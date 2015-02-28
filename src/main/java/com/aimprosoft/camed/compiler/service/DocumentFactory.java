package com.aimprosoft.camed.compiler.service;

import org.jdom.Document;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;

import java.io.File;
import java.io.IOException;
import java.io.StringReader;

public class DocumentFactory {

    public static Document createDocument(File file) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        return builder.build(file);
    }

    public static Document createDocument(String string) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        return builder.build(new StringReader(string));
    }

}
