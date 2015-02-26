package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Header;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.model.impl.Structure;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
import com.aimprosoft.camed.compiler.service.ModelFactory;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
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
        initStructure();
        initNamespaces(); //2
        initHeader(); //3
        initConstraintManager();
        return template;
    }

    private void init(Document document) {
        template = new CAMTemplate(document);
    }

    private void initHeader() throws CAMCompilerException {
        Element headerNode = JDOMXPathAdapter.newInstance(HEADER_XPATH, template).selectNode();
        Header header = headerNode == null ? null : new Header(headerNode);
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

//    private void initStructure() throws CAMCompilerException {
//        Element structureNode = JDOMXPathAdapter.newInstance(STRUCTURE_XPATH, template).selectNode();
//        Structure structure = ModelFactory.createStructure(structureNode, template); //todo
//        template.setStructure(structure);
//    }

    private void initStructure() throws CAMCompilerException {
        Element structureNode = template.getTemplateDocument().getRootElement()
                .getChild("AssemblyStructure", CAMConstants.CAM_NAMESPACE)
                .getChild("Structure", CAMConstants.CAM_NAMESPACE);
        Structure structure = ModelFactory.createStructure(structureNode, template); //todo
        template.setStructure(structure);
    }

    private void initConstraintManager() throws CAMCompilerException {
        template.setConstraintManager(new ConstraintManager(template));
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