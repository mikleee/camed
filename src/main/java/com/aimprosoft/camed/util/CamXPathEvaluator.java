package com.aimprosoft.camed.util;

import net.sf.saxon.xpath.XPathEvaluator;
import org.jdom.Element;
import org.jdom.Namespace;
import org.jdom.output.XMLOutputter;
import org.xml.sax.InputSource;

import javax.xml.namespace.NamespaceContext;
import javax.xml.xpath.XPathExpressionException;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.Map;

public class CamXPathEvaluator {
    private ByteArrayOutputStream out = null;
    private XPathEvaluator eval = null;
    private InputSource inputSource = null;
    private ByteArrayInputStream input = null;
    private Map<String, Namespace> namespacesMap = null;

    public CamXPathEvaluator(Element node, Map<String, Namespace> namespacesMap) throws IOException {
        this.out = new ByteArrayOutputStream();
        XMLOutputter xmlOut = new XMLOutputter();
        xmlOut.output(node, out);
        this.eval = new XPathEvaluator();
        this.eval.setNamespaceContext(new CamNamspaceContext());
        this.input = new ByteArrayInputStream(out.toByteArray());
        this.inputSource = new InputSource(input);
        this.namespacesMap = namespacesMap;
    }

    public String evaluate(String expression) throws XPathExpressionException {
        input.reset();
        return eval.evaluate(expression, inputSource);
    }

    public void close() throws IOException {
        out.close();
        input.close();
    }

    /* (non-Javadoc)
     * @see java.lang.Object#finalize()
     */
    @Override
    protected void finalize() throws Throwable {
        out.close();
        input.close();
        super.finalize();
    }

    private class CamNamspaceContext implements NamespaceContext {

        @Override
        public String getNamespaceURI(String prefix) {
            return namespacesMap.get(prefix).getURI();
        }

        @Override
        public String getPrefix(String namespaceURI) {
            return null;
        }

        @Override
        public Iterator<?> getPrefixes(String namespaceURI) {
            return namespacesMap.keySet().iterator();
        }

    }

}