package com.aimprosoft.camed.compiler.extensions;

import org.jdom.Element;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.lang.reflect.Constructor;
import java.util.Collection;
import java.util.HashMap;

/**
 * @author 802051682
 *
 */
public class AllowedExtensions {

	static Logger logger = LoggerFactory.getLogger(AllowedExtensions.class);

	static HashMap<String,IExtension> extensions = new HashMap<String, IExtension>();

	
	public static IExtension allocateExtension(String name,Element element){
		try {
			Class<?> cls = Class.forName(name);
			Class<?> partypes[] = new Class[1];
            partypes[0] = Element.class;
            Constructor<?> ct = cls.getConstructor(partypes);
			Object arglist[] = new Object[1];
			arglist[0] = element;
			Object retObj = ct.newInstance(arglist);
			if (retObj instanceof IExtension){
				extensions.put(name, (IExtension) retObj);
				return (IExtension) retObj;
			}
		} catch (Exception e) {
			logger.warn("Unable allocate extensions", e);
			return null;
		} 
		return null;
		
	}
	
	public static IExtension getExtension(String name){
		if (extensions.get(name) == null){
			return allocateExtension(name, null);
		}
		return extensions.get(name);
	}
	
	public static Collection<IExtension> getExtensions(){
		return extensions.values();
	}
	
	public static void dispose(){
		for (IExtension ext: getExtensions()){
			ext.dispose();
		}
	}
	
}
