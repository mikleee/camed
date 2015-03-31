package com.aimprosoft.camed.model;

import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * @author mtkachenko.
 */
public class DecompiledCamTemplate {

    private List<Attribute> metaInfo;
    private List<Namespace> declaredNamespaces;
    private List<Element> compiledNamespaces;
    private Map<String, Element> structures;


    public List<Attribute> getMetaInfo() {
        return metaInfo;
    }

    public void setMetaInfo(List<Attribute> metaInfo) {
        this.metaInfo = metaInfo;
    }

    public List<Namespace> getDeclaredNamespaces() {
        return declaredNamespaces;
    }

    public void setDeclaredNamespaces(List<Namespace> declaredNamespaces) {
        this.declaredNamespaces = declaredNamespaces;
    }

    public List<Element> getCompiledNamespaces() {
        return compiledNamespaces;
    }

    public void setCompiledNamespaces(List<Element> compiledNamespaces) {
        this.compiledNamespaces = compiledNamespaces;
    }

    public Map<String, Element> getStructures() {
        return structures;
    }

    public void setStructures(Map<String, Element> structures) {
        this.structures = structures;
    }
}
