package com.aimprosoft.camed.compiler.model.impl;


import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.extensions.AllowedExtensions;
import com.aimprosoft.camed.compiler.extensions.IExtension;
import com.aimprosoft.camed.compiler.extensions.StructureAnnotations;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.util.*;
import com.aimprosoft.camed.compiler.xpath.CAMXPathEvaluator;
import org.apache.commons.lang.text.StrBuilder;
import org.jaxen.SimpleNamespaceContext;
import org.jdom.*;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.output.XMLOutputter;

import java.io.*;
import java.util.*;

public class CAMTemplate implements Compilable {

    private String version = "0.1"; //todo
    private Integer camLevel = 1;

    private Header header;
    private Namespaces namespaces;
    private Structure structure;

    private String description;
    private String owner;
    private String templateVersion;
    private String creationDateTime;

    private Date dateTime;


    private Map<String, Parameter> parameters = new HashMap<String, Parameter>();
    private Map<String, Property> Properties = new HashMap<String, Property>();
    private Map<String, Import> Imports = new HashMap<String, Import>();
    private Map<String, Structure> Structures = new HashMap<String, Structure>();
    private Map<String, Include> Includes = new HashMap<String, Include>();
    private RuleManager ruleManager = new RuleManager(this);

    private Map<String, Namespace> namespacesMap = new HashMap<String, Namespace>();
    private Document templateDocument;

    private Element runResults = null;

    private String tempFilesDirPath;
    private String compilePath;
    private String templatePath;

    private static Parser parser = new Parser();

    private CAMXPathEvaluator camXpathEvaluator = null;

    public Document getTemplateDocument() {
        return templateDocument;
    }

//    public void initNamespaces() {
//        for (Namespace ns : CommonUtils.retrieveNamespaces(templateDocument)) {
//            namespacesMap.put(ns.getPrefix(), ns);
//        }
//    }

//    private void initHeader() {
//        final Namespace as = namespacesMap.get(CAMConstants.CAM_NAMESPACE_PREFIX);
//        Element header = templateDocument.getRootElement().getChild("Header", as);
//
//        description = header.getChildText("Description", as);
//        owner = header.getChildText("Owner", as);
//        templateVersion = header.getChildText("Version", as);
//    }

//    @SuppressWarnings("unchecked")
//    private void initStructures() {
//        try {
//            JDOMXPath assemblyStructurePath = new JDOMXPathAdapter("//as:AssemblyStructure/as:Structure", this);
//            List<Element> structures = (ArrayList<Element>) assemblyStructurePath.selectNodes(templateDocument);
//            for (Element structure : structures) {
//                //AddStructureToTemplate(structure, template);
//            }
//        } catch (JaxenException e) {
//            e.printStackTrace(); //todo
//        }
//    }


//    private void initStructures(Element structure) throws JDOMException {
//        String taxonomy = structure.getAttributeValue("taxonomy");
//        String taxonomyOther = "";
//
//        if (taxonomy.equals(Structure.TaxonomyType.OTHER.toString())) {
//            taxonomyOther = structure.getAttributeValue("taxonomyOther");
//            if (taxonomyOther.equals("")) {
//                throw new JDOMException("taxonomyOther should be populated if taxonomy = OTHER");
//            }
//        }
//        String ID = structure.getAttributeValue("ID");
//        if (ID == null || ID.equals("")) {
//            ID = "default";
//        }
//        String reference = structure.getAttributeValue("reference");
//        if (reference == null)
//            reference = "";
//        if (structure.getChildren().size() > 1) {
//            throw new JDOMException("Structure should only have one root node");
//        }
//        Structure struct = new Structure(structure, Structure.TaxonomyType.valueOf(taxonomy), taxonomyOther);
//        struct.setID(ID);
//        struct.setReference(reference);
//        struct.setTemplate(this);
//
//        putStructure(ID, struct);
//
//
//    }

    public Map<String, Namespace> getNamespacesMap() {
        return namespacesMap;
    }

    public CAMTemplate() {
        initialise(null);
    }

//    public CAMTemplate(Document doc, String tempFilesDirPath) {
//        this.version = "0.1";
//        this.ruleManager = new RuleManager(this);
//        this.tempFilesDirPath = tempFilesDirPath;
//        this.templateDocument = doc;
//        initNamespaces();
//        initHeader();
//        initStructures();
//    }

