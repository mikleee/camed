package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.model.Structure;
import com.aimprosoft.camed.compiler.model.impl.Header;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
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

    private final static String HEADER_XPATH = "/as:CAM/as:Header";
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

    private void initHeader() throws CAMCompilerException {
        Element headerNode = retrieveTemplateNode(HEADER_XPATH);
        Header header = new Header(headerNode);
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
        Element structureNode = retrieveTemplateNode(STRUCTURE_XPATH);
        Structure structure = ModelFactory.createStructure(structureNode, template); //todo
        template.setStructure(structure);
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

    private Element retrieveTemplateNode(String xPath) throws CAMCompilerException {
        try {
            JDOMXPathAdapter jdomxPathAdapter = new JDOMXPathAdapter(STRUCTURE_XPATH, template);
            return jdomxPathAdapter.selectNode();
        } catch (JaxenException e) {
            throw new CAMCompilerException("Element " + STRUCTURE_XPATH + " is absent.");
        }

    }

}