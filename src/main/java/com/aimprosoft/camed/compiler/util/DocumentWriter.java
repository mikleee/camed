package com.aimprosoft.camed.compiler.util;


import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.output.CAMXMLOutputEngine;
import org.jdom.output.Format;
import org.jdom.output.XMLOutputter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.*;

public class DocumentWriter {

    static Logger logger = LoggerFactory.getLogger(DocumentWriter.class);

    static String ENCODING = "UTF-8";


    public static void write(String filename, Document doc) {
        Format format = Format.getRawFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        XMLOutputter outp = new XMLOutputter(format);
        FileOutputStream fos = null;
        Writer writer = null;
        try {
            fos = new FileOutputStream(filename);
            writer = new OutputStreamWriter(fos, ENCODING);
            outp.output(doc, writer);
            writer.flush();
            fos.flush();
        } catch (IOException e) {
            logger.error("Unable to write", e);
        } finally {
            CommonUtils.closeQuietly(writer, fos);
        }

    }

    public static String writeString(Document doc) {
        String output = null;
        Format format = Format.getRawFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        XMLOutputter outp = new XMLOutputter(format);
        OutputStream out = null;
        OutputStreamWriter writer = null;
        try {
            out = new ByteArrayOutputStream();
            writer = new OutputStreamWriter(out, ENCODING);
            outp.output(doc, writer);
            output = writer.toString();
            writer.flush();
            out.flush();
        } catch (IOException e) {
            logger.error("Unable to write", e);
        } finally {
            CommonUtils.closeQuietly(writer, out);
        }
        return output;

    }

    public static void write(String filename, Element elem) {
        Format format = Format.getRawFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        XMLOutputter outp = new XMLOutputter(format);
        FileOutputStream fos = null;
        Writer writer = null;
        try {
            fos = new FileOutputStream(filename);
            writer = new OutputStreamWriter(fos, ENCODING);
            outp.output(elem, writer);
            writer.flush();
            fos.flush();
        } catch (IOException e) {
            logger.error("Unable to write", e);
        } finally {
            CommonUtils.closeQuietly(writer, fos);
        }
    }

    public static void writePretty(String filename, Element elem, CAMTemplate template) {

        Format format = Format.getPrettyFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        CAMXMLOutputEngine outp = new CAMXMLOutputEngine(format);
        FileOutputStream fos = null;
        Writer writer = null;
        try {
            fos = new FileOutputStream(filename);
            writer = new OutputStreamWriter(fos, ENCODING);
            outp.output(elem, writer);
            writer.flush();
            fos.flush();
        } catch (IOException e) {
            logger.error("Unable to write", e);
        } finally {
            CommonUtils.closeQuietly(writer, fos);
        }
    }

    public static String writePrettyString(Document doc) {
        Format format = Format.getPrettyFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        CAMXMLOutputEngine outp = new CAMXMLOutputEngine(format);
        return outp.outputString(doc);
    }

    public static String writePrettyString(Element elem) {
        Format format = Format.getPrettyFormat();
        format = format.setEncoding(ENCODING);
        format = format.setOmitDeclaration(false);
        CAMXMLOutputEngine outp = new CAMXMLOutputEngine(format);
        return outp.outputString(elem);
    }
}
