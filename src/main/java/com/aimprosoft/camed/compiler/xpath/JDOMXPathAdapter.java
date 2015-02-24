package com.aimprosoft.camed.compiler.xpath;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jaxen.JaxenException;
import org.jaxen.SimpleNamespaceContext;
import org.jaxen.jdom.JDOMXPath;
import org.jdom.Attribute;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.List;
import java.util.Map;

/**
 * author m.tkachenko
 */
public class JDOMXPathAdapter extends JDOMXPath {

    private Document document;
    private String xPath;

    public JDOMXPathAdapter(String xpathExpr) throws JaxenException {
        super(xpathExpr);
    }

    public JDOMXPathAdapter(String xpathExpr, CAMTemplate camTemplate) throws JaxenException {
        this(xpathExpr);
        this.document = camTemplate.getTemplateDocument();
        initNamespaceContext(camTemplate);
    }

    public static JDOMXPathAdapter newInstance(String xpathExpr, CAMTemplate camTemplate) throws CAMCompilerException {
        try {
            return new JDOMXPathAdapter(xpathExpr, camTemplate);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Can not parse xPath expression: " + xpathExpr);
        }
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
    public List<Element> selectNodes() throws CAMCompilerException {
        try {
            return (List<Element>) super.selectNodes(document);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Can not find element by xPath expression: " + toString());
        }
    }

    @SuppressWarnings("unchecked")
    public List<Attribute> selectAttributes() throws CAMCompilerException {
        try {
            return (List<Attribute>) super.selectNodes(document);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Can not find attributes by xPath expression: " + toString());
        }
    }

    public Element selectNode() throws CAMCompilerException {
        try {
            return (Element) super.selectSingleNode(document);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Can not find element by xPath expression: " + toString());
        }
    }

    public Attribute selectAttribute() throws CAMCompilerException {
        try {
            return (Attribute) super.selectSingleNode(document);
        } catch (JaxenException e) {
            throw new CAMCompilerException("Can not find attribute by xPath expression: " + toString());
        }
    }
}
