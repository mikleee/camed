package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.constants.CAMElementType;
import org.jdom.Attribute;
import org.jdom.Element;

/**
 * author m.tkachenko
 */
public class CAMElement {

    private CAMElementType type;
    private Element element;
    private Attribute attribute;

    public CAMElement(Object element) {
        if (element instanceof Element) {
            this.element = (Element) element;
            this.type = CAMElementType.ELEMENT;
        } else if (element instanceof Attribute) {
            this.attribute = (Attribute) element;
            this.type = CAMElementType.ATTRIBUTE;
        }
    }


    public String getElementName() {
        return type.getName();
    }

    public String getNameAttributeValue() {
        if (type == CAMElementType.ELEMENT) {
            return element.getQualifiedName();
        } else {
            return attribute.getQualifiedName();
        }
    }


}
