package com.aimprosoft.camed.compiler.xpath;

import net.sf.saxon.jdom.DocumentWrapper;
import net.sf.saxon.om.NodeInfo;
import net.sf.saxon.om.VirtualNode;
import net.sf.saxon.s9api.*;
import org.jdom.Content;
import org.jdom.Document;
import org.jdom.Namespace;

import java.util.ArrayList;
import java.util.List;

public class S9APIXpath {

    private XPathCompiler xpath;
    private Processor proc;
    private DocumentWrapper saxonDoc;
    private DocumentBuilder db;
    private XdmNode xdmDoc;

    public S9APIXpath(Document doc, String baseURI) {
        proc = new Processor(false);
        saxonDoc = new DocumentWrapper(doc, doc.getBaseURI(), proc.getUnderlyingConfiguration());
        db = proc.newDocumentBuilder();
        xdmDoc = db.wrap(saxonDoc);
        xpath = proc.newXPathCompiler();
    }


    public List<Content> selectNodes(String expr) throws SaxonApiException {
        XPathExecutable xx = xpath.compile(expr);
        XPathSelector selector = xx.load();
        selector.setContextItem(xdmDoc);
        List<Content> content = new ArrayList<Content>();
        for (XdmItem item : selector) {
            NodeInfo saxonNode = ((XdmNode) item).getUnderlyingNode();
            content.add((Content) ((VirtualNode) saxonNode).getUnderlyingNode());
        }
        return content;
    }

    public Content selectNode(String expr) throws SaxonApiException {
        XPathExecutable xx = xpath.compile(expr);
        XPathSelector selector = xx.load();
        selector.setContextItem(xdmDoc);
        List<Content> content = new ArrayList<Content>();
        for (XdmItem item : selector) {
            NodeInfo saxonNode = ((XdmNode) item).getUnderlyingNode();
            content.add((Content) ((VirtualNode) saxonNode).getUnderlyingNode());
        }
        if (content.size() > 1)
            return null;
        else
            return content.get(0);
    }

    public List<Namespace> getDocumentNamespaces() throws SaxonApiException {
        List<Namespace> nss = new ArrayList<Namespace>();
        XPathExecutable xx;
        xx = xpath.compile("in-scope-prefixes(/*)");
        XPathSelector selector = xx.load();
        selector.setContextItem(xdmDoc);
        for (XdmItem item : selector) {
            String prefix = item.getStringValue();
            String uri = getNamespaceFromPrefix(item.getStringValue());
            nss.add(Namespace.getNamespace(prefix, uri));
        }

        return nss;
    }

    public String getNamespaceFromPrefix(String prefix) throws SaxonApiException {

        XPathExecutable xx;
        xx = xpath.compile("namespace-uri-for-prefix('" + prefix + "',/*)");
        XPathSelector selector = xx.load();
        selector.setContextItem(xdmDoc);
        for (XdmItem item : selector) {
            return item.getStringValue();
        }
        return null;
    }

}
