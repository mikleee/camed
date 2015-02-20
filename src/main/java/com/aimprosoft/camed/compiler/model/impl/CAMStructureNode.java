package com.aimprosoft.camed.compiler.model.impl;

import org.jdom.Attribute;

import java.util.List;

/**
 * author m.tkachenko
 */
public abstract class CAMStructureNode {

    private List<Attribute> attributes;

    public List<Attribute> getAttributes() {
        return attributes;
    }

    public void setAttributes(List<Attribute> attributes) {
        this.attributes = attributes;
    }
}
