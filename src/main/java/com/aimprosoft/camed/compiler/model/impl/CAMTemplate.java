package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.constants.CamsConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.service.compiler.ConstraintManager;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import static com.aimprosoft.camed.compiler.constants.CamsConstants.CAM_NAMESPACE;
import static com.aimprosoft.camed.compiler.constants.CamsConstants.QUOTE;

public class CAMTemplate implements Compilable {

    private String version = "1.0";
    private String camLevel = "1";

    private Header header;
    private Namespaces namespaces;
    private Structure structure;

    private Document templateDocument;

    private ConstraintManager constraintManager;

    public Document getTemplateDocument() {
        return templateDocument;
    }

    public CAMTemplate(Document doc) {
        this.version = doc.getRootElement().getAttribute("version").getValue();
        this.camLevel = doc.getRootElement().getAttribute("CAMlevel").getValue();
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
                .getChild("AssemblyStructure", CamsConstants.CAM_NAMESPACE)
                .getChild("Structure", CamsConstants.CAM_NAMESPACE);
    }

    @Override
    public String compile() throws CamException {

        StringBuilder builder = new StringBuilder("<as:CAM ");

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

        builder
                .append("<as:AssemblyStructure>\n")
                .append(structure.compile())
                .append("</as:AssemblyStructure>\n");

        return builder.append("</as:CAM>\n").toString();
    }
}
