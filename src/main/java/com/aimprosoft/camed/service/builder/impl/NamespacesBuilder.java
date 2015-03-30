package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.CamConstants;
import com.aimprosoft.camed.model.Compilable;
import com.aimprosoft.camed.model.impl.CamTemplate;
import com.aimprosoft.camed.model.impl.Namespaces;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.*;

/**
 * @author mtkachenko.
 */
public class NamespacesBuilder implements ElementBuilder<Compilable> {

    private Element element;

    public NamespacesBuilder(CamTemplate template) {
        element = template.getTemplateDocument().getRootElement();
    }

    @Override
    public Namespaces build() throws CamException {
        Map<String, Namespace> map = new HashMap<String, Namespace>();

        for (Namespace ns : retrieveNamespaces()) {
            map.put(ns.getPrefix(), ns);
        }

        return new Namespaces(map);
    }

    private Set<Namespace> retrieveNamespaces() {
        Set<Namespace> result = new HashSet<Namespace>();
        result.add(CamConstants.XML_NAMESPACE);
        populateNamespaceList(element, result);
        return result;
    }

    public static void populateNamespaceList(Element element, Collection<Namespace> result) {
        Namespace namespace = element.getNamespace();

        if (!namespace.getPrefix().isEmpty()) {
            result.add(namespace);
        }

        //noinspection unchecked
        for (Namespace additionalNamespace : (List<Namespace>) element.getAdditionalNamespaces()) {
            result.add(additionalNamespace);
        }

        //noinspection unchecked
        for (Element child : (List<Element>) element.getChildren()) {
            populateNamespaceList(child, result);
        }

    }
}