    public CAMTemplate(Document doc) {
        this.templateDocument = doc;
    }


    private void initialise(String tempFilesDirPath) {
        this.version = "0.1";
        this.parameters = new HashMap<String, Parameter>();
        this.Imports = new HashMap<String, Import>();
        this.Properties = new HashMap<String, Property>();
        this.Structures = new HashMap<String, Structure>();
//        this.Includes = new HashMap<String, Include>();
        this.ruleManager = new RuleManager(this);
        this.tempFilesDirPath = tempFilesDirPath;
    }

    //
//    private void businessContextRulesToXML(Element cam) {
//        Element bus = new Element("BusinessUseContext", CAMEditor.CAMNamespace);
//        if (getRootRules() != null) {
//            Element rulesElement = new Element("Rules", CAMEditor.CAMNamespace);
//            Element defaultElement = new Element("default",
//                    CAMEditor.CAMNamespace);
//
//            int count = 0;
//            for (Rule rule : getRootRules()) {
//                if (count == 0) {
//                    fillRuleElement(defaultElement, rule);
//                    rulesElement.addContent(defaultElement);
//                } else {
//                    fillRuleElement(rulesElement, rule);
//                }
//                count++;
//            }
//            bus.addContent(rulesElement);
//        }
//        cam.addContent(bus);
//
//    }
//
//    private void fillRuleElement(Element ruleElement, Rule parentRule) {
//        if (parentRule.getType() == Rule.RuleType.context)
//            ruleElement.addContent(((Context) parentRule).toXML());
//        else
//            ruleElement.addContent(((Constraint) parentRule).toXML());
//    }
//
    public Structure getFirstStructure() {
        if (!Structures.isEmpty()) {
            for (Structure str : getStructures().values()) {
                return str;
            }
            return null;
        } else {
            Structure struct = new Structure(new Element("Structure", CAMConstants.CAMNamespace), TaxonomyType.XML, null);
            return struct;
        }
    }

    //
//    /**
//     * @return Returns the cAMLevel.
//     */
    public Integer getCAMLevel() {
        return camLevel;
    }

    //
//    /**
//     * @return Returns the dateTime.
//     */
//    public Date getDateTime() {
//        return dateTime;
//    }
//
//    /**
//     * @return Returns the description.
//     */
//    public String getDescription() {
//        return Description;description
//    public Collection<Import> getImports() {
//        return Imports.values();
//    }
//
//    /**
//     * @return Returns the owner.
//     */
//    public String getOwner() {
//        return owner;
//    }
//
    public Collection<Parameter> getParameters() {
        return parameters.values();
    }

    //
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#get(java.lang.Object)
//     */
//    public Structure getStructure(String name) {
//        return Structures.get(name);
//    }
//
//    /**
//     * @return Returns the templateVersion.
//     */
//    public String getTemplateVersion() {
//        return templateVersion;
//    }
//
//    /**
//     * @return Returns the version.
//     */
//    public String getVersion() {
//        return version;
//    }
//
//    private void importsToXML(Element header) {
//        if (Imports.size() > 0) {
//            Element imps = new Element("Imports", CAMEditor.CAMNamespace);
//            for (Import imp : Imports.values()) {
//                imps.addContent(imp.toXML());
//            }
//            header.addContent(imps);
//        }
//    }
//
//    private void parametersToXML(Element header) {
//        if (Parameters.size() > 0) {
//            Element pars = new Element("Parameters", CAMEditor.CAMNamespace);
//            for (Parameter param : Parameters.values()) {
//                pars.addContent(param.toXML());
//            }
//            header.addContent(pars);
//        }
//    }
//
//    private void propertiesToXML(Element header) {
//        if (Properties.size() > 0) {
//            Element props = new Element("Properties", CAMEditor.CAMNamespace);
//            for (String key : Properties.keySet()) {
//                Property property = Properties.get(key);
//
//                props.addContent(property.toXML());
//            }
//            header.addContent(props);
//        }
//
//    }

    public Object putImport(String name, Import imp) {
        return Imports.put(name, imp);
    }

    public Object putParameter(String name, Parameter param) {
        return parameters.put(name, param);
    }

    public Object putProperty(String name, String value) {
        return Properties.put(name, new Property(name, value));
    }

