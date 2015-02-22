package com.aimprosoft.camed.compiler.xpath;

import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jaxen.JaxenException;
import org.jaxen.SimpleNamespaceContext;
import org.jaxen.jdom.JDOMXPath;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * author m.tkachenko
 */
public class JDOMXPathAdapter extends JDOMXPath {

    private Document document;

    public JDOMXPathAdapter(String xpathExpr) throws JaxenException {
        super(xpathExpr);
    }

    public JDOMXPathAdapter(String xpathExpr, CAMTemplate camTemplate) throws JaxenException {
        this(xpathExpr);
        this.document = camTemplate.getTemplateDocument();
        initNamespaceContext(camTemplate);
    }

    private void initNamespaceContext(CAMTemplate camTemplate) {
        SimpleNamespaceContext result = new SimpleNamespaceContext();

        Map<String, Namespace> namespaceMap = camTemplate.getNamespaces().getNamespacesMap();
        for (String key : namespaceMap.keySet()) {
            Namespace namespace = namespaceMap.get(key);
            result.addNamespace(namespace.getPrefix(), namespace.getURI());
        }

        setNamespaceContext(result);
    }

    @SuppressWarnings("unchecked")
    public List<Element> selectNodes() throws JaxenException {
        return (ArrayList<Element>) super.selectNodes(document);
    }

    public Element selectNode() throws JaxenException {
        return (Element) super.selectSingleNode(document);
    }
}
