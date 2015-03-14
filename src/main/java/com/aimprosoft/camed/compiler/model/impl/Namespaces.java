package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.model.Compilable;
import org.jdom.Namespace;

import java.util.HashMap;
import java.util.Map;

import static com.aimprosoft.camed.compiler.constants.CAMConstants.QUOTE;

/**
 * author m.tkachenko
 */
public class Namespaces implements Compilable {

    public Namespaces(Map<String, Namespace> namespacesMap) {
        this.namespacesMap = namespacesMap;
    }

    private Map<String, Namespace> namespacesMap = new HashMap<String, Namespace>();

    public Map<String, Namespace> getNamespacesMap() {
        return namespacesMap;
    }

    @Override
    public String compile() {
        StringBuilder builder = new StringBuilder("<as:Namespaces>\n");

        for (Namespace ns : namespacesMap.values()) {
            builder
                    .append("<as:namespace ")
                    .append("prefix=" + QUOTE)
                    .append(ns.getPrefix())
                    .append(QUOTE + ">")
                    .append(ns.getURI())
                    .append("</as:namespace>\n");
        }

        builder.append("</as:Namespaces>\n");
        return builder.toString();
    }
}
