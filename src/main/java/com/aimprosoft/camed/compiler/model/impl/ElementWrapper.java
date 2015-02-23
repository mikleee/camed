package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.model.Action;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.model.Rule;
import com.aimprosoft.camed.compiler.util.XPathFunctions;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import com.aimprosoft.camed.compiler.xpath.Xpath;
import org.apache.commons.lang.StringEscapeUtils;
import org.jaxen.JaxenException;
import org.jaxen.SimpleNamespaceContext;
import org.jdom.*;
import org.jdom.Attribute;
import org.jdom.adapters.JAXPDOMAdapter;

import java.util.*;


public class ElementWrapper implements Compilable {

    private final static String ELEMENT = "as:Element";
    private final static String ATTRIBUTE = "as:Attribute";

    private CAMTemplate template;
    private Element element;
    private List<Attribute> attributes;


    public ElementWrapper(Element element) {
        this(element, new ArrayList<Attribute>(), null);
    }

    public ElementWrapper(Element element, List<Attribute> attributes, CAMTemplate template) {
        this.element = element;
        this.template = template;
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

        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();
        List<Attribute> attributes = (List<Attribute>) element.getAttributes();
        List<Element> children = (List<Element>) element.getChildren();

        {
            List<Constraint> constraints = getConstraints(elementWrapper.getElement(), groupedConstraints);
            String compiledConstraints = compileConstraints(constraints);

            builder
                    .append("<" + ELEMENT + " ")
                    .append("name=" + QUOTE).append(elementWrapper.getElement().getQualifiedName()).append(QUOTE)
                    .append(compiledConstraints);  //todo
        }

        if (children.isEmpty() && attributes.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder.append(">").append("\n");

            for (Attribute attribute : attributes) {

                List<Constraint> constraints = getConstraints(attribute, groupedConstraints);
                String compiledConstraints = compileConstraints(constraints);

                builder
                        .append("<" + ATTRIBUTE + " ")
                        .append("name=" + QUOTE).append(attribute.getQualifiedName()).append(QUOTE)
                        .append(compiledConstraints)
                        .append("/>\n");

            }


            for (Element child : children) {

                List<Attribute> childAttributes = new ArrayList<Attribute>(); //todo
                ElementWrapper childWrapper = new ElementWrapper(child, childAttributes, template);
                childWrapper.compile(builder, childWrapper);
            }
            builder.append("</" + ELEMENT + ">\n");
        }

        return builder;


    }

    private StringBuilder compileAttributes(StringBuilder builder, List<Attribute> attributes) {
        for (Attribute attribute : attributes) {
            builder
                    .append(attribute.getQualifiedName())
                    .append(QUOTE)
                    .append(attribute.getValue())
                    .append(QUOTE + " ");
        }
        return builder;
    }

    private String nameToAttribute() {
        return "name=" + QUOTE + element.getQualifiedName() + QUOTE + " ";
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


    //todo==================-----------------------------------------------------------------------

    private String compileConstraints(List<Constraint> constraints) throws CAMCompilerException {
        if (constraints == null || constraints.isEmpty()) {
            return "";
        }

        StringBuilder builder = new StringBuilder();

        for (Constraint constraint : constraints) {
            builder.append(constraint.compile());
        }

        return builder.toString();
    }

    private List<Constraint> getConstraints(Element element, Map<String, List<Constraint>> groupedConstraints) throws CAMCompilerException {
        String currentXpath = XPathFunctions.fullXpathWithPosition(element);

        try {
            for (String boundXPath : groupedConstraints.keySet()) {

                if (boundXPath.contains("/@")) {
                    continue;
                }

                List<Element> matchedNodes = new JDOMXPathAdapter(boundXPath, template).selectNodes();

                for (Element matchedNode : matchedNodes) {

                    String xPathOfCandidate = XPathFunctions.fullXpathWithPosition(matchedNode);

                    if (currentXpath.equals(xPathOfCandidate)) {
                        return groupedConstraints.get(boundXPath);
                    }

                }

            }

            return null;
        } catch (JaxenException e) {
            throw new CAMCompilerException();
        }
    }

    private List<Constraint> getConstraints(Attribute attribute, Map<String, List<Constraint>> groupedConstraints) throws CAMCompilerException {
        for (String boundXPath : groupedConstraints.keySet()) {

            if (!boundXPath.contains("@" + attribute.getQualifiedName())) {
                continue;
            }

            String parentXpath = XPathFunctions.getParentXpath(boundXPath);
            if (isAttributeMapped(attribute, parentXpath)) {
                return groupedConstraints.get(boundXPath);
            }

        }
        return null;
    }

    private boolean isAttributeMapped(Attribute attribute, String parentXpath) throws CAMCompilerException {
        try {
            List<Element> matchedParentNodes = new JDOMXPathAdapter(parentXpath, template).selectNodes();

            if (parentXpath.equals("//UDBFile")) { // example "//@attr"
                for (Element matchedParentNode : matchedParentNodes) {
                    // if attr consist in one of children of  "UDBFile"
                    if (XPathFunctions.isAttributePresent(attribute, matchedParentNode)) {
                        return true;
                    }
                }
            } else {
                for (Element matchedParentNode : matchedParentNodes) {
                    // if attr consist in one of matched nodes
                    if (matchedParentNode.getAttribute(attribute.getQualifiedName()) != null) {
                        return true;
                    }
                }
            }

            return false;
        } catch (JaxenException e) {
            throw new CAMCompilerException(e.getMessage());
        }
    }


}
