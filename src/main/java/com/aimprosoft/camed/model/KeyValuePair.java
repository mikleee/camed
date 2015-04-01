package com.aimprosoft.camed.model;

import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.Namespace;

public class KeyValuePair {

    private String key;
    private String value;

    public KeyValuePair(Element element) {
        this.key = element.getQualifiedName();
        this.value = element.getValue();
    }

    public KeyValuePair(Namespace namespace) {
        this.key = namespace.getPrefix();
        this.value = namespace.getURI();
    }



    public KeyValuePair(Attribute attribute) {
        this.key = attribute.getQualifiedName();
        this.value = attribute.getValue();
    }


    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
}
