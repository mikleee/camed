package com.aimprosoft.camed.compiler.service;


import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.DOMBuilder;
import org.jdom.input.SAXBuilder;

import java.io.*;
import java.net.URL;

public class DocumentFactory {

    public DocumentFactory() {
    }

    public DocumentFactory(CAMTemplate template) {
        this.template = template;
    }

    private CAMTemplate template;

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

    public Document createDocument(InputStream inputStream) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        try {
            return (builder.build(inputStream));
        } finally {
            inputStream.close();
        }
    }

    public Document createDocument(URL fileNameURL) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        return (builder.build(fileNameURL));
    }

    public String findFile(String hostFilename, String filename) throws FileNotFoundException {
        File file = new File(filename);
        if (file.exists()) {

            return filename;
        } else if (hostFilename != null && hostFilename.length() > 1) {
            File host = new File(hostFilename);
            String fullFilename = host.getParent() + File.separator + filename;
            file = new File(fullFilename);
            if (file.exists()) {
                return file.getAbsolutePath();
            } else {
                throw new FileNotFoundException("Filename of file not found = " + fullFilename);
            }
        } else {
            throw new FileNotFoundException("Filename of file not found = " + filename);
        }
    }

    public Document includeDocument(URL fileNameURL) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        Document temp = builder.build(fileNameURL);
        Element e = temp.getRootElement();
        stripContent(e);
        return temp;

    }

    public Document includeDocument(org.w3c.dom.Document fileDOM) {
        DOMBuilder DomBuilder = new DOMBuilder();
        Document temp = DomBuilder.build(fileDOM);
        Element e = temp.getRootElement();
        stripContent(e);
        return temp;
    }

    public Element stripContent(Element elm) {
        if (elm.getAttributes() != null && elm.getAttributes().size() > 0) {
            for (Object attr : elm.getAttributes()) {
                if (!(((Attribute) attr).getName().startsWith("xmlns")))
                    ((Attribute) attr).setValue("%" + ((Attribute) attr).getValue() + "%");
            }
        }
        if (elm.getChildren() != null && elm.getChildren().size() > 0) {
            for (Object element : elm.getChildren()) {
                element = stripContent((Element) element);
            }
        } else if (elm.getText().length() > 0) {
            elm.setText("%" + elm.getText() + "%");
        }

        return elm;
    }

    private boolean isCAMTemplate(Document includeDoc) {
        return includeDoc.getRootElement().getName().equals("CAM") && includeDoc.getRootElement().getNamespace() == CAMConstants.CAM_NAMESPACE;
    }

}
