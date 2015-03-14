package com.aimprosoft.camed.service.compiler;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.impl.CamTemplate;
import com.aimprosoft.camed.service.DocumentFactory;
import com.aimprosoft.camed.service.ModelFactory;
import com.aimprosoft.camed.util.CommonUtils;
import org.jdom.Document;
import org.jdom.output.Format;

import java.io.*;


public class CamCompiler {

    private final static String ENCODING = "UTF-8";

    private OutputEngine outputEngine;

    private CamTemplate inputTemplate;
    private Document outputTemplate;
    private File inputFile;


    public CamCompiler(File inputFile) throws CamException {
        initOutputEngine();
        this.inputFile = inputFile;
        inputTemplate = initInputTemplate(inputFile);
        outputTemplate = compile();
    }

    private CamTemplate initInputTemplate(File inputFile) throws CamException {
        Document doc = DocumentFactory.createDocument(inputFile);
        return ModelFactory.createCAMTemplate(doc);
    }

    private Document compile() throws CamException {
        String compiledTemplate = inputTemplate.compile();
        return DocumentFactory.createDocument(compiledTemplate);
    }

    public void compileAndSave() throws CamException {
        File outputFile = CommonUtils.changeFileExtension(inputFile, "cxx");
        compileAndSave(outputFile);
    }

    public void compileAndSave(File outputFile) throws CamException {
        Writer writer = null;

        try {
            writer = createBufferedWriter(outputFile);
            outputEngine.output(outputTemplate.getRootElement(), writer);
        } catch (IOException e) {
            throw new CamException("Cant write to " + outputFile.getAbsolutePath());
        } finally {
            CommonUtils.closeQuietly(writer);
        }
    }

    private void initOutputEngine() {
        Format format = createPrettyFormat();
        this.outputEngine = new OutputEngine(format);
    }

    private Format createPrettyFormat() {
        Format result = Format.getPrettyFormat();
        result = result.setEncoding(ENCODING);
        result = result.setOmitDeclaration(false);
        return result;
    }

    private Writer createBufferedWriter(File outputFile) throws FileNotFoundException, UnsupportedEncodingException {
        return new BufferedWriter(
                new OutputStreamWriter(
                        new FileOutputStream(outputFile), ENCODING
                )
        );
    }

}
