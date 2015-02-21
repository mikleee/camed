package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Compilable;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.*;
import org.jdom.Attribute;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public class ElementWrapper implements Compilable {

    private final static String ELEMENT = "as:Element";
    private final static String ATTRIBUTE = "as:Attribute";

    private Element element;
    private List<Attribute> attributes;


    public ElementWrapper(Element element) {
        this(element, new ArrayList<Attribute>());
    }

    public ElementWrapper(Element element, List<Attribute> attributes) {
        this.element = element;
        initAttributes(attributes);
    }


    @Override
    public String compile() throws CAMCompilerException {
        StringBuilder builder = new StringBuilder();
        return compile(builder, this).toString();
    }


    private void initAttributes(List<Attribute> attributes) {
        this.attributes = new ArrayList<Attribute>();
        String name = StringEscapeUtils.escapeXml(element.getQualifiedName());
        this.attributes.add(new Attribute("name", name));
        this.attributes.addAll(attributes);
    }

    private List<Attribute> initAttributes(Attribute attribute, List<Attribute> attributes) {
        List<Attribute> result = new ArrayList<Attribute>();
        String name = StringEscapeUtils.escapeXml(attribute.getQualifiedName());
        result.add(new Attribute("name", name));
        result.addAll(attributes);
        return result;
    }

    private StringBuilder compile(StringBuilder builder, ElementWrapper elementWrapper) throws CAMCompilerException {

        List<Attribute> attributes = (List<Attribute>) element.getAttributes();
        List<Element> children = (List<Element>) element.getChildren();

        builder.append("<").append(ELEMENT).append(" ");

        builder = compileAttributes(builder, elementWrapper.getAttributes());

        if (children.isEmpty() && attributes.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder.append(">").append("\n");

            for (Attribute attribute : attributes) {
                List<Attribute> attributeList = initAttributes(attribute, new ArrayList<Attribute>());
                builder.append("<").append(ATTRIBUTE).append(" ");
                builder = compileAttributes(builder, attributeList);
                builder.append("/>").append("\n");
            }

            for (Element child : children) {
                List<Attribute> childAttributes = new ArrayList<Attribute>(); //todo
                ElementWrapper childWrapper = new ElementWrapper(child, childAttributes);
                childWrapper.compile(builder, childWrapper);
            }
            builder.append("</").append(ELEMENT).append(">").append("\n");
        }

        return builder;
    }

    private StringBuilder compileAttributes(StringBuilder builder, List<Attribute> attributes) {
        for (Attribute attribute : attributes) {
            builder
                    .append(attribute.getQualifiedName())
                    .append("=\"")
                    .append(attribute.getValue())
                    .append("\" ");
        }
        return builder;
    }

    public Element getElement() {
        return element;
    }

    public void setElement(Element element) {
        this.element = element;
    }

    public List<Attribute> getAttributes() {
        return attributes;
    }

    public void setAttributes(List<Attribute> attributes) {
        this.attributes = attributes;
    }

}
