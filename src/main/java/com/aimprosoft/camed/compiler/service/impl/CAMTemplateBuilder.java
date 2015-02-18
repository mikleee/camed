package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.model.impl.Header;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.service.*;
import com.aimprosoft.camed.compiler.service.ModelFactory;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jaxen.JaxenException;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.*;

/**
 * author m.tkachenko
 */
public class CAMTemplateBuilder implements ElementBuilder {

    private final static String STRUCTURE_XPATH = "//as:AssemblyStructure/as:Structure";

    private CAMTemplate template;

    public CAMTemplateBuilder(Document document) {
        init(document); //1
    }

    @Override
    public CAMTemplate build() throws CAMCompilerException {
        initNamespaces(); //2
        initHeader(); //3
        initStructure();
        return template;
    }

    private void init(Document document) {
        template = new CAMTemplate(document);
    }

    private void initHeader() {
        final Namespace as = template.getNamespacesMap().get(CAMConstants.CAM_NAMESPACE_PREFIX);
        Element headerNode = template.getTemplateDocument().getRootElement().getChild("Header", as);

        String description = headerNode.getChildText("Description", as);
        String owner = headerNode.getChildText("Owner", as);
        String templateVersion = headerNode.getChildText("Version", as);

        Header header = new Header(description, owner, templateVersion);
        template.setHeader(header);
    }

    public void initNamespaces() {
        Map<String, Namespace> map = new HashMap<String, Namespace>();

        for (Namespace ns : retrieveNamespaces()) {
            map.put(ns.getPrefix(), ns);
        }

        Namespaces namespaces = new Namespaces(map);
        template.setNamespaces(namespaces);
    }


    private void initStructure() throws CAMCompilerException {
        try {
            JDOMXPathAdapter jdomxPathAdapter = new JDOMXPathAdapter(STRUCTURE_XPATH, template);
            Element structureNode = jdomxPathAdapter.selectNode();
            Structure structure = ModelFactory.createStructureBuilder(structureNode); //todo
            template.setStructure(structure);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Element " + STRUCTURE_XPATH + " is absent.");
        }
    }


    private Set<Namespace> retrieveNamespaces() {
        Set<Namespace> result = new HashSet<Namespace>();
        Element root = template.getTemplateDocument().getRootElement();
        populateNamespaceList(root, result);
        return result;
    }

    private void populateNamespaceList(Element element, Set<Namespace> result) {
        Namespace namespace = element.getNamespace();

        if (!namespace.getPrefix().isEmpty()) {
            result.add(namespace);
        }

        List children = element.getChildren();

        if (!children.isEmpty()) {
            for (Element child : (List<Element>) children) {
                populateNamespaceList(child, result);
            }
        }
    }


}