package com.aimprosoft.camed.compiler.xpath;

import com.aimprosoft.camed.compiler.util.Namespaces;
import org.jaxen.SimpleNamespaceContext;
import org.jaxen.SimpleVariableContext;
import org.jaxen.jdom.JDOMXPath;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.Namespace;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Xpath {

    static Logger logger = LoggerFactory.getLogger(Xpath.class);

    private Namespaces namespaces;
    private JDOMXPath xpath = null;
    private Element element = null;
    private SimpleNamespaceContext nsContext;
    private SimpleVariableContext vContext = null;
    private boolean namespacesExist = false;


    public Xpath() {

    }

    public Xpath(Document doc) {
        this.element = doc.getRootElement();
    }

    public void setUpVariables() {
        if (xpath != null && vContext != null)
            xpath.setVariableContext(vContext);

    }

    public void setUpXPath(String path) throws Exception {
        if (this.element == null) {
            throw new NullPointerException();
        }
        setUpXPath(this.element, path);
    }

    public void setUpXPath(Document doc, String path) throws Exception {
        element = doc.getRootElement();
        setUpXPath(element, path);
    }

    public void setUpXPath(Element elem, String path) throws Exception {
        this.element = elem;
        xpath = new JDOMXPath(path);
        if (namespaces == null) {
            setNamespaceContext(elem);
        }
        setUpNamespaces();
        setUpVariables();
    }

    public void setUpXPath(String path, SimpleNamespaceContext namespaceContext) throws Exception {
        //this.element = doc.getRootElement();
        xpath = new JDOMXPath(path);
        xpath.setNamespaceContext(namespaceContext);
    }

    private void setUpNamespaces() {
        if (namespaces != null) {
            if (namespacesExist) {
                xpath.setNamespaceContext(nsContext);
            }
        }
    }

    private void setNamespaceContext(Element elem) throws JDOMException {
        namespaces = new Namespaces(elem);
        if (!namespaces.getNamespaceList().isEmpty()) {
            namespacesExist = true;
        }
        nsContext = resetNamespaceContext();
    }

    private SimpleNamespaceContext resetNamespaceContext() {
        SimpleNamespaceContext nsContext = new SimpleNamespaceContext();
        if (namespaces != null) {
            for (Namespace ns : namespaces.getNamespaceList()) {
                if (!(ns.getPrefix().equals("") && ns.getURI().equals(""))) {
                    nsContext.addNamespace(ns.getPrefix(), ns.getURI());
                    if (logger.isDebugEnabled())
                        logger.debug("Namespaces:" + ns.getPrefix() + ":"
                                + ns.getURI());
                    namespacesExist = true;
                }
            }
        }
        return nsContext;
    }

    public JDOMXPath getXPath() {
        return xpath;
    }

    public void setXPath(JDOMXPath xpath) {
        this.xpath = xpath;
    }

    protected Element getElement() {
        return element;
    }

    protected void setElement(Element element) {
        this.element = element;
    }

    public Namespaces getNamespaces() {
        return namespaces;
    }

    protected void setNamespaces(Namespaces namespaces) {
        this.namespaces = namespaces;
    }

    protected JDOMXPath getXpath() {
        return xpath;
    }

    protected void setXpath(JDOMXPath xpath) {
        this.xpath = xpath;
    }

}
