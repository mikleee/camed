package com.aimprosoft.camed.compiler.extensions;

import org.jdom.Element;

public interface ILookupList {

	public String getName();
	
	public Element toXML();
	
	public Element toDoc();
	
	public Element toCXF();
}
