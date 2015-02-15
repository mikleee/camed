package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Element;

public class Property {

    private String name = null;
    private String value = null;

    public Property(String name, String value) {
        this.name = name;
        this.value = value;
    }

    @Override
    public String toString() {
        return name + "=" + value;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public Element toXML() {
        Element prop = new Element("Property", CAMConstants.CAMNamespace);
        prop.setAttribute("name", name);
        prop.setAttribute("value", value);
        return prop;
    }

}
