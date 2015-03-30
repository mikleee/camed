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
    private Set<Namespace> namespaces;
    private Map<String, Element> structures;


    public List<Attribute> getMetaInfo() {
        return metaInfo;
    }

    public void setMetaInfo(List<Attribute> metaInfo) {
        this.metaInfo = metaInfo;
    }

    public Set<Namespace> getNamespaces() {
        return namespaces;
    }

    public void setNamespaces(Set<Namespace> namespaces) {
        this.namespaces = namespaces;
    }

    public Map<String, Element> getStructures() {
        return structures;
    }

    public void setStructures(Map<String, Element> structures) {
        this.structures = structures;
    }
}
