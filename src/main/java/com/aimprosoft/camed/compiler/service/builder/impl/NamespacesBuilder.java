package com.aimprosoft.camed.compiler.service.builder.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.impl.CamTemplate;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.service.builder.ElementBuilder;
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
    public Namespaces build() throws CAMCompilerException {
        Map<String, Namespace> map = new HashMap<String, Namespace>();

        for (Namespace ns : retrieveNamespaces()) {
            map.put(ns.getPrefix(), ns);
        }

        return new Namespaces(map);
    }

    private Set<Namespace> retrieveNamespaces() {
        Set<Namespace> result = new HashSet<Namespace>();
        result.add(CAMConstants.XML_NAMESPACE);
        populateNamespaceList(element, result);
        return result;
    }

    private void populateNamespaceList(Element element, Set<Namespace> result) {
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
