package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import org.jdom.Document;
import org.jdom.JDOMException;
import org.jdom.output.CAMXMLOutputEngine;
import org.jdom.output.Format;

import java.io.*;


public class CamCompiler {

    private final static String ENCODING = "UTF-8";

    private CAMTemplate inputTemplate;
    private Document outputTemplate;


    public CamCompiler(File inputFile) throws JDOMException, CAMCompilerException, IOException {
        inputTemplate = initInputTemplate(inputFile);
        outputTemplate = compile();
    }

    private CAMTemplate initInputTemplate(File inputFile) throws CAMCompilerException {
        try {
            Document doc = DocumentFactory.createDocument(inputFile);
            return ModelFactory.createCAMTemplate(doc);
        } catch (Exception e) {
            throw new CAMCompilerException(e.getMessage()); //todo
        }

    }

    private Document compile() throws JDOMException, IOException, CAMCompilerException {
        String compiledTemplate = inputTemplate.compile();
        return DocumentFactory.createDocument(compiledTemplate);
    }

    public void compileToFile(File outputFile) throws CAMCompilerException {
        Writer writer = null;

        try {
            writer = new OutputStreamWriter(new FileOutputStream(outputFile), ENCODING);
            CAMXMLOutputEngine camxmlOutputEngine = prepareCAMOutputEngine();
            camxmlOutputEngine.output(outputTemplate.getRootElement(), writer);
        } catch (IOException e) {
            throw new CAMCompilerException("Cant write to " + outputFile.getAbsolutePath());
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