    //
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#put(K, V)
//     */
    public Object putStructure(String name, Structure structure) {
        return Structures.put(name, structure);
    }
//
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#remove(java.lang.Object)
//     */
//    public Object removeImport(String name) {
//        return Imports.remove(name);
//    }
//
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#remove(java.lang.Object)
//     */
//    public Object removeParameter(String name) {
//        return Parameters.remove(name);
//    }
//
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#remove(java.lang.Object)
//     */
//    public Object removeProperty(String name) {
//        return Properties.remove(name);
//    }
//
//    /*
//     * (non-Javadoc)
//     *
//     * @see java.util.HashMap#remove(java.lang.Object)
//     */
//    public Object removeStructure(String name) {
//        return Structures.remove(name);
//    }
//

    /**
     * @param level The cAMLevel to set.
     */
    public void setCAMLevel(Integer level) {
        camLevel = level;
    }

//    /**
//     * @param dateTime The dateTime to set.
//     */
//    public void setDateTime(Date dateTime) {
//        this.dateTime = dateTime;
//    }

    /**
     * @param description The description to set.
     */
    public void setDescription(String description) {
        this.description = description;
    }

    /**
     * @param owner The owner to set.
     */
    public void setOwner(String owner) {
        this.owner = owner;
    }

    /**
     * @param templateVersion The templateVersion to set.
     */
    public void setTemplateVersion(String templateVersion) {
        this.templateVersion = templateVersion;
    }

    /**
     * @param version The version to set.
     */
    public void setVersion(String version) {
        this.version = version;
    }

    private void structuresToXML(Element cam) {
        Element ass = new Element("AssemblyStructure", CAMConstants.CAMNamespace);
        if (!Structures.isEmpty()) {
            for (Structure struct : Structures.values()) {
                Element elem = struct.toXML();
                Element output = includesToXML(elem);
                if (output == null)
                    ass.addContent(elem);
                else
                    ass.addContent(output);
            }
        }
        cam.addContent(ass);
    }

    @SuppressWarnings("unchecked")
    private Element includesToXML(Element element) {
        if (IncludeHandlers.includedRootElement(element, this) && IncludeHandlers.includeNotIgnoringRoot(element, this)) {

            return IncludeHandlers.getInclude(element, this).toXML(templatePath);
        } else if (!IncludeHandlers.isIncluded(element, this)) {
            Element output = new Element(element.getName(),
                    element.getNamespace());
            if (element.getChildren().size() <= 0)
                output.setText(element.getText());
            for (Attribute attr : (List<Attribute>) element.getAttributes()) {
                output.setAttribute((Attribute) attr.clone());
            }
            for (Element child : (List<Element>) element.getChildren()) {
                Element newChild = includesToXML(child);
                if (newChild != null)
                    output.addContent(newChild);
            }
            return output;
        } else {
            if (element.getParentElement().indexOf(element) == 1) {
                return IncludeHandlers.getInclude(element, this).toXML(templatePath);
            } else {
                return null;
            }
        }
    }
//
//    public Element toXML() {
//        Element cam = new Element("CAM", CAMEditor.CAMNamespace);
//        cam.setAttribute("CAMlevel", getCAMLevel().toString());
//        cam.setAttribute("version", getVersion());
//        for (Namespace ns : getNamespacesMap().values()) {
//            cam.addNamespaceDeclaration(ns);
//        }
//        Element header = new Element("Header", CAMEditor.CAMNamespace);
//        if (getDescription() != null && getDescription().length() != 0)
//            header.addContent(new Element("Description", CAMEditor.CAMNamespace)description            .setText(getDescription()));
//        if (getOwner() != null && getOwner().length() != 0)
//            header.addContent(new ElemownerOwner", CAMEditor.CAMNamespace)
//                    .setText(getOwner()));
//        if (getTemplateVersion() != null && getTemplateVersion().length() != 0)
//            header.addContent(new Element("Version", CAMEditor.CAMNamespace)
//                    .setText(getTemplateVersion()));
//        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss");
//        header.addContent(new Element("DateTime", CAMEditor.CAMNamespace)
//                .setText(df.format(getDateTime())));
//
//        parametersToXML(header);
//        propertiesToXML(header);
//        importsToXML(header);
//        cam.addContent(header);
//        structuresToXML(cam);
//        businessContextRulesToXML(cam);
//        extensionsToXML(cam);
//        return cam;
//    }

