package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import static com.aimprosoft.camed.compiler.constants.CAMConstants.CAM_NAMESPACE;
import static com.aimprosoft.camed.compiler.constants.CAMConstants.QUOTE;

public class CAMTemplate implements Compilable {

    private final static String version = "0.1"; //todo
    private final static Integer camLevel = 1;

    private Header header;
    private Namespaces namespaces;
    private Structure structure;

    private Document templateDocument;

    private ConstraintManager constraintManager;

    public Document getTemplateDocument() {
        return templateDocument;
    }

    public CAMTemplate(Document doc) {
        this.templateDocument = doc;
    }

    public void setHeader(Header header) {
        this.header = header;
    }

    public Namespaces getNamespaces() {
        return namespaces;
    }

    public void setNamespaces(Namespaces namespaces) {
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

    public Element getContextElement() {
        return templateDocument.getRootElement()
                .getChild("BusinessUseContext", CAM_NAMESPACE)
                .getChild("Rules", CAM_NAMESPACE)
                .getChild("default", CAM_NAMESPACE)
                .getChild("context", CAM_NAMESPACE);
    }

    public Element getStructureElement() {
        return templateDocument.getRootElement()
                .getChild("AssemblyStructure", CAMConstants.CAM_NAMESPACE)
                .getChild("Structure", CAMConstants.CAM_NAMESPACE);
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
                .append(header == null ? "" : header.compile())
                .append(namespaces.compile());

//        parametersToCXF(writer) todo;

        builder
                .append("<as:AssemblyStructure>\n")
                .append(structure.compile())
                .append("</as:AssemblyStructure>\n");


//        extensionsToCXF(writer) todo;

        return builder.append("</as:CAM>\n").toString();
    }
}
