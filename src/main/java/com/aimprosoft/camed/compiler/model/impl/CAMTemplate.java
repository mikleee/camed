package com.aimprosoft.camed.compiler.model.impl;


import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.extensions.AllowedExtensions;
import com.aimprosoft.camed.compiler.extensions.IExtension;
import com.aimprosoft.camed.compiler.extensions.StructureAnnotations;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
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

    private ConstraintManager constraintManager;

    private static Parser parser = new Parser();

    private CAMXPathEvaluator camXpathEvaluator = null;

    public Document getTemplateDocument() {
        return templateDocument;
    }

    public Map<String, Namespace> getNamespacesMap() {
        return namespacesMap;
    }

    public CAMTemplate() {
        initialise(null);
    }

    public CAMTemplate(Document doc) {
        this.templateDocument = doc;
    }


    private void initialise(String tempFilesDirPath) {
        this.version = "0.1";
        this.parameters = new HashMap<String, Parameter>();
        this.Imports = new HashMap<String, Import>();
        this.Properties = new HashMap<String, Property>();
        this.Structures = new HashMap<String, Structure>();
        this.ruleManager = new RuleManager(this);
        this.tempFilesDirPath = tempFilesDirPath;
    }

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


    public Integer getCAMLevel() {
        return camLevel;
    }

    public Collection<Parameter> getParameters() {
        return parameters.values();
    }

    public Object putImport(String name, Import imp) {
        return Imports.put(name, imp);
    }

    public Object putParameter(String name, Parameter param) {
        return parameters.put(name, param);
    }

    public Object putProperty(String name, String value) {
        return Properties.put(name, new Property(name, value));
    }

    public Object putStructure(String name, Structure structure) {
        return Structures.put(name, structure);
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public void setTemplateVersion(String templateVersion) {
        this.templateVersion = templateVersion;
    }

    public void setCAMLevel(Integer camLevel) {
        this.camLevel = camLevel;
    }

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

    public Map<String, Structure> getStructures() {
        return Structures;
    }

    public Map<String, Include> getIncludes() {
        return Includes;
    }

    public static Parser getParser() {
        return parser;
    }

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

    public ConstraintManager getConstraintManager() {
        return constraintManager;
    }

    public void setConstraintManager(ConstraintManager constraintManager) {
        this.constraintManager = constraintManager;
    }

    @Override
    public String compile() throws CAMCompilerException {

        StringBuilder builder = new StringBuilder();

        builder.append("<as:CAM ");

        for (Namespace ns : namespaces.getNamespacesMap().values()) {
            builder.append(" xmlns:").append(ns.getPrefix()).append("=" + QUOTE).append(ns.getURI()).append(QUOTE + " ");
        }

        builder
                .append(" compiled=" + QUOTE + "true" + QUOTE)
                .append(" CAMlevel=" + QUOTE).append(camLevel).append(QUOTE + " ")
                .append(" version=" + QUOTE).append(version).append(QUOTE).append(">\n");

        builder
                .append(header.compile())
                .append(namespaces.compile());

//        parametersToCXF(writer);

        builder
                .append("<as:AssemblyStructure>\n")
                .append(structure.compile())
                .append("</as:AssemblyStructure>\n");


//        extensionsToCXF(writer);

        builder.append("</as:CAM>\n");


        return builder.toString();
    }
}