    public Element toXMLnoRules() {
        Element cam = new Element("CAM", CAMConstants.CAMNamespace);
        for (Namespace ns : getNamespacesMap().values()) {
            cam.addNamespaceDeclaration(ns);
        }
        structuresToXML(cam);
        return cam;
    }

    public Document toDocument() throws Exception {
        Document document = null;
        ByteArrayOutputStream out = null;
        ByteArrayInputStream input = null;
        try {
            out = new ByteArrayOutputStream();
            XMLOutputter xmlOut = new XMLOutputter();
            xmlOut.output(toXMLnoRules(), out);
            input = new ByteArrayInputStream(out.toByteArray());
            return new DocumentFactory().createDocument(input);
        } finally {
            CommonUtils.closeQuietly(out, input);
        }
    }

    public void writeToCXF(String fileName, boolean full) {
        OutputStreamWriter writer = null;
        try {
            File file = CommonUtils.findFile(fileName);
            writer = new OutputStreamWriter(new FileOutputStream(file));

            openRootTag(writer, full);

            writer.write(header.compile());
            writer.write(namespaces.compile());

            parametersToCXF(writer);

            writer.write(compileStructureToCXF());

            extensionsToCXF(writer);
            closeRootTag(writer);

        } catch (Exception e) {
            e.printStackTrace(); //todo
        } finally {
            CommonUtils.closeQuietly(writer);
        }


    }

    private void openRootTag(Writer out, boolean full) throws IOException {
        out.write("<as:CAM ");

        for (Namespace ns : namespaces.getNamespacesMap().values()) {
            out.write(" xmlns:" + ns.getPrefix() + "=\"" + ns.getURI() + "\" ");
        }

        if (!full) {
            out.write(" compiled=\"true\"");
        }
        out.write(" CAMlevel=\"" + camLevel.toString() + "\" ");
        out.write(" version=\"" + version + "\">\n");
    }

    private void closeRootTag(Writer out) throws IOException {
        out.write("</as:CAM>\n");
    }

    private void headerToCXF(Writer out) throws IOException {
        out.write(header.compile());
    }

    private void assemblyStructureToCXF(Writer out, boolean full) throws Exception {
        out.write("<as:AssemblyStructure>\n");

        for (Structure struct : Structures.values()) {
            struct.toCXF(out, full);
        }

        out.write("</as:AssemblyStructure>\n");
    }

    private String compileStructureToCXF() throws Exception {
        return "<as:AssemblyStructure>\n" + structure.compile() + "</as:AssemblyStructure>\n";
    }


    private void parametersToCXF(Writer out) throws IOException {
        if (!parameters.isEmpty()) {
            out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":" + "Parameters" + ">\n");
            for (Parameter param : parameters.values()) {
                param.toCXF(out);
            }
            out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":" + "Parameters" + ">\n");
        }
    }

    private void namespacesToCXF(Writer out) throws IOException {
        out.write(namespaces.compile());
    }

    public Element toDoc(boolean full) throws Exception {

        String fileName = CommonUtils.generateTempFileName(tempFilesDirPath);

        writeToCXF(fileName, full);

        DocumentFactory df = new DocumentFactory(this);
        Document results = df.createDocument(fileName);

        Element elem = results.getRootElement();
        elem.detach();

        return elem;
    }

    //
//    public Element toDoc() throws Exception {
//        return toDoc(true);
//    }
//
    private void extensionsToXML(Element cam) {
        for (IExtension ext : AllowedExtensions.getExtensions()) {
            Element extension = ext.toXML();
            if (extension != null)
                cam.addContent(extension);
        }

    }

    //
    private void extensionsToCXF(Writer out) throws IOException {
        for (IExtension ext : AllowedExtensions.getExtensions()) {
            if (!ext.getName().equals(StructureAnnotations.name)) {
                Element extension = ext.toCXF();
                if (extension != null) {
                    String output = DocumentWriter.writePrettyString(extension);
                    out.write(output);
                }
            }
        }

    }

    //
//    /*
//     * (non-Javadoc)
//     * 
//     * @see java.util.HashMap#values()
//     */
//    public Collection<Property> getProperties() {
//        return Properties.values();
//    }
//
    public Map<String, Structure> getStructures() {
        return Structures;
    }

    //
