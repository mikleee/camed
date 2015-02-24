package com.aimprosoft.camed.compiler.util;

import com.aimprosoft.camed.compiler.xpath.S9APIXpath;
import net.sf.saxon.s9api.SaxonApiException;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.Namespace;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.List;

public class Namespaces implements Cloneable{

	Logger logger = LoggerFactory.getLogger(this.getClass());
	
	private List<Namespace> NamespaceList = new ArrayList<Namespace>();
	
	S9APIXpath xpath = null;

	public Namespaces(Document doc) throws JDOMException {
		xpath = new S9APIXpath(doc,"");
		
		extractNamespaces(doc.getRootElement());
	}
	
	public Namespaces(Element elem) throws JDOMException {
		xpath = new S9APIXpath(elem.getDocument(),"");
		extractNamespaces(elem);
	}

	private void extractNamespaces(Element elem) {
		try {
			NamespaceList = xpath.getDocumentNamespaces();
		} catch (SaxonApiException e) {
			logger.error("System Error", e);
		}
	}


	public List<Namespace> getNamespaceList() {

		return NamespaceList;
	}


	@Override
	protected Object clone() throws CloneNotSupportedException {
		
		return super.clone();
	}

	
}
