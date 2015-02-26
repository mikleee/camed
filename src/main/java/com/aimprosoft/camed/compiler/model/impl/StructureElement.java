package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.service.StructureConstraintBridge;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.List;


public class StructureElement implements Compilable {

    private CAMTemplate template;
    private Element element;
    private List<Attribute> attributes;
    private List<Element> children;


    @SuppressWarnings("unchecked")
    public StructureElement(Element element, CAMTemplate template) {
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


    private StringBuilder compile(StringBuilder builder, StructureElement structureElement) throws CAMCompilerException {
        builder
                .append("<" + CAMConstants.ELEMENT + " ")
                .append(populateElement(structureElement));

        if (structureElement.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder
                    .append(">").append("\n")
                    .append(populateAttributes(structureElement));

            builder = populateChildren(structureElement, builder)
                    .append("</" + CAMConstants.ELEMENT + ">\n");
        }

        return builder;
    }

    private StringBuilder populateElement(StructureElement structureElement) throws CAMCompilerException {
        List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(structureElement.getElement(), template);
        String compiledConstraints = compileConstraints(constraints);

        return new StringBuilder()
                .append("name=" + CAMConstants.QUOTE).append(structureElement.getElement().getQualifiedName()).append(CAMConstants.QUOTE)
                .append(compiledConstraints);
    }

    private StringBuilder populateAttributes(StructureElement structureElement) throws CAMCompilerException {
        StringBuilder builder = new StringBuilder();

        for (Attribute attribute : structureElement.getAttributes()) {
            List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(attribute, template);
            String compiledConstraints = compileConstraints(constraints);

            builder.append("<" + CAMConstants.ATTRIBUTE + " ")
                    .append("name=" + CAMConstants.QUOTE).append(attribute.getQualifiedName()).append(CAMConstants.QUOTE)
                    .append(compiledConstraints)
                    .append("/>\n");
        }

        return builder;
    }

    private StringBuilder populateChildren(StructureElement structureElement, StringBuilder builder) throws CAMCompilerException {
        for (Element child : structureElement.getChildren()) {
            StructureElement childWrapper = new StructureElement(child, template);
            childWrapper.compile(builder, childWrapper);
        }
        return builder;
    }

    private String compileConstraints(List<Constraint> constraints) throws CAMCompilerException {
        if (constraints == null || constraints.isEmpty()) {
            return " " + ActionType.makeMandatory + "=" + CAMConstants.QUOTE + "true" + CAMConstants.QUOTE + " "; //todo
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
