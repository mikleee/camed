package org.jdom.output;

import java.io.Serializable;
import java.util.Comparator;

import org.jdom.Namespace;

public class NamespaceComparator implements Comparator<Namespace>, Serializable {

	private static final long serialVersionUID = 1L;

	@Override
	public int compare(Namespace ns1, Namespace ns2) {
		return ns1.getPrefix().compareToIgnoreCase(ns2.getPrefix());
	}

}
