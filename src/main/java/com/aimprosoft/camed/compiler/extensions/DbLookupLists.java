package com.aimprosoft.camed.compiler.extensions;

import java.util.Collection;
import java.util.HashMap;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Element;
import org.jdom.Namespace;

public class DbLookupLists implements IExtension, ILookupLists {

	public static final String name = "com.aimprosoft.camed.compiler.extensions.DbLookupLists";
	public static final Namespace DbLookupListsNamespace = Namespace
			.getNamespace("dblook", "http://jcam.org.uk/DbLookupLists");
	private static HashMap<String, ILookupList> lists = new HashMap<String, ILookupList>();
	private Element extension = null;
	//private String filename = null;

	public DbLookupLists(Element element) {
		this.extension = element;
/*		Include include = CAMEditor.getTemplate().getInclude(element);
		if (include != null) {
			filename = include.getUri();
		}*/
		convertElementtoDbLookupLists(element);
	}

	private void convertElementtoDbLookupLists(Element element) {
		if (element != null && element.getChildren() != null) {
			for (Object child : element.getChildren()) {
				DbLookupList dblist = new DbLookupList((Element) child);
				lists.put(dblist.getName(), dblist);
			}
		}
	}

	@Override
	public String getName() {
		return name;
	}

	@Override
	public Element getExtension() {
		return extension;
	}

	@Override
	public Element toXML() {
		Element extension = new Element("Extension", CAMConstants.CAMNamespace);
		extension.setAttribute("name", name);
		for (ILookupList list: lists.values()){
			Element elem = list.toXML();
			if (elem != null)
				extension.addContent(elem);
		}
		return extension.getChildren().size() > 0?extension:null;
	}

	@Override
	public Element toDoc() {
		return toXML();
	}

	@Override
	public Element toCXF() {
		return toXML();
	}

	@Override
	public void dispose() {
		// TODO Auto-generated method stub

	}
	
	public ILookupList put(String name, ILookupList list) {
		return lists.put(name, list);
	}

	public  Collection<ILookupList> getLists() {	
		return lists.values();
	}

	public ILookupList get(String name) {
		return lists.get(name);
	}

	public ILookupList remove(String name) {
		return lists.remove(name);
	}

}
