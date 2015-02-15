package com.aimprosoft.camed.compiler.extensions;

import java.util.Collection;

public interface ILookupLists {

	public Collection<ILookupList> getLists();
	public ILookupList put(String name, ILookupList list);
	public ILookupList get(String name);
	public ILookupList remove(String name);
}
