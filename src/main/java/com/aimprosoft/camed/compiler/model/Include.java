package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Attribute;
import org.jdom.Element;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class Include {

    private Element document = null;
    private String uri = null;
    private boolean ignoreRoot = false;

    private Element parentElement = null;

    private List<Element> elements = new ArrayList<Element>();

    public Element getParentElement() {
        return parentElement;
    }


    public Include(Element doc, String URI) {
        document = doc;
        uri = URI;
        List<Element> temp = new ArrayList<Element>();
        temp.add(document);
        addToElements(temp);
        ignoreRoot = false;
    }

    @SuppressWarnings("unchecked")
    public Include(Element doc, String URI, boolean ignoreRoot) {
        document = doc;
        uri = URI;
        this.ignoreRoot = ignoreRoot;
        addToElements(document.getChildren());
    }

    @SuppressWarnings("unchecked")
    private void addToElements(List<Element> children) {
        elements.addAll(children);
        for (Element child : children) {
            addToElements(child.getChildren());
        }
    }

    @SuppressWarnings("unchecked")
    public Include(List<Element> list, String URI, boolean ignoreRoot) {
        document = list.get(0).getParentElement();
        uri = URI;
        this.ignoreRoot = ignoreRoot;
        addToElements(document.getChildren());
    }

    public Element getDocument() {
        return document;
    }

    public void setDocument(Element document) {
        this.document = document;
    }


    public boolean isIgnoreRoot() {
        return ignoreRoot;
    }

    public void setIgnoreRoot(boolean ignoreRoot) {
        this.ignoreRoot = ignoreRoot;
    }

    public String getUri() {
        return uri;
    }

    public void setUri(String uri) {
        this.uri = uri;
    }

    public boolean containsElement(Object object) {
        Element element = null;
        if (object instanceof Element) {
            element = (Element) object;
        } else if (object instanceof Attribute) {
            element = ((Attribute) object).getParent();
        }
        return element != null && elements.contains(element);
    }

    public boolean isRoot(Object element) {
        return (document.equals(element));
    }

    public Element toXML(String path) {
        Element incl = new Element("include", CAMConstants.CAMNamespace);
        if (ignoreRoot)
            incl.setAttribute("ignoreRoot", "yes");

        String text = getUri();
        String templatePath = new File(path).getParent();
        String includePath = null;

        if (getUri().startsWith("file:/")) {
            includePath = new File(getUri()).getParent();
        }

        if (!templatePath.equals(includePath)) {
            File includeFile = new File(getUri());
            if (includeFile.renameTo(new File(templatePath, includeFile.getName()))) {
                text = includeFile.getName();
            }


        }

        incl.setText(text);
        if (document.getAttribute("name") != null)
            incl.setAttribute("name", document.getAttributeValue("name"));
        return incl;
    }

}
