package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import com.aimprosoft.camed.compiler.extensions.AllowedExtensions;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.xpath.Xpath;
import com.aimprosoft.camed.compiler.util.DocumentFactory;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class ModelFactory {

    private DateFormat XMLFormat = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss");

    public ModelFactory() {
    }

    public void createModel(CAMTemplate template, Document doc) throws Exception {
        DocumentFactory df = new DocumentFactory(template);
        df.handleStructureIncludes(doc.getRootElement(), true);
        setUpCAMAttributes(doc, template);
        setUpCamTemplateHeader(doc, template);
        setUpCamTemplateStruture(doc, template);
        setUpCamTemplateRules(doc, template);
        //template.setUpCrossReference();
        setUpCamEditorExtensions(doc);
    }


    @SuppressWarnings("unchecked")
    private void setUpCamEditorExtensions(Document doc) throws Exception {
        Xpath xpath = new Xpath();
        xpath.setUpXPath(doc, "//as:Extension");
        List<Element> extensions = xpath.getXPath().selectNodes(doc);
        for (Element extension : extensions) {
            Attribute name = extension.getAttribute("name");
            if (name != null) {
                AllowedExtensions.allocateExtension(name.getValue(), extension);
            }
        }
    }

    private void setUpCAMAttributes(Document doc, CAMTemplate template) throws Exception {
        template.setCAMLevel(doc.getRootElement().getAttribute("CAMlevel").getIntValue());
        template.setVersion(doc.getRootElement().getAttributeValue("version"));

    }

    private void setUpCamTemplateHeader(Document doc, CAMTemplate template) throws Exception {
        Xpath xpath = new Xpath();
        xpath.setUpXPath(doc, "//as:DateTime");

        Element element = (Element) xpath.getXPath().selectSingleNode(doc);
        Date temp = convertXMLDate(element.getTextNormalize());
        if (temp != null) {
            template.setDateTime(temp);
        } else {
            throw new JDOMException("DateTime must be a full XML Date");
        }

        //setUpDescription
        xpath.setUpXPath(doc, "//as:Description");
        element = (Element) xpath.getXPath().selectSingleNode(doc);
        if (element != null)
            template.setDescription(element.getText());

        //setUpOwner
        xpath.setUpXPath(doc, "//as:Owner");
        element = (Element) xpath.getXPath().selectSingleNode(doc);
        if (element != null)
            template.setOwner(element.getText());

        //setUpVersion
        xpath.setUpXPath(doc, "//as:Version");
        element = (Element) xpath.getXPath().selectSingleNode(doc);
        if (element != null)
            template.setTemplateVersion(element.getText());

        //setUpParameters
        xpath.setUpXPath(doc, "//as:Parameters");
        Element params = null;
        params = (Element) xpath.getXPath().selectSingleNode(doc);
        if (params != null) {
            setUpParameters(params, template);
        }
        //setUpProperties
        xpath.setUpXPath(doc, "//as:Properties");
        Element properties = null;
        properties = (Element) xpath.getXPath().selectSingleNode(doc);
        if (properties != null) {
            setUpProperties(properties, template);
        }
        //setUpImports
        xpath.setUpXPath(doc, "//as:Imports");
        Element imports = null;
        imports = (Element) xpath.getXPath().selectSingleNode(doc);
        if (imports != null) {
            setUpImports(imports, template);
        }

    }

    @SuppressWarnings("unchecked")
    private void setUpCamTemplateStruture(Document doc, CAMTemplate template) throws Exception {
        Xpath xpath = new Xpath();
        xpath.setUpXPath(doc, "//as:AssemblyStructure/as:Structure");
        List<Element> structures = xpath.getXPath().selectNodes(doc);
        for (Element structure : structures) {
            AddStructureToTemplate(structure, template);
        }

    }

    public static final String DATE_FORMAT_NOW = "yyyy-MM-dd HH:mm:ss.SSS";


    private void AddStructureToTemplate(Element structure, CAMTemplate template) throws JDOMException {
        String taxonomy = structure.getAttributeValue("taxonomy");
        String taxonomyOther = "";
        if (taxonomy.equals(TaxonomyType.OTHER.toString())) {
            taxonomyOther = structure.getAttributeValue("taxonomyOther");
            if (taxonomyOther.equals("")) {
                throw new JDOMException("taxonomyOther should be populated if taxonomy = OTHER");
            }
        }
        String ID = structure.getAttributeValue("ID");
        if (ID == null || ID.equals("")) {
            ID = "default";
        }
        String reference = structure.getAttributeValue("reference");
        if (reference == null)
            reference = "";
        if (structure.getChildren().size() > 1) {
            throw new JDOMException("Structure should only have one root node");
        }
        Structure struct = new Structure(structure, TaxonomyType.valueOf(taxonomy), taxonomyOther);
        struct.setID(ID);
        struct.setReference(reference);
        struct.setTemplate(template);

        template.putStructure(ID, struct);


    }

    @SuppressWarnings("unchecked")
    private Integer setUpParameters(Element params, CAMTemplate template) throws Exception {
        Integer count = 0;
        Xpath xpath = new Xpath();
        xpath.setUpXPath(params, "//as:Parameter");
        List<Element> parameters = xpath.getXPath().selectNodes(params);
        for (Element param : parameters) {
            count++;
            String name = param.getAttributeValue("name");
            Parameter parameter = new Parameter(name);
            List<Attribute> attributes = param.getAttributes();
            for (Attribute attr : attributes) {
                if (attr.getName().equals("name")) {
                    continue;
                } else if (attr.getName().equals("values")) {
                    List<String> values = new ArrayList<String>();
                    StringTokenizer t = new StringTokenizer(attr.getValue(), "|'");
                    for (int k = 0; t.hasMoreTokens(); k++) {
                        String token = t.nextToken();
                        if (token.trim().length() > 0) {
                            values.add(token.trim());
                        }
                    }
                    parameter.setValues(values);
                } else if (attr.getName().equals("default")) {
                    if (!attr.getValue().endsWith(" not allowed")) {
                        parameter.setDefaultValue(attr.getValue());
                    }
                } else if (attr.getName().equals("datatype")) {
                    parameter.setDatatype(attr.getValue());
                } else if (attr.getName().equals("xpath")) {
                    if (!attr.getValue().equals("xpath must exist")) {
                        parameter.setXpath(attr.getValue());
                    }
                } else if (attr.getName().equals("use")) {
                    parameter.setUse(attr.getValue());
                }
            }
            template.putParameter(name, parameter);
        }
        return count;
    }

    @SuppressWarnings("unchecked")
    private int setUpProperties(Element properties, CAMTemplate template) throws Exception {
        Integer count = 0;
        Xpath xpath = new Xpath();
        xpath.setUpXPath(properties, "//as:property");
        List<Element> props = xpath.getXPath().selectNodes(properties);
        for (Element prop : props) {
            count++;
            String name = prop.getAttributeValue("name");
            String value = prop.getAttributeValue("value");
            template.putProperty(name, value);
        }
        return count;
    }

    @SuppressWarnings("unchecked")
    private int setUpImports(Element imports, CAMTemplate template) throws Exception {
        Integer count = 0;
        Xpath xpath = new Xpath();
        xpath.setUpXPath(imports, "//as:import");
        List<Element> props = xpath.getXPath().selectNodes(imports);
        for (Element prop : props) {
            count++;
            String URI = prop.getAttributeValue("URI");
            String alias = prop.getAttributeValue("alias");
            Import imp = new Import();
            imp.setURI(URI);
            imp.setAlias(alias);
            template.putImport(alias, imp);
        }
        return count;
    }

    @SuppressWarnings("unchecked")
    private void setUpCamTemplateRules(Document doc, CAMTemplate template) throws Exception {
        Map<UUID, Rule> ruleMap = new HashMap<UUID, Rule>();
        Xpath xpath = new Xpath();
        xpath.setUpXPath(doc, "//as:BusinessUseContext/as:Rules/as:default");
        Element rules = (Element) xpath.getXPath().selectSingleNode(doc);
        Constraint consRule;
        List<Element> childrenRules = rules.getChildren();
        for (Element childRule : childrenRules) {
            if (childRule.getName().equals("constraint")) {
                Constraint cons = new Constraint(childRule, RuleCategory.DEFAULT);
                cons.setTemplate(template);
                ruleMap.put(cons.getUuid(), cons);
                for (Element constRule : (List<Element>) childRule.getChildren()) {
                    consRule = new Constraint(constRule, RuleCategory.DEFAULT);
                    consRule.setParentUUID(cons.getUuid());
                    consRule.setTemplate(template);
                    ruleMap.put(consRule.getUuid(), consRule);
                    consRule = null;
                }
                cons = null;
            } else if (childRule.getName().equals("context")) {
                Context context = new Context(childRule, RuleCategory.DEFAULT);
                context.setTemplate(template);
                ruleMap.put(context.getUuid(), context);
                for (Element constRule : (List<Element>) childRule.getChildren()) {
                    consRule = new Constraint(constRule, RuleCategory.DEFAULT);
                    consRule.setParentUUID(context.getUuid());
                    ruleMap.put(consRule.getUuid(), consRule);
                    consRule = null;
                }
                context = null;
            }
        }
        xpath.setUpXPath(doc, "//as:BusinessUseContext/as:Rules/as:context");
        List<Element> contextRules = xpath.getXPath().selectNodes(doc);
        for (Element childRule : contextRules) {
            if (childRule.getName().equals("constraint")) {
                Constraint cons = new Constraint(childRule, RuleCategory.CONDITIONAL);
                ruleMap.put(cons.getUuid(), cons);
                for (Element constRule : (List<Element>) childRule.getChildren()) {
                    consRule = new Constraint(constRule, RuleCategory.CONDITIONAL);
                    consRule.setParentUUID(cons.getUuid());
                    ruleMap.put(consRule.getUuid(), consRule);
                    consRule = null;
                }
                cons = null;
            } else if (childRule.getName().equals("context")) {
                Context context = new Context(childRule, RuleCategory.CONDITIONAL);
                context.setTemplate(template);
                ruleMap.put(context.getUuid(), context);
                for (Element constRule : (List<Element>) childRule.getChildren()) {
                    consRule = new Constraint(constRule, RuleCategory.CONDITIONAL);
                    consRule.setParentUUID(context.getUuid());
                    ruleMap.put(consRule.getUuid(), consRule);
                    consRule = null;
                }
                context = null;
            }
        }
        template.getRuleManager().getRuleMap().putAll(ruleMap);
        template.getRuleManager().setUpXpathRulesMap();

    }


    private Date convertXMLDate(String date) {
        if (date == null)
            return null;
        try {
            return XMLFormat.parse(date);
        } catch (ParseException e1) {
            return null;
        }
    }

}
