package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.model.impl.AssemblyStructure;
import com.aimprosoft.camed.compiler.model.impl.Header;
import com.aimprosoft.camed.compiler.model.impl.Namespaces;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
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

    private CAMTemplate template;

    public CAMTemplateBuilder(Document document) {
        init(document); //1
    }

    @Override
    public CAMTemplate build() {
        initNamespaces(); //2
        initHeader(); //3
        initStructures();
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

        Namespaces namespaces =  new Namespaces(map);
        template.setNamespaces(namespaces);
    }


    private void initStructures() {
        try {
            JDOMXPathAdapter assemblyStructurePath = new JDOMXPathAdapter("//as:AssemblyStructure/as:Structure", template);
            List<Structure> list = new ArrayList<Structure>();
            for (Element structure : assemblyStructurePath.selectNodes()) {
                //AddStructureToTemplate(structure, template);
            }
            AssemblyStructure assemblyStructure = new AssemblyStructure(list);
            template.setAssemblyStructure(assemblyStructure );
        } catch (JaxenException e) {
            e.printStackTrace(); //todo
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