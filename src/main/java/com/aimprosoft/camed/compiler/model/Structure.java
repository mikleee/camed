package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.extensions.StructureAnnotations;
import com.aimprosoft.camed.compiler.util.*;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.aimprosoft.camed.compiler.extensions.AllowedExtensions;
import com.aimprosoft.camed.compiler.extensions.StructureAnnotation;
import com.aimprosoft.camed.compiler.model.Action.ActionType;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.Writer;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static com.aimprosoft.camed.compiler.util.CommonUtils.isNotEmpty;


public class Structure implements Compilable {

    @Override
    public String compile() {
        boolean full = false;

//        if (elem.getQualifiedName().endsWith("as:Structure") && applyTemplate == null) {
//            out.write("<" + "as:Structure" + " ");
//            String ID = elem.getAttributeValue("ID");
//            if (ID != null) {
//                out.write(" " + "ID" + "=\"" + StringEscapeUtils.escapeXml(ID) + "\" ");
//            }
//            String ref = elem.getAttributeValue("reference");
//            if (ref != null) {
//                out.write(" " + "reference" + "=\""
//                        + StringEscapeUtils.escapeXml(ref) + "\" ");
//            }
//            String tax = elem.getAttributeValue("taxonomy");
//            if (tax != null) {
//                out.write(" " + "taxonomy" + "=\""
//                        + StringEscapeUtils.escapeXml(tax) + "\" ");
//            }
//            out.write(">\n");
//            if (template != null && template.getParameters().size() > 0) {
//                out.write("<" + "as:parameters" + ">\n");
//                for (Parameter param : template.getParameters()) {
//                    param.toCXF(out);
//                }
//                out.write("</" + "as:parameters" + ">\n");
//            }
//            List<Element> children = elem.getChildren();
//            for (Element child : children) {
//                toCXF(out, child, null, full);
//            }
//            out.write("</" + "as:Structure" + ">");
//        } else if (elem.getQualifiedName().endsWith("as:Structure") && applyTemplate != null) {
//            List<Element> children = elem.getChildren();
//            for (Element child : children) {
//                toCXF(out, child, applyTemplate, full);
//            }
//        } else {
//            Boolean ignoreChildren = false;
//            // String itemQualifiedName =
//            // XPathFunctions.fullXpathWithPosition(elem);
//            out.write("<" + "as:Element" + " ");
//            out.write(" " + "name" + "=\""
//                    + StringEscapeUtils.escapeXml(elem.getQualifiedName())
//                    + "\" ");
//            // if (elem.getNamespace() != null)
//            // out.write(" "+"namespace"+"=\""+StringEscapeUtils.escapeXml(elem.getNamespaceURI())+"\" ");
//            if (full) {
//                out.write(" "
//                        + "path"
//                        + "=\""
//                        + StringEscapeUtils.escapeXml(XPathFunctions
//                        .xpath(elem)) + "\" ");
//                if (elem.getNamespace() != null)
//                    out.write(" "
//                            + "namespace"
//                            + "=\""
//                            + StringEscapeUtils.escapeXml(elem
//                            .getNamespaceURI()) + "\" ");
//                if (elem.getNamespacePrefix() != null)
//                    out.write(" "
//                            + "namespacePrefix"
//                            + "=\""
//                            + StringEscapeUtils.escapeXml(elem
//                            .getNamespacePrefix()) + "\" ");
//                if (IncludeHandlers.isIncluded(elem, template)) {
//                    out.write(" " + "included" + "=\""
//                            + StringEscapeUtils.escapeXml("true") + "\" ");
//                    if (IncludeHandlers.includedRootElement(elem, template)) {
//                        out.write(" "
//                                + "includedFile"
//                                + "=\""
//                                + StringEscapeUtils.escapeXml(IncludeHandlers
//                                .getInclude(elem, template).getUri()) + "\" ");
//                    }
//                }
//                if (elem.getChildren().size() == 0) {
//                    out.write(" " + "exampleValue" + "=\""
//                            + StringEscapeUtils.escapeXml(elem.getText())
//                            + "\" ");
//                }
//            } else {
//                if (elem.getChildren().size() == 0) {
//                    if (!(elem.getTextTrim().startsWith("%") && elem
//                            .getTextTrim().endsWith("%"))) {
//                        out.write(" " + "setValue" + "=\""
//                                + StringEscapeUtils.escapeXml(elem.getText())
//                                + "\" ");
//                    }
//                }
//            }
//
//            if (applyTemplate != null) {
//                if (full)
//                    out.write(" " + "applyTemplate" + "=\""
//                            + StringEscapeUtils.escapeXml(applyTemplate)
//                            + "\" ");
//            }
//            if (full)
//                out.write(">\n");
//            boolean finish = true;
//            List<Rule> nodeRules = template.getRuleManager().getNodeRules(elem);
//            if (nodeRules != null && nodeRules.size() > 0) {
//                if (full)
//                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "Rule" + ">\n");
//                boolean unconditional = false;
//                int count = 0;
//                boolean duplicates = checkDuplicates();
//                for (Rule rule : nodeRules) {
//                    if (rule instanceof Constraint) {
//                        count++;
//                        Constraint cons = (Constraint) rule;
//                        if (duplicates) {
//                            cons.toCXF(out, full, count);
//                        } else {
//                            cons.toCXF(out, full, -1);
//                        }
//                        if (cons.getCondition() == null
//                                || cons.getCondition().length() == 0) {
//                            unconditional = true;
//                        }
//                        if (cons.getFirstActionString().startsWith(ActionType.applyTemplate.toString())) {
//                            if (full) {
//                                // out.write(">\n");
//                                if (applyTemplate != null
//                                        && !applyTemplate.equals(cons
//                                        .getFirstAction()
//                                        .getActionParameters().get(0)))
//                                    applyTemplateCXF(out, full, cons);
//                                finish = false;
//                                cons.toCXF(out, full, count);
//                            } else {
//                                outputCompiledTemplate(cons);
//                            }
//                            ignoreChildren = true;
//                        }
//                    }
//                }
//                if (full && unconditional == false && count == 0) {
//                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "constraint" + " ");
//                    out.write(" " + "action" + "=\""
//                            + StringEscapeUtils.escapeXml("makeMandatory()")
//                            + "\" ");
//                    out.write("/>\n");
//                } else if (unconditional == false && count == 0) {
//                    out.write(" " + "makeMandatory" + "=\"true\" ");
//                }
//                if (full)
//                    out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "Rule" + ">");
//
//            } else {
//                if (full) {
//                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "Rule" + ">\n");
//                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "constraint" + " ");
//                    out.write(" " + "action" + "=\""
//                            + StringEscapeUtils.escapeXml("makeMandatory()")
//                            + "\" ");
//                    out.write("/>\n");
//                    out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                            + "Rule" + ">\n");
//                } else {
//                    out.write(" " + "makeMandatory" + "=\"true\" ");
//                }
//
//            }
//            if (full) {
//                StructureAnnotations sa = (StructureAnnotations) AllowedExtensions
//                        .getExtension(StructureAnnotations.name);
//                if (sa != null) {
//                    String xpath = XPathFunctions.xpathParentAndAll(elem);
//                    StructureAnnotation anno = sa.get(xpath);
//                    if (anno != null) {
//                        anno.toCXF(out);
//                    }
//                }
//            }
//            if (!full && finish)
//                out.write(">\n");
//
//            if (ignoreChildren) {
//                ignoreChildren = false;
//            } else {
//                List<Attribute> attributes = elem.getAttributes();
//                for (Attribute attr : attributes) {
//                    toCXF(out, attr, full);
//                }
//                List<Element> children = elem.getChildren();
//                for (Element child : children) {
//                    toCXF(out, child, null, full);
//                }
//            }
//            out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                    + "Element" + ">\n");
//        }

        return null;
    }

    //Logger logger = LoggerFactory.getLogger(this.getClass());


    private String ID = "";
    private String reference = "";
    private String taxonomy = TaxonomyType.XML.toString();
    private String taxonomyOther = "";
    private Element structure;
    private CAMTemplate template;

    public Structure() {
    }

    public Structure(Element structure, TaxonomyType taxonomy, String taxonomyOther) {
        setStructure(structure);
//        setTaxonomy(taxonomy);
        if (taxonomy.equals(TaxonomyType.OTHER.toString()))
            setTaxonomyOther(taxonomyOther);
        reference = "";
        ID = "";
    }

    public String getID() {
        return ID;
    }

    public void setID(String id) {
        ID = id;
//        structure.setAttribute("ID", id);
    }

    public String getReference() {
        if (reference != null)
            return reference;
        else
            return "";
    }

    public void setReference(String reference) {
        this.reference = reference;
//        structure.setAttribute("reference", reference);
    }

    public Element getStructure() {
        return structure;
    }

    public void setStructure(Element structure) {
        this.structure = structure;
    }

    public void setTemplate(CAMTemplate template) {
        this.template = template;
    }

    public String getTaxonomy() {
        return taxonomy;
    }

    public void setTaxonomy(String taxonomy) {
        this.taxonomy = taxonomy;
//        structure.setAttribute("taxonomy", taxonomy);
    }

    public String getTaxonomyOther() {
        return taxonomyOther;
    }

    public void setTaxonomyOther(String taxonomyOther) {
        this.taxonomyOther = taxonomyOther;
//        structure.setAttribute("taxonomyOther", taxonomyOther);
    }


    public Element toXML() {
        if (getID().length() > 0) {
            structure.setAttribute("ID", getID());
        } else {
            structure.setAttribute("ID", "NewStructure");
        }
        if (isNotEmpty(reference)) {
            structure.setAttribute("reference", reference);
        }
        if (taxonomy != null) {
            structure.setAttribute("taxonomy", taxonomy);
            if (taxonomy.equals(TaxonomyType.OTHER.toString())) {
                structure.setAttribute("taxonomyOther", getTaxonomyOther());
            }
        }
        return structure;
    }


    @SuppressWarnings("unchecked")
    public Element toDoc(Element elem) throws Exception {
        Element output = null;
        if (elem.getQualifiedName().endsWith("as:Structure")) {
            output = new Element("Structure", CAMConstants.CAMNamespace);
            String ID = elem.getAttributeValue("ID");
            if (ID != null)
                output.setAttribute("ID", ID);
            String ref = elem.getAttributeValue("reference");
            if (ref != null)
                output.setAttribute("reference", ref);
            String tax = elem.getAttributeValue("taxonomy");
            if (tax != null)
                output.setAttribute("taxonomy", tax);
            if (template != null && template.getParameters().size() > 0) {
                Element paramsElem = new Element("parameters", CAMConstants.CAMNamespace);
                for (Parameter param : template.getParameters()) {
                    paramsElem.addContent(param.toXML());
                }
                output.addContent(paramsElem);
            } else if (template == null) {
                //logger.info("template is null");
            }
            List<Element> children = elem.getChildren();
            for (Element child : children) {
                Element temp = toDoc(child);
                if (temp != null)
                    output.addContent(temp);
            }
        } else {
            Boolean ignoreChildren = false;
            output = new Element("Element", CAMConstants.CAMNamespace);
            output.setAttribute("name", elem.getQualifiedName());
            output.setAttribute("path", XPathFunctions.xpath(elem));
            if (elem.getNamespace() != null)
                output.setAttribute("namespace", elem.getNamespaceURI());
            if (elem.getNamespacePrefix() != null)
                output.setAttribute("namespacePrefix", elem.getNamespacePrefix());
            if (IncludeHandlers.isIncluded(elem, template)) {
                output.setAttribute("included", "true");
                if (IncludeHandlers.includedRootElement(elem, template)) {
                    output.setAttribute("includedFile", IncludeHandlers.getInclude(elem, template).getUri());
                }
            }
            if (elem.getChildren().size() == 0) {
                output.setAttribute("exampleValue", elem.getText());
            }
            StructureAnnotations sa = (StructureAnnotations) AllowedExtensions.getExtension(StructureAnnotations.name);
            if (sa != null) {
                String xpath = XPathFunctions.xpathParentAndAll(elem);
                StructureAnnotation anno = sa.get(xpath);
                if (anno != null) {
                    Element annotation = anno.toXML();
                    if (annotation != null) {
                        output.addContent(annotation);
                    }
                }
            }
            List<Rule> nodeRules = template.getRuleManager().getNodeRules(elem);
            if (nodeRules != null && nodeRules.size() > 0) {
                Element ruleE = new Element("Rule", CAMConstants.CAMNamespace);
                boolean unconditional = false;
                for (Rule rule : nodeRules) {
                    if (rule instanceof Constraint) {
                        Constraint cons = (Constraint) rule;
                        Element consE = cons.toDoc();
                        if (consE != null) {
                            ruleE.addContent(consE);
                        }
                        if (cons.getCondition() == null
                                || cons.getCondition().length() == 0) {
                            unconditional = true;
                        }
                        if (cons.getFirstActionString().startsWith(
                                ActionType.applyTemplate.toString())) {

                            List<String> params = cons.getFirstAction()
                                    .getActionParameters();

                            DocumentFactory df = new DocumentFactory();
                            Document doc = df.createDocument(params.get(0));
                            CAMTemplate template = new CAMTemplate(doc);
                            ModelFactory mf = new ModelFactory();
                            mf.createModel(template, doc);
                            // template.setUpCrossReference();
                            Structure tempStruct = template.getFirstStructure();
                            // Element tempFirstRealElement = (Element)
                            // tempStruct.getStructure().getChildren().get(0);
                            Element tempElement = tempStruct.toDoc(tempStruct
                                    .getStructure());
                            if (tempElement != null) {
                                for (Element child : (List<Element>) tempElement
                                        .getChildren()) {
                                    if (!child.getName().equals("Element")) {
                                        output.addContent((Element) child
                                                .clone());
                                        if (child.getName()
                                                .equals("parameters")) {
                                            if (params.size() > 1) {
                                                output.addContent(parametersToDoc(params
                                                        .get(1)));
                                            }
                                        }
                                    } else {
                                        for (Element grandChild : (List<Element>) child
                                                .getChildren()) {
                                            output.addContent((Element) grandChild
                                                    .clone());
                                        }
                                    }
                                }
                                if (params.size() == 1) {
                                    output.setAttribute("applyTemplate",
                                            params.get(0));
                                } else {
                                    output.setAttribute("applyTemplate",
                                            params.get(0) + "," + params.get(1));
                                }

                                output.setAttribute("included", "true");
                                // ruleE.removeContent();
                            }
                            ignoreChildren = true;
                        }
                    }
                }
                if (!unconditional && ruleE.getChildren().size() > 0) {
                    Element consE = new Element("constraint", CAMConstants.CAMNamespace);
                    consE.setAttribute("action", "makeMandatory()");
                    ruleE.addContent(consE);
                }
                if (ruleE.getChildren().size() > 0)
                    output.addContent(ruleE);

            } else {
                Element ruleE = new Element("Rule", CAMConstants.CAMNamespace);
                Element consE = new Element("constraint", CAMConstants.CAMNamespace);
                consE.setAttribute("action", "makeMandatory()");
                ruleE.addContent(consE);
                output.addContent(ruleE);
            }

            List<Attribute> attributes = elem.getAttributes();
            for (Attribute attr : attributes) {
                Element temp = toDoc(attr);
                if (temp != null)
                    output.addContent(temp);
            }
            if (ignoreChildren) {
                ignoreChildren = false;
            } else {
                List<Element> children = elem.getChildren();
                for (Element child : children) {
                    Element temp = toDoc(child);
                    if (temp != null)
                        output.addContent(temp);
                }
            }
        }
        return output;
    }

    private Element parametersToDoc(String params) {
        String[] parameters = params.split(";");
        Element parent = new Element("parameterValues", CAMConstants.CAMNamespace);
        for (String param : parameters) {
            Element child = new Element("Parameter", CAMConstants.CAMNamespace);
            child.setAttribute("name", param.substring(0, param.indexOf("=")));
            child.setAttribute("value", param.substring(param.indexOf("=") + 1));
            parent.addContent(child);
        }

        return parent;
    }


    public Element toDoc(Attribute attr) throws Exception {
        Element output = new Element("Attribute", CAMConstants.CAMNamespace);
        output.setAttribute("name", attr.getQualifiedName());
        output.setAttribute("path", XPathFunctions.xpath(attr));
        if (attr.getNamespace() != null)
            output.setAttribute("namespace", attr.getNamespaceURI());
        if (attr.getNamespacePrefix() != null)
            output.setAttribute("namespacePrefix", attr.getNamespacePrefix());
        output.setAttribute("exampleValue", attr.getValue());
        if (IncludeHandlers.isIncluded(attr, template)) {
            output.setAttribute("included", "true");
        }
        List<Rule> nodeRules = template.getRuleManager().getNodeRules(attr);
        if (nodeRules != null && nodeRules.size() > 0) {
            Element ruleE = new Element("Rule", CAMConstants.CAMNamespace);
            for (Rule rule : nodeRules) {
                if (rule instanceof Constraint) {
                    Constraint cons = (Constraint) rule;
                    Element consE = cons.toDoc();
                    if (consE != null) {
                        ruleE.addContent(consE);
                    }
                }
            }
            if (ruleE != null && ruleE.getChildren().size() > 0)
                output.addContent(ruleE);
        } else {
            Element ruleE = new Element("Rule", CAMConstants.CAMNamespace);
            Element consE = new Element("constraint", CAMConstants.CAMNamespace);
            consE.setAttribute("action", "makeMandatory()");
            ruleE.addContent(consE);
            output.addContent(ruleE);
        }
        StructureAnnotations sa = (StructureAnnotations) AllowedExtensions.getExtension(StructureAnnotations.name);
        if (sa != null) {
            String xpath = XPathFunctions.xpathParentAndAll(attr);
            StructureAnnotation anno = sa.get(xpath);
            if (anno != null) {
                Element annotation = anno.toXML();
                if (annotation != null) {
                    output.addContent(annotation);
                }
            }
        }
        return output;
    }

