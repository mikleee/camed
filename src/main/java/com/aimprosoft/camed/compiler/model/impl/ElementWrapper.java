package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Compilable;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.*;
import org.jdom.Attribute;

import java.util.ArrayList;
import java.util.List;


public class ElementWrapper implements Compilable {

//    private String name;
//    private String path;
//    private String namespace;

    private Element element;
    private List<Attribute> attributes;


    public ElementWrapper(Element element) {
        this(element, new ArrayList<Attribute>());
    }

    public ElementWrapper(Element element, List<Attribute> attributes) {
        this.element = element;
        this.attributes = attributes;
        init();
    }


    @Override
    public String compile() throws CAMCompilerException {
        StringBuilder builder = new StringBuilder();
        return compile(builder).toString();
    }


    private void init() {
        String name = StringEscapeUtils.escapeXml(element.getQualifiedName());
        attributes.add(new Attribute("name", name));
    }

    private StringBuilder compile(StringBuilder builder) throws CAMCompilerException {

        String namespacePrefix = element.getNamespace().getPrefix();
        String elementName = element.getQualifiedName();

        builder.append("<").append(namespacePrefix).append(elementName);

        builder = compileAttributes(builder);

        List<Element> children = (List<Element>) element.getChildren();

        if (children.isEmpty()) {
            builder.append("/>");
        } else {
            for (Element child : children) {
                compile(builder);
            }
            builder.append("</").append(namespacePrefix).append(elementName);
        }

        return builder;
    }

    private StringBuilder compileAttributes(StringBuilder builder) {
        for (Attribute attribute : attributes) {
            builder
                    .append(attribute.getQualifiedName())
                    .append("=\"")
                    .append(attribute.getValue())
                    .append("\" ");
        }
        return builder;
    }


    public org.jdom.Element getElement() {
        return element;
    }

    public void setElement(org.jdom.Element element) {
        this.element = element;
    }

    public List<Attribute> getAttributes() {
        return attributes;
    }

    public void setAttributes(List<Attribute> attributes) {
        this.attributes = attributes;
    }

}
