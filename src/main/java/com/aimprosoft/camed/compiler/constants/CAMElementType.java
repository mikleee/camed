package com.aimprosoft.camed.compiler.constants;

/**
 * author m.tkachenko
 */
public enum CAMElementType {

    ATTRIBUTE("as:Attribute"),
    ELEMENT("as:Element");

    private String name;

    CAMElementType(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