    public List<String> getStructureXPaths() {
        return getStructureXPaths((Element) structure.getChildren().get(0));
    }

    @SuppressWarnings("unchecked")
    private List<String> getStructureXPaths(Element element) {
        List<String> xpaths = new ArrayList<String>();
        xpaths.add(XPathFunctions.xpathParentAndAll(element));
        if (element.getAttributes().size() > 0) {
            List<Attribute> attrs = element.getAttributes();
            for (Attribute attribute : attrs) {
                xpaths.add(XPathFunctions.xpathParentAndAll(attribute));
            }
        }
        if (element.getChildren().size() > 0) {
            List<Element> children = element.getChildren();
            for (Element child : children) {
                xpaths.addAll(getStructureXPaths(child));
            }
        }
        return xpaths;
    }

    public Map<String, Object> getStructureXPathsMap() {
        Map<String, Object> map = new HashMap<String, Object>();
        String path = XPathFunctions.xpathParentAndAll((Element) structure.getChildren().get(0));
        map.put(path, (Element) structure.getChildren().get(0));
        getStructureXPaths(map, (Element) structure.getChildren().get(0));
        return map;
    }

    @SuppressWarnings("unchecked")
    private void getStructureXPaths(Map<String, Object> map, Element element) {


        if (!element.getAttributes().isEmpty()) {
            List<Attribute> attrs = element.getAttributes();
            for (Attribute attribute : attrs) {
                map.put(XPathFunctions.xpathParentAndAll(attribute), attribute);
            }
        }

        if (!element.getChildren().isEmpty()) {
            List<Element> children = element.getChildren();
            for (Element child : children) {
                String path = XPathFunctions.xpathParentAndAll(child);
                map.put(path, child);
                getStructureXPaths(map, child);
            }
        }
    }

