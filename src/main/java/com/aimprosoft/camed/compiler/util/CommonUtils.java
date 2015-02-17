package com.aimprosoft.camed.compiler.util;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author mtkachenko.
 */
public class CommonUtils {

    public static String getFileSeparator(){
        return System.getProperty("file.separator");
    }

    public static void closeQuietly(AutoCloseable... streams) {
        for (AutoCloseable stream : streams) {
            if (stream != null) {
                try {
                    stream.close();
                } catch (Exception e) {
                    //ignore
                }
            }
        }
    }

    public static Set<Namespace> retrieveNamespaces(Element element){
        Set<Namespace> result = new HashSet<Namespace>();
        populateNamespaceList(element, result);
        return result;
    }

    public static Set<Namespace> retrieveNamespaces(Document document){
        return retrieveNamespaces(document.getRootElement());
    }

    private static void populateNamespaceList(Element element, Set<Namespace> result) {
        Namespace namespace = element.getNamespace();
        result.add(namespace);

        List children = element.getChildren();

        if (!children.isEmpty()) {
            for (Element child : (List<Element>) children) {
                populateNamespaceList(child, result);
            }
        }
    }

}
