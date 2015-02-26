package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import com.aimprosoft.camed.compiler.util.DocumentFactory;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

public class CAMTemplate implements Compilable {

    private final static String version = "0.1"; //todo
    private final static Integer camLevel = 1;

    private Header header;
    private Namespaces namespaces;
    private Structure structure;

    private Document templateDocument;

    private String tempFilesDirPath;
    private String templatePath;

    private ConstraintManager constraintManager;

    public Document getTemplateDocument() {
        return templateDocument;
    }

    public CAMTemplate(Document doc) {
        this.templateDocument = doc;
    }

    public void writeToCXF(String fileName) {
        OutputStreamWriter writer = null;
        try {
            File file = CommonUtils.findFile(fileName);
            writer = new OutputStreamWriter(new FileOutputStream(file));

            writer.write(this.compile());

        } catch (Exception e) {
            e.printStackTrace(); //todo
        } finally {
            CommonUtils.closeQuietly(writer);
        }
    }

    public Element toDoc() throws Exception {

        String fileName = CommonUtils.generateTempFileName(tempFilesDirPath);

        writeToCXF(fileName);

        DocumentFactory df = new DocumentFactory(this);
        Document results = df.createDocument(fileName);

        Element elem = results.getRootElement();
        elem.detach();

        return elem;
    }

    public void setTempFilesDirPath(String tempFilesDirPath) {
        this.tempFilesDirPath = tempFilesDirPath;
    }

    public String getTemplatePath() {
        return templatePath;
    }

    public void setTemplatePath(String templatePath) {
        this.templatePath = templatePath;
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

    @Override
    public String compile() throws CAMCompilerException {

        StringBuilder builder = new StringBuilder();

        builder.append("<as:CAM ");

        for (Namespace ns : namespaces.getNamespacesMap().values()) {
            builder.append(" xmlns:").append(ns.getPrefix()).append("=" + CAMConstants.QUOTE).append(ns.getURI()).append(CAMConstants.QUOTE + " ");
        }

        builder
                .append(" compiled=" + CAMConstants.QUOTE + "true" + CAMConstants.QUOTE)
                .append(" CAMlevel=" + CAMConstants.QUOTE).append(camLevel).append(CAMConstants.QUOTE + " ")
                .append(" version=" + CAMConstants.QUOTE).append(version).append(CAMConstants.QUOTE).append(">\n");

        builder
                .append(header == null ? "" : header.compile()) //todo optional
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
