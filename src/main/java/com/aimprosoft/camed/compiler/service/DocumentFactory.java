package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import org.jdom.Document;
import org.jdom.input.SAXBuilder;

import java.io.File;
import java.io.StringReader;

public class DocumentFactory {

    public static Document createDocument(File file) throws CAMCompilerException {
        try {
            SAXBuilder builder = new SAXBuilder();
            builder.setValidation(false);
            builder.setIgnoringElementContentWhitespace(true);
            return builder.build(file);
        } catch (Exception e) {
            throw new CAMCompilerException("Cant parse " + file.getAbsolutePath() + " to xml.");
        }
    }

    public static Document createDocument(String string) throws CAMCompilerException {
        try {
            SAXBuilder builder = new SAXBuilder();
            builder.setValidation(false);
            builder.setIgnoringElementContentWhitespace(true);
            return builder.build(new StringReader(string));
        } catch (Exception e) {
            throw new CAMCompilerException("Cant parse compiled template to xml."); //it wont be happen
        }
    }

}
