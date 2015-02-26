package com.aimprosoft.camed.compiler.util;


import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Include;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.xpath.Xpath;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.filter.ContentFilter;
import org.jdom.input.DOMBuilder;
import org.jdom.input.SAXBuilder;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;

public class DocumentFactory {

    public DocumentFactory() {
    }

    public DocumentFactory(CAMTemplate template) {
        this.template = template;
    }

    private CAMTemplate template;

    public Document createDocument(String fileNameString) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        return (builder.build(new File(findFile(template.getTemplatePath(), fileNameString))));
    }

    public Document createDocument(File file) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        return (builder.build(file));
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

    public void handleStructureIncludes(Element root) throws Exception {
        handleStructureIncludes(root, false);
    }

    @SuppressWarnings("unchecked")
    public void handleStructureIncludes(Element root, boolean addToIncludes) throws Exception {
        boolean raw = false;
        Xpath xpath = new Xpath();
        xpath.setUpXPath(root, "//as:include");
        for (Object incl : xpath.getXPath().selectNodes(root)) {
            Document includeDoc = null;
            Element include = (Element) incl;
            if (include.getAttribute("raw") != null && include.getAttribute("raw").getValue().equals("true")) {
                raw = true;
            }
            String includeFilename = include.getTextNormalize();
            try {
                URL includeURL = new URL(includeFilename);
                if (raw) {
                    includeDoc = includeDocument(includeURL);
                } else {
                    includeDoc = createDocument(includeURL);
                }
            } catch (MalformedURLException e) {
                try {
                    URL url1 = new URL(template.getTemplatePath());
                    String uStr = url1.toExternalForm();
                    URL realFilenameURL = new URL(uStr.substring(0, uStr.lastIndexOf("/") + 1) + includeFilename);
                    if (raw) {
                        includeDoc = includeDocument(realFilenameURL);
                    } else {
                        includeDoc = createDocument(realFilenameURL);
                    }
                } catch (MalformedURLException mfU1) {
                    File templateFile = new File(template.getTemplatePath());
                    if (includeFilename.contains(templateFile.getParent())) {
                        includeFilename = includeFilename.substring(templateFile.getParent().length() + 1);
                    }
                    File file = new File(includeFilename);

                    String realFilename = includeFilename;
                    if (!file.exists()) {
                        File fileTemp = new File(template.getTemplatePath());
                        realFilename = fileTemp.getParent() + File.separatorChar + includeFilename;
                    }
                    if (raw) {
                        includeDoc = new DocumentFactory().includeDocument(realFilename);
                    } else {
                        includeDoc = new DocumentFactory().createDocument(realFilename);
                    }
                }
            }
            if (isCAMTemplate(includeDoc)) {
                Xpath inclXpath = new Xpath(includeDoc);
                inclXpath.setUpXPath("//as:Structure/*");
                Object includeObj = inclXpath.getXPath().selectSingleNode(includeDoc);
                if (includeObj != null && includeObj instanceof Element) {
                    Element e = (Element) includeObj;
                    include.getParentElement().addContent(e.detach());
                    if (addToIncludes) {
                        template.getIncludes().put(includeFilename, new Include(includeDoc.getRootElement(), includeFilename));
                    }

                } else if (includeObj != null && includeObj instanceof Document) {
                    Document d = (Document) includeObj;
                    include.getParentElement().addContent(d.getRootElement().detach());
                    if (addToIncludes) {
                        template.getIncludes().put(includeFilename, new Include(includeDoc.getRootElement(), includeFilename));
                    }
                }
            } else {
                boolean included = false;

                List<Object> att = include.getAttributes();
                if (att.size() > 0) {
                    Attribute at = (Attribute) att.get(0);
                    if (at.getName().equals("ignoreRoot") && at.getValue().equals("yes")) {
                        if (addToIncludes) {
                            Include newIncl = new Include(includeDoc.getRootElement(), includeFilename, true);
                            newIncl.setIgnoreRoot(true);
                            template.getIncludes().put(XPathFunctions.fullXpathWithPosition(include.getParentElement()) + includeFilename, newIncl);
                        }
                        List<Element> children = includeDoc.getRootElement().removeContent(new ContentFilter(ContentFilter.ELEMENT));
                        for (Element child : children) {
                            include.getParentElement().addContent(include.getParent().indexOf(include), child);
                            included = true;
                        }

                    }
                }
                if (!included) {
                    if (addToIncludes) {
                        Include newIncl = new Include(includeDoc.getRootElement(), includeFilename);
                        newIncl.setIgnoreRoot(false);
                        template.getIncludes().put(XPathFunctions.fullXpathWithPosition(include.getParentElement()) + includeFilename, newIncl);
                    }
                    if (include.getParentElement() != null)
                        include.getParentElement().addContent(include.getParent().indexOf(include), includeDoc.getRootElement().detach());
                }
                //templateInclude.setParentElement(include.getParentElement());
            }
            if (include.getParentElement() != null)
                include.getParent().removeContent(include);
        }
        xpath.setUpXPath(root, "//as:include");
        if (xpath.getXPath().selectNodes(root).size() > 0)
            handleStructureIncludes(root, addToIncludes);
    }

    public Document includeDocument(String fileNameString) throws JDOMException, IOException {
        SAXBuilder builder = new SAXBuilder();
        builder.setValidation(false);
        builder.setIgnoringElementContentWhitespace(true);
        //builder.setXMLFilter(new CamFilter());
        Document temp = builder.build(new File(findFile(template.getTemplatePath(), fileNameString)));
        Element e = temp.getRootElement();
        stripContent(e);
        return temp;
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
