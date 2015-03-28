package com.aimprosoft.camed.model;

import com.aimprosoft.camed.model.impl.Header;
import com.aimprosoft.camed.model.impl.Namespaces;
import org.jdom.Element;

import java.util.Map;

/**
 * @author mtkachenko.
 */
public class DecompiledCamTemplate {

    private Header header;
    private Namespaces namespaces;

    private Map<String, Element> structures;

    public Header getHeader() {
        return header;
    }

    public void setHeader(Header header) {
        this.header = header;
    }

    public Namespaces getNamespaces() {
        return namespaces;
    }

    public void setNamespaces(Namespaces namespaces) {
        this.namespaces = namespaces;
    }

    public Map<String, Element> getStructures() {
        return structures;
    }

    public void setStructures(Map<String, Element> structures) {
        this.structures = structures;
    }
}
