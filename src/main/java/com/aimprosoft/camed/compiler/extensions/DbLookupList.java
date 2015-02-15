package com.aimprosoft.camed.compiler.extensions;

import org.jdom.Element;

public class DbLookupList implements ILookupList{
	
	private String name = null;
	private String value = null;

	public DbLookupList(String name, String value){
		this.name = name;
		this.value = value;
	}
	public DbLookupList(Element listElement) {
		name = listElement.getAttributeValue("name");
		value = listElement.getValue();
	}

	public String getName() {
		return name;
	}

	public String getValue() {
		return value;
	}
	
	public Element toXML(){
		Element element = new Element("DbLookupList",
				DbLookupLists.DbLookupListsNamespace);
		element.setAttribute("name", name);
		element.setText(value);
		return element;
	}
	
	public Element toCXF(){
		return toXML();
	}

	@Override
	public Element toDoc() {
		// TODO Auto-generated method stub
		return toXML();
	}

	public void setValue(String value) {
		this.value = value;
	}
}