//    public boolean namespacePrefixExists(String prefix) {
//        if (prefix != null) {
//            for (Namespace ns : namespacesMap.values()) {
//                if (ns.getPrefix().equals(prefix)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//
//    }
//
//    public Namespace getNamespace(String prefix) {
//        if (prefix != null) {
//            for (Namespace ns : namespacesMap.values()) {
//                if (ns.getPrefix().equals(prefix)) {
//                    return ns;
//                }
//            }
//        }
//        return null;
//
//    }
//
//    public void setRunResults(Element elem) {
//        runResults = elem;
//    }
//
//    public Element getRunResults() {
//        return runResults;
//    }
//
    public Map<String, Include> getIncludes() {
        return Includes;
    }

    //
//    public void removeInclude(Include include) {
//        for (String key : getIncludes().keySet()) {
//            if (Includes.get(key).equals(include)) {
//                Includes.remove(key);
//                return;
//            }
//        }
//    }
//
//    public Include getInclude(Element element) {
//        for (Include include : getIncludes().values()) {
//            if (include.getDocument().equals(element)) {
//                return include;
//            }
//        }
//        return null;
//    }
//
    public static Parser getParser() {
        return parser;
    }

    //
//    public void deleteRule(Rule rule) throws Exception {
//        getRuleManager().removeRule(rule.getUuid());
//    }
//
//    public void addRule(Rule rule) throws Exception {
//        getRuleManager().addRule(rule);
//    }
//
//    public void deleteNodeRules(Object node) throws Exception {
//        camXpathEvaluator = new CAMXPathEvaluator(toXMLnoRules(),
//                getNamespacesMap());
//        deleteRules(node);
//        camXpathEvaluator.close();
//    }
//
//    private void deleteRules(Object node) throws Exception {
//        for (Rule rule : getRuleManager().getNodeRules(node)) {
//            if (!Boolean.parseBoolean(camXpathEvaluator.evaluate("count("
//                    + rule.getXpath() + ") > 1")))
//                getRuleManager().removeRule(rule.getUuid());
//
//        }
//
//        if (node instanceof Element) {
//            for (Object attribute : ((Element) node).getAttributes())
//                deleteRules(attribute);
//            for (Object element : ((Element) node).getChildren())
//                deleteRules(element);
//        }
//    }
//
//    public boolean renameNode(Object node, String newName) throws Exception {
//        boolean hasMoreElements = false;
//        String originalXpath = XPathFunctions.xpathParentAndAll(node);
//        camXpathEvaluator = new CAMXPathEvaluator(toXMLnoRules(), getNamespacesMap());
//        String name = null;
//        Namespace ns = null;
//        if (newName.contains(":")) {
//            name = newName.substring(newName.lastIndexOf(":") + 1);
//            ns = getNamespace(newName.substring(0, newName.lastIndexOf(":")));
//        } else {
//            name = newName;
//        }
//
//        if (node instanceof Element) {
//            renameRuleXpath(node, ((Element) node).getQualifiedName(), newName);
//            ((Element) node).setName(name);
//            ((Element) node).setNamespace(ns);
//        } else if (node instanceof Attribute) {
//            renameRuleXpath(node, ((Attribute) node).getQualifiedName(),
//                    newName);
//            ((Attribute) node).setName(name);
//            ((Attribute) node).setNamespace(ns);
//        }
//        hasMoreElements = renameAnnotationsXpath(node, originalXpath);
//        camXpathEvaluator.close();
//        getRuleManager().setUpXpathRulesMap();
//        return hasMoreElements;
//    }
//
//    /**
//     * @param node
//     * @param originalXpath
//     * @throws CloneNotSupportedException
//     * @throws XPathExpressionException
//     */
//    private boolean renameAnnotationsXpath(Object node, String originalXpath)
//            throws CloneNotSupportedException, XPathExpressionException {
//        boolean hasMoreElements = false;
//        if (getAnnotations() != null) {
//            if (getAnnotations().containsKey(originalXpath)) {
//                StructureAnnotation sa = null;
//                if (!Boolean.parseBoolean(camXpathEvaluator.evaluate("count("
//                        + originalXpath + ") > 1"))) {
//                    sa = getAnnotations().remove(originalXpath);
//                    sa.setXpath(XPathFunctions.xpathParentAndAll(node));
//                    getAnnotations().put(
//                            XPathFunctions.xpathParentAndAll(node), sa);
//                    // Fix children level as well
//                    if (node instanceof Element) {
//                        String oldParenName = originalXpath
//                                .substring(originalXpath.lastIndexOf("/") + 1);
//                        for (Object child : ((Element) node).getChildren()) {
//                            if (getAnnotations().containsKey(
//                                    "//"
//                                            + oldParenName
//                                            + "/"
//                                            + ((Element) child)
//                                            .getQualifiedName())) {
//                                sa = getAnnotations().remove(
//                                        "//"
//                                                + oldParenName
//                                                + "/"
//                                                + ((Element) child)
//                                                .getQualifiedName());
//                                sa.setXpath(XPathFunctions
//                                        .xpathParentAndAll(child));
//                                getAnnotations()
//                                        .put(XPathFunctions
//                                                .xpathParentAndAll(child),
//                                                sa);
//                            }
//                        }
//                        for (Object child : ((Element) node).getAttributes()) {
//                            if (getAnnotations().containsKey(
//                                    "//"
//                                            + oldParenName
//                                            + "/@"
//                                            + ((Attribute) child)
//                                            .getQualifiedName())) {
//                                sa = getAnnotations().remove(
//                                        "//"
//                                                + oldParenName
//                                                + "/@"
//                                                + ((Attribute) child)
//                                                .getQualifiedName());
//                                sa.setXpath(XPathFunctions
//                                        .xpathParentAndAll(child));
//                                getAnnotations()
//                                        .put(XPathFunctions
//                                                .xpathParentAndAll(child),
//                                                sa);
//                            }
//                        }
//                    }
//                } else {
//                    hasMoreElements = true;
//                    sa = getAnnotations().get(originalXpath);
//                    StructureAnnotation saClone = sa.cloneAnnotation();
//                    saClone.setXpath(XPathFunctions.xpathParentAndAll(node));
//                    getAnnotations().put(
//                            XPathFunctions.xpathParentAndAll(node), saClone);
//                    // Fix children level as well
//                    if (node instanceof Element) {
//                        String oldParenName = originalXpath
//                                .substring(originalXpath.lastIndexOf("/") + 1);
//                        for (Object child : ((Element) node).getChildren()) {
//                            if (getAnnotations().containsKey(
//                                    "//"
//                                            + oldParenName
//                                            + "/"
//                                            + ((Element) child)
//                                            .getQualifiedName())) {
//                                sa = getAnnotations().get(
//                                        "//"
//                                                + oldParenName
//                                                + "/"
//                                                + ((Element) child)
//                                                .getQualifiedName());
//                                saClone = sa.cloneAnnotation();
//                                saClone.setXpath(XPathFunctions
//                                        .xpathParentAndAll(child));
//                                getAnnotations()
//                                        .put(XPathFunctions
//                                                .xpathParentAndAll(child),
//                                                saClone);
//                            }
//                        }
//                        for (Object child : ((Element) node).getAttributes()) {
//                            if (getAnnotations().containsKey(
//                                    "//"
//                                            + oldParenName
//                                            + "/@"
//                                            + ((Attribute) child)
//                                            .getQualifiedName())) {
//                                sa = getAnnotations().get(
//                                        "//"
//                                                + oldParenName
//                                                + "/@"
//                                                + ((Attribute) child)
//                                                .getQualifiedName());
//                                saClone = sa.cloneAnnotation();
//                                saClone.setXpath(XPathFunctions
//                                        .xpathParentAndAll(child));
//                                getAnnotations()
//                                        .put(XPathFunctions
//                                                .xpathParentAndAll(child),
//                                                saClone);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        return hasMoreElements;
//    }
//
//    private void renameRuleXpath(Object origNode, String oldName, String newName)
//            throws Exception {
//
//        if (oldName != null && newName != null) {
//            Rule ruleClone = null;
//
//            for (Rule rule : getRuleManager().getNodeRules(origNode)) {
//                if (!Boolean.parseBoolean(camXpathEvaluator
//                        .evaluate("count(" + rule.getXpath() + ") > 1"))) {
//                    rule.setXpath(rule.getXpath().replace(oldName, newName));
//                } else {
//                    ruleClone = rule.cloneRule();
//                    ruleClone.setUUID();
//                    ruleClone.setXpath(ruleClone.getXpath().replace(
//                            oldName, newName));
//                    addRule(ruleClone);
//                }
//            }
//        }
//        if (origNode instanceof Element) {
//            if (!((Element) origNode).getChildren().isEmpty()) {
//                for (Object child : ((Element) origNode).getChildren()) {
//                    renameRuleXpath(child, oldName, newName);
//                }
//            }
//            if (!((Element) origNode).getAttributes().isEmpty()) {
//                for (Object child : ((Element) origNode).getAttributes()) {
//                    renameRuleXpath(child, oldName, newName);
//                }
//            }
//        }
//    }
//
//    /**
//     * @return the annotations
//     */
//    public StructureAnnotations getAnnotations() {
//        if (annotations == null)
//            annotations = (StructureAnnotations) AllowedExtensions
//                    .getExtension(StructureAnnotations.name);
//        return annotations;
//    }
//
//    public void deleteNodeAnnotations(Object obj) throws Exception {
//        camXpathEvaluator = new CAMXPathEvaluator(toXMLnoRules(), getNamespacesMap());
//        deleteAnnotations(obj);
//        camXpathEvaluator.close();
//    }
//
//    private void deleteAnnotations(Object node) throws XPathExpressionException {
//        if (!Boolean.parseBoolean(camXpathEvaluator.evaluate("count("
//                + XPathFunctions.xpathParentAndAll(node) + ") > 1")))
//            deleteAnnotation(node);
//
//        if (node instanceof Element) {
//            for (Object attribute : ((Element) node).getAttributes()) {
//                deleteAnnotations(attribute);
//            }
//            for (Object element : ((Element) node).getChildren()) {
//                deleteAnnotations(element);
//            }
//        }
//    }
//
//    public void deleteAnnotation(Object obj) {
//        String annXpath = XPathFunctions.xpathParentAndAll(obj);
//        if (getAnnotations() != null) {
//            if (getAnnotations().containsKey(annXpath)) {
//                getAnnotations().remove(annXpath);
//            }
//        }
//    }
//
//    public Rule getDefaultContextParentRule() {
//        return getRuleManager().getDefaultContextParentRule();
//    }
//
    public List<Rule> getRootRules() {
        return getRuleManager().getRootRules();
    }

    public SimpleNamespaceContext getNamespaceContext() {
        SimpleNamespaceContext nsContext = new SimpleNamespaceContext();
        Namespace ns = null;
        for (Map.Entry<String, Namespace> entry : getNamespacesMap().entrySet()) {
            ns = entry.getValue();
            nsContext.addNamespace(ns.getPrefix(), ns.getURI());
        }
        return nsContext;
    }

    public RuleManager getRuleManager() {
        return ruleManager;
    }

    public String getTempFilesDirPath() {
        return tempFilesDirPath;
    }

    public void setTempFilesDirPath(String tempFilesDirPath) {
        this.tempFilesDirPath = tempFilesDirPath;
    }

    public String getCompilePath() {
        return compilePath;
    }

    public void setCompilePath(String compilePath) {
        this.compilePath = compilePath;
    }

    public Date getDateTime() {
        return dateTime;
    }

    public void setDateTime(Date dateTime) {
        this.dateTime = dateTime;
    }

    public String getCreationDateTime() {
        return creationDateTime;
    }

    public void setCreationDateTime(String creationDateTime) {
        this.creationDateTime = creationDateTime;
    }

    public String getTemplatePath() {
        return templatePath;
    }

    public void setTemplatePath(String templatePath) {
        this.templatePath = templatePath;
    }

    public void setTemplateDocument(Document templateDocument) {
        this.templateDocument = templateDocument;
    }

    public void setNamespacesMap(Map<String, Namespace> namespacesMap) {
        this.namespacesMap = namespacesMap;
    }

    public Header getHeader() {
        return header;
    }

    public void setHeader(Header header) {
        this.header = header;
    }

    public com.aimprosoft.camed.compiler.model.impl.Namespaces getNamespaces() {
        return namespaces;
    }

    public void setNamespaces(com.aimprosoft.camed.compiler.model.impl.Namespaces namespaces) {
        this.namespaces = namespaces;
    }

    public Structure getStructure() {
        return structure;
    }

    public void setStructure(Structure structure) {
        this.structure = structure;
    }

    @Override
    public String compile() {
        return null;
    }
}
