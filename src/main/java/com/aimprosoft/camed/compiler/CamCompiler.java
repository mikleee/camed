package com.aimprosoft.camed.compiler;

import com.aimprosoft.camed.compiler.Service.CAMTemplateBuilder;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import org.apache.log4j.Logger;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.output.CAMXMLOutputEngine;
import org.jdom.output.Format;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.util.DocumentFactory;

import java.io.*;


public class CamCompiler {

    private final static Logger LOGGER = Logger.getLogger(CamCompiler.class);
    private final static String ENCODING = "UTF-8";

    private String tempFilesDirPath;
    private String compilePath;

    public CamCompiler(String tempFilesDirPath, String compilePath) {
        this.tempFilesDirPath = tempFilesDirPath;
        this.compilePath = compilePath;
    }


    public void compile(File inputFile) throws Exception {
        CAMTemplate template = prepareTemplate(inputFile);
        Element element = template.toDoc(false);
//        Document doc = new DocumentFactory().createDocument(inputFile);
//        Element element = doc.getRootElement();
        writePretty(new File(compilePath), element);
    }

    private CAMTemplate prepareTemplate(File inputFile) throws JDOMException, IOException {
        Document doc = new DocumentFactory().createDocument(inputFile);
        CAMTemplateBuilder builder = new CAMTemplateBuilder();
        CAMTemplate result = builder.build(doc);

        result.setCompilePath(compilePath);
        result.setTempFilesDirPath(tempFilesDirPath);
        result.setTemplatePath(inputFile.getAbsolutePath());
        return result;
    }

    private void writePretty(File outputFile, Element elem) throws IOException {

        Writer writer = null;

        try {
            writer = new OutputStreamWriter(new FileOutputStream(outputFile), ENCODING);
            CAMXMLOutputEngine camxmlOutputEngine = prepareCAMOutputEngine();
            camxmlOutputEngine.output(elem, writer);
        } catch (IOException e) {
            LOGGER.error("Unable to write", e);
            throw e;
        } finally {
            CommonUtils.closeQuietly(writer);
        }
    }

    private CAMXMLOutputEngine prepareCAMOutputEngine() {
        Format format = createPrettyFormat();
        return new CAMXMLOutputEngine(format);
    }

    private Format createPrettyFormat() {
        Format result = Format.getPrettyFormat();
        result = result.setEncoding(ENCODING);
        result = result.setOmitDeclaration(false);
        return result;
    }


}
