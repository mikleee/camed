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

        builder.append("<").append(ELEMENT).append(" ");

        builder = compileAttributes(builder, elementWrapper.getAttributes());

        if (children.isEmpty() && attributes.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder.append(">").append("\n");

            for (Attribute attribute : attributes) {


                for (String xpath : groupedConstraints.keySet()) {

                }

                //todo link constraints

                List<Attribute> attributeList = initAttributes(attribute, new ArrayList<Attribute>());
                builder.append("<").append(ATTRIBUTE).append(" ");
                builder = compileAttributes(builder, attributeList);
                builder.append("/>").append("\n");
            }

            for (Element child : children) {
                List<Attribute> childAttributes = new ArrayList<Attribute>(); //todo
                ElementWrapper childWrapper = new ElementWrapper(child, childAttributes, template);
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
                    .append(QUOTE)
                    .append(attribute.getValue())
                    .append(QUOTE + " ");
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


    //todo==================-----------------------------------------------------------------------


    private String getConstraintString(Attribute attribute, Map<String, List<Constraint>> groupedConstraints) throws CAMCompilerException {
        try {
            for (String xpath : groupedConstraints.keySet()) {
                List<Element> matchedNodes = new JDOMXPathAdapter(xpath, template).selectNodes();


            }
            return null;
        } catch (JaxenException e) {
            throw new CAMCompilerException();
        }
    }

//    private boolean isRuleExists(String xPath) throws Exception {
//
//        Action action = ((Constraint) rule).getActions().get(0);
//        if (xPath.contains("[")) {
//            List<Element> nodes = new JDOMXPathAdapter(xPath, template).selectNodes();
//            for (Element node : nodes) {
//                if (getXpathRulesMap().containsKey(XPathFunctions.xpath(node))) {
//                    for (UUID uuid : getXpathRulesMap().get(XPathFunctions.xpath(node))) {
//                        if (((Constraint) getRuleMap().get(uuid)).getActions().get(0).equals(action))
//                            return true;
//                    }
//                }
//            }
//        } else {
//            if (getXpathRulesMap().containsKey(rule.getXpath())) {
//                for (UUID uuid : getXpathRulesMap().get(rule.getXpath())) {
//                    if (((Constraint) getRuleMap().get(uuid)).getActions().get(0).getAction().equals(action.getAction()))
//                        return true;
//                }
//            }
//        }
//
//        return false;
//    }

}
