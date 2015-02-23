package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.service.StructureConstraintBridge;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.List;


public class ElementWrapper implements Compilable {

    private CAMTemplate template;
    private Element element;
    private List<Attribute> attributes;
    private List<Element> children;


    @SuppressWarnings("unchecked")
    public ElementWrapper(Element element, CAMTemplate template) {
        this.attributes = (List<Attribute>) element.getAttributes();
        this.children = (List<Element>) element.getChildren();
        this.template = template;
        this.element = element;
    }


    @Override
    public String compile() throws CAMCompilerException {
        StringBuilder builder = new StringBuilder();
        return compile(builder, this).toString();
    }


    private StringBuilder compile(StringBuilder builder, ElementWrapper elementWrapper) throws CAMCompilerException {
        builder
                .append("<" + ELEMENT + " ")
                .append(populateElement(elementWrapper));

        if (elementWrapper.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder
                    .append(">").append("\n")
                    .append(populateAttributes(elementWrapper))
                    .append(populateChildren(elementWrapper, builder))
                    .append("</" + ELEMENT + ">\n");
        }

        return builder;
    }

    private StringBuilder populateElement(ElementWrapper elementWrapper) throws CAMCompilerException {
        List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(elementWrapper.getElement(), template);
        String compiledConstraints = compileConstraints(constraints);

        return new StringBuilder()
                .append("name=" + QUOTE).append(elementWrapper.getElement().getQualifiedName()).append(QUOTE)
                .append(compiledConstraints);
    }

    private StringBuilder populateAttributes(ElementWrapper elementWrapper) throws CAMCompilerException {
        StringBuilder builder = new StringBuilder();

        for (Attribute attribute : elementWrapper.getAttributes()) {
            List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(attribute, template);
            String compiledConstraints = compileConstraints(constraints);

            builder.append("<" + ATTRIBUTE + " ")
                    .append("name=" + QUOTE).append(attribute.getQualifiedName()).append(QUOTE)
                    .append(compiledConstraints)
                    .append("/>\n");
        }

        return builder;
    }

    private StringBuilder populateChildren(ElementWrapper elementWrapper, StringBuilder builder) throws CAMCompilerException {
        for (Element child : elementWrapper.getChildren()) {
            ElementWrapper childWrapper = new ElementWrapper(child, template);
            childWrapper.compile(builder, childWrapper);
        }
        return builder;
    }

    private String compileConstraints(List<Constraint> constraints) throws CAMCompilerException {
        if (constraints == null || constraints.isEmpty()) {
            return " makeMandatory=" + QUOTE + "true" + QUOTE + " ";
        }

        StringBuilder builder = new StringBuilder();

        for (Constraint constraint : constraints) {
            builder.append(constraint.compile());
        }

        return builder.toString();
    }

    private boolean isEmpty() {
        return getAttributes().isEmpty() && getChildren().isEmpty();
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

    public List<Element> getChildren() {
        return children;
    }

}
