package com.aimprosoft.camed.service;

import com.aimprosoft.camed.CamException;
import org.jdom.Document;
import org.jdom.input.SAXBuilder;

import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;
import java.io.StringReader;

public class DocumentFactory {

    public static Document createDocument(File file) throws CamException {
        try {
            SAXBuilder builder = new SAXBuilder();
            builder.setValidation(false);
            builder.setIgnoringElementContentWhitespace(true);
            return builder.build(file);
        } catch (Exception e) {
            throw new CamException("Cant parse " + file.getAbsolutePath() + " to xml.");
        }
    }

    public static Document createDocument(String string) throws CamException {
        try {
            SAXBuilder builder = new SAXBuilder();
            builder.setValidation(false);
            builder.setIgnoringElementContentWhitespace(true);
            return builder.build(new StringReader(string));
        } catch (Exception e) {
            throw new CamException("Cant parse compiled template to xml."); //it wont be happen
        }
    }

    public static Object createW3Document(String string) throws CamException {
        try {
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

            dbf.setNamespaceAware(true);
            dbf.setCoalescing(true);
            dbf.setIgnoringElementContentWhitespace(true);
            dbf.setIgnoringComments(true);
            return dbf.newDocumentBuilder().parse(new File(string));
        } catch (Exception e) {
            throw new CamException("Cant parse compiled template to xml."); //it wont be happen
        }
    }

}
