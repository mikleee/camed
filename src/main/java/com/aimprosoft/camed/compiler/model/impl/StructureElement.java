package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.service.compiler.StructureConstraintBridge;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.List;

import static com.aimprosoft.camed.compiler.constants.CamConstants.QUOTE;


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
    public String compile() throws CamException {
        StringBuilder builder = new StringBuilder();
        return compile(builder, this).toString();
    }


    private StringBuilder compile(StringBuilder builder, StructureElement structureElement) throws CamException {
        builder
                .append("<as:Element ")
                .append(populateElement(structureElement));

        if (structureElement.isEmpty()) {
            builder.append("/>").append("\n");
        } else {
            builder
                    .append(">").append("\n")
                    .append(populateAttributes(structureElement));

            builder = populateChildren(structureElement, builder)
                    .append("</as:Element>\n");
        }

        return builder;
    }

    private StringBuilder populateElement(StructureElement structureElement) throws CamException {
        List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(structureElement.getElement(), template);
        String compiledConstraints = compileConstraints(constraints, element);

        return new StringBuilder()
                .append("name=" + QUOTE).append(structureElement.getElement().getQualifiedName()).append(QUOTE)
                .append(compiledConstraints);
    }

    private StringBuilder populateAttributes(StructureElement structureElement) throws CamException {
        StringBuilder builder = new StringBuilder();

        for (Attribute attribute : structureElement.getAttributes()) {
            List<Constraint> constraints = StructureConstraintBridge.getInstance().findNodeConstraints(attribute, template);
            String compiledConstraints = compileConstraints(constraints);

            builder.append("<as:Attribute ")
                    .append("name=" + QUOTE).append(attribute.getQualifiedName()).append(QUOTE)
                    .append(compiledConstraints)
                    .append("/>\n");
        }

        return builder;
    }

    private StringBuilder populateChildren(StructureElement structureElement, StringBuilder builder) throws CamException {
        for (Element child : structureElement.getChildren()) {
            StructureElement childWrapper = new StructureElement(child, template);
            childWrapper.compile(builder, childWrapper);
        }
        return builder;
    }

    private String compileConstraints(List<Constraint> constraints, Element element) throws CamException {
        String additionalConstraints = "";
        String elementText = element.getTextTrim();
        if (element.getChildren().size() == 0 && !elementText.endsWith("%") && !elementText.endsWith("%")) {
            additionalConstraints = " " + ActionType.setValue + "=" + QUOTE + QUOTE + " ";
        }
        return additionalConstraints + compileConstraints(constraints);
    }

    private String compileConstraints(List<Constraint> constraints) throws CamException {
        if (constraints == null || constraints.isEmpty()) {
            return " " + ActionType.makeMandatory + "=" + QUOTE + "true" + QUOTE + " "; //todo
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