    @SuppressWarnings({"unchecked"})
    public void toCXF(Writer out, Element elem, String applyTemplate, boolean full) throws Exception {

        if (elem.getQualifiedName().endsWith("as:Structure") && applyTemplate == null) {
            out.write("<" + "as:Structure" + " ");
            String ID = elem.getAttributeValue("ID");
            if (ID != null) {
                out.write(" " + "ID" + "=\"" + StringEscapeUtils.escapeXml(ID) + "\" ");
            }
            String ref = elem.getAttributeValue("reference");
            if (ref != null) {
                out.write(" " + "reference" + "=\""
                        + StringEscapeUtils.escapeXml(ref) + "\" ");
            }
            String tax = elem.getAttributeValue("taxonomy");
            if (tax != null) {
                out.write(" " + "taxonomy" + "=\""
                        + StringEscapeUtils.escapeXml(tax) + "\" ");
            }
            out.write(">\n");
            if (template != null && template.getParameters().size() > 0) {
                out.write("<" + "as:parameters" + ">\n");
                for (Parameter param : template.getParameters()) {
                    param.toCXF(out);
                }
                out.write("</" + "as:parameters" + ">\n");
            }
            List<Element> children = elem.getChildren();
            for (Element child : children) {
                toCXF(out, child, null, full);
            }
            out.write("</" + "as:Structure" + ">");
        } else if (elem.getQualifiedName().endsWith("as:Structure") && applyTemplate != null) {
            List<Element> children = elem.getChildren();
            for (Element child : children) {
                toCXF(out, child, applyTemplate, full);
            }
        } else {
            Boolean ignoreChildren = false;
            // String itemQualifiedName =
            // XPathFunctions.fullXpathWithPosition(elem);
            out.write("<" + "as:Element" + " ");
            out.write(" " + "name" + "=\""
                    + StringEscapeUtils.escapeXml(elem.getQualifiedName())
                    + "\" ");
            // if (elem.getNamespace() != null)
            // out.write(" "+"namespace"+"=\""+StringEscapeUtils.escapeXml(elem.getNamespaceURI())+"\" ");
            if (full) {
                out.write(" "
                        + "path"
                        + "=\""
                        + StringEscapeUtils.escapeXml(XPathFunctions
                        .xpath(elem)) + "\" ");
                if (elem.getNamespace() != null)
                    out.write(" "
                            + "namespace"
                            + "=\""
                            + StringEscapeUtils.escapeXml(elem
                            .getNamespaceURI()) + "\" ");
                if (elem.getNamespacePrefix() != null)
                    out.write(" "
                            + "namespacePrefix"
                            + "=\""
                            + StringEscapeUtils.escapeXml(elem
                            .getNamespacePrefix()) + "\" ");
                if (IncludeHandlers.isIncluded(elem, template)) {
                    out.write(" " + "included" + "=\""
                            + StringEscapeUtils.escapeXml("true") + "\" ");
                    if (IncludeHandlers.includedRootElement(elem, template)) {
                        out.write(" "
                                + "includedFile"
                                + "=\""
                                + StringEscapeUtils.escapeXml(IncludeHandlers
                                .getInclude(elem, template).getUri()) + "\" ");
                    }
                }
                if (elem.getChildren().size() == 0) {
                    out.write(" " + "exampleValue" + "=\""
                            + StringEscapeUtils.escapeXml(elem.getText())
                            + "\" ");
                }
            } else {
                if (elem.getChildren().size() == 0) {
                    if (!(elem.getTextTrim().startsWith("%") && elem
                            .getTextTrim().endsWith("%"))) {
                        out.write(" " + "setValue" + "=\""
                                + StringEscapeUtils.escapeXml(elem.getText())
                                + "\" ");
                    }
                }
            }

            if (applyTemplate != null) {
                if (full)
                    out.write(" " + "applyTemplate" + "=\""
                            + StringEscapeUtils.escapeXml(applyTemplate)
                            + "\" ");
            }
            if (full)
                out.write(">\n");
            boolean finish = true;
            List<Rule> nodeRules = template.getRuleManager().getNodeRules(elem);
            if (nodeRules != null && nodeRules.size() > 0) {
                if (full)
                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "Rule" + ">\n");
                boolean unconditional = false;
                int count = 0;
                boolean duplicates = checkDuplicates();
                for (Rule rule : nodeRules) {
                    if (rule instanceof Constraint) {
                        count++;
                        Constraint cons = (Constraint) rule;
                        if (duplicates) {
                            cons.toCXF(out, full, count);
                        } else {
                            cons.toCXF(out, full, -1);
                        }
                        if (cons.getCondition() == null
                                || cons.getCondition().length() == 0) {
                            unconditional = true;
                        }
                        if (cons.getFirstActionString().startsWith(ActionType.applyTemplate.toString())) {
                            if (full) {
                                // out.write(">\n");
                                if (applyTemplate != null
                                        && !applyTemplate.equals(cons
                                        .getFirstAction()
                                        .getActionParameters().get(0)))
                                    applyTemplateCXF(out, full, cons);
                                finish = false;
                                cons.toCXF(out, full, count);
                            } else {
                                outputCompiledTemplate(cons);
                            }
                            ignoreChildren = true;
                        }
                    }
                }
                if (full && unconditional == false && count == 0) {
                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "constraint" + " ");
                    out.write(" " + "action" + "=\""
                            + StringEscapeUtils.escapeXml("makeMandatory()")
                            + "\" ");
                    out.write("/>\n");
                } else if (unconditional == false && count == 0) {
                    out.write(" " + "makeMandatory" + "=\"true\" ");
                }
                if (full)
                    out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "Rule" + ">");

            } else {
                if (full) {
                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "Rule" + ">\n");
                    out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "constraint" + " ");
                    out.write(" " + "action" + "=\""
                            + StringEscapeUtils.escapeXml("makeMandatory()")
                            + "\" ");
                    out.write("/>\n");
                    out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                            + "Rule" + ">\n");
                } else {
                    out.write(" " + "makeMandatory" + "=\"true\" ");
                }

            }
            if (full) {
                StructureAnnotations sa = (StructureAnnotations) AllowedExtensions
                        .getExtension(StructureAnnotations.name);
                if (sa != null) {
                    String xpath = XPathFunctions.xpathParentAndAll(elem);
                    StructureAnnotation anno = sa.get(xpath);
                    if (anno != null) {
                        anno.toCXF(out);
                    }
                }
            }
            if (!full && finish)
                out.write(">\n");

            if (ignoreChildren) {
                ignoreChildren = false;
            } else {
                List<Attribute> attributes = elem.getAttributes();
                for (Attribute attr : attributes) {
                    toCXF(out, attr, full);
                }
                List<Element> children = elem.getChildren();
                for (Element child : children) {
                    toCXF(out, child, null, full);
                }
            }
            out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                    + "Element" + ">\n");
        }
    }

    private String outputCompiledTemplate(Constraint cons) throws Exception {
        List<String> params = cons.getFirstAction().getActionParameters();
        String filename = null;
        if (params != null && params.get(0) != null) {
            if (params.get(0).contains(","))
                filename = params.get(0).substring(0, params.get(0).indexOf(","));
            else
                filename = params.get(0);
        }
        File file = new File(filename);
        if (!file.exists()) {
            String path = template.getCompilePath();
            String tempfilename = path + "/" + filename;
            file = new File(tempfilename);
            if (!file.exists()) {
                throw new FileNotFoundException("file " + filename + " not found.");
            } else {
                filename = tempfilename;
            }
        }
        String outputFilename = template.getCompilePath() + file.getName().replace(".cam", ".cxx");
        Document doc = null;
        try {
            URL url = new URL(filename);
            doc = new DocumentFactory().createDocument(url);
        } catch (MalformedURLException e) {
            doc = new DocumentFactory().createDocument(filename);
        }
        if (filename.endsWith(".cxf")) {
            doc = CAMEditorUtils.translateCXFFile(filename);
        }
        CAMTemplate tempTemplate = new CAMTemplate(doc);
        ModelFactory mf = new ModelFactory();
        mf.createModel(tempTemplate, doc);

        DocumentWriter.writePretty(outputFilename, tempTemplate.toDoc(false), template);
        return outputFilename;
    }

    private boolean checkDuplicates() {
        Map<ActionType, Integer> map = new HashMap<ActionType, Integer>();
        for (Rule rule : template.getRuleManager().getRuleMap().values()) {
            if (rule instanceof Constraint) {
                ActionType a = ((Constraint) rule).getFirstAction().getAction();
                Integer i = map.get(a);
                if (i != null) {
                    return true;
                } else {
                    map.put(a, 1);
                }
            }
        }
        return false;
    }

    /**
     * @param out
     * @param full
     * @param cons
     * @return
     * @throws java.io.IOException
     */
    private void applyTemplateCXF(Writer out, boolean full, Constraint cons) throws Exception {
        List<String> params = cons.getFirstAction().getActionParameters();

        DocumentFactory df = new DocumentFactory();

        Document doc = df.createDocument(params.get(0));
        CAMTemplate template = new CAMTemplate(doc);
        ModelFactory mf = new ModelFactory();
        mf.createModel(template, doc);
        //template.setUpCrossReference();
        Structure tempStruct = template.getFirstStructure();
        String applytemplate = "";
        if (params.size() == 1) {
            applytemplate = "applyTemplate" + params.get(0);
        } else {
            applytemplate = "applyTemplate" + params.get(0) + "+" + params.get(1);
        }
        if (template.getParameters().size() > 0) {
            out.write("<" + "as:parameters" + ">\n");
            for (Parameter param : template.getParameters()) {
                param.toCXF(out);
            }
            out.write("</" + "as:parameters" + ">\n");
        }
        //Element tempFirstRealElement = (Element) tempStruct.getStructure().getChildren().get(0);
        tempStruct.toCXF(out, tempStruct.getStructure(), applytemplate, full);

    }


    private void toCXF(Writer out, Attribute attr, boolean full)
            throws Exception {

        out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":" + "Attribute"
                + " ");
        out.write(" " + "name" + "=\""
                + StringEscapeUtils.escapeXml(attr.getQualifiedName()) + "\" ");
        if (full) {
            out.write(" " + "path" + "=\""
                    + StringEscapeUtils.escapeXml(XPathFunctions.xpath(attr))
                    + "\" ");
            if (attr.getNamespace() != null)
                out.write(" " + "namespace" + "=\""
                        + StringEscapeUtils.escapeXml(attr.getNamespaceURI())
                        + "\" ");
            if (attr.getNamespacePrefix() != null)
                out.write(" "
                        + "namespacePrefix"
                        + "=\""
                        + StringEscapeUtils.escapeXml(attr.getNamespacePrefix())
                        + "\" ");
            out.write(" " + "exampleValue" + "=\""
                    + StringEscapeUtils.escapeXml(attr.getValue()) + "\" ");
            if (IncludeHandlers.isIncluded(attr, template)) {
                out.write(" " + "included" + "=\""
                        + StringEscapeUtils.escapeXml("true") + "\" ");
            }
        }
        if (full)
            out.write(">\n");

        List<Rule> nodeRules = template.getRuleManager().getNodeRules(attr);

        if (nodeRules != null && nodeRules.size() > 0) {
            if (full)
                out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "Rule" + ">\n");
            int count = 1;
            boolean duplicates = checkDuplicates();
            for (Rule rule : nodeRules) {
                if (rule instanceof Constraint) {
                    Constraint cons = (Constraint) rule;
                    if (duplicates) {
                        cons.toCXF(out, full, count++);
                    } else {
                        cons.toCXF(out, full, -1);
                    }
                }
            }
            if (full)
                out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "Rule" + ">\n");
        } else {
            if (full) {
                out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "Rule" + ">\n");
                out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "constraint" + " ");
                out.write(" " + "action" + "=\""
                        + StringEscapeUtils.escapeXml("makeMandatory()")
                        + "\" ");
                out.write("/>");
                out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "Rule" + ">\n");
            } else {
                out.write(" " + "makeMandatory" + "=\"true\" ");
            }
        }
        if (full) {
            StructureAnnotations sa = (StructureAnnotations) AllowedExtensions
                    .getExtension(StructureAnnotations.name);
            if (sa != null) {
                String xpath = XPathFunctions.xpathParentAndAll(attr);
                StructureAnnotation anno = sa.get(xpath);
                if (anno != null) {
                    anno.toCXF(out);
                }
            }
        }
        if (!full)
            out.write("/>\n");
        if (full)
            out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                    + "Attribute" + ">\n");
    }

    public void toCXF(Writer out) throws Exception {
        toCXF(out, structure, null, true);
    }

    public void toCXF(Writer out, boolean full) throws Exception {
        toCXF(out, structure, null, full);
    }


}
