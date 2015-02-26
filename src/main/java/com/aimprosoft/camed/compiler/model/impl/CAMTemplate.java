package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
import com.aimprosoft.camed.compiler.util.*;
import org.jaxen.SimpleNamespaceContext;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;
import org.jdom.output.XMLOutputter;

import java.io.*;
import java.util.*;

public class CAMTemplate implements Compilable {

    private String version = "0.1"; //todo
    private Integer camLevel = 1;

    private Header header;
    private Namespaces namespaces;
    private Structure structure;

    private Map<String, Include> Includes = new HashMap<String, Include>();

    private Document templateDocument;

    private String tempFilesDirPath;
    private String templatePath;
    private String compilePath;

    private ConstraintManager constraintManager;

    private static Parser parser = new Parser();

    public Document getTemplateDocument() {
        return templateDocument;
    }

    public CAMTemplate(Document doc) {
        this.templateDocument = doc;
    }

    public void writeToCXF(String fileName, boolean full) {
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

    public Element toDoc(boolean full) throws Exception {

        String fileName = CommonUtils.generateTempFileName(tempFilesDirPath);

        writeToCXF(fileName, full);

        DocumentFactory df = new DocumentFactory(this);
        Document results = df.createDocument(fileName);

        Element elem = results.getRootElement();
        elem.detach();

        return elem;
    }

    public Map<String, Include> getIncludes() {
        return Includes;
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

    public String getCompilePath() {
        return compilePath;
    }

    public void setCompilePath(String compilePath) {
        this.compilePath = compilePath;
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

//        parametersToCXF(writer) todo;

        builder
                .append("<as:AssemblyStructure>\n")
                .append(structure.compile())
                .append("</as:AssemblyStructure>\n");


//        extensionsToCXF(writer) todo;

        return builder.append("</as:CAM>\n").toString();
    }
}
