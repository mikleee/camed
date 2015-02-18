package com.aimprosoft.camed.compiler.util;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.*;

/**
 * @author mtkachenko.
 */
public class CommonUtils {

    public static String getFileSeparator() {
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

    public static Set<Namespace> retrieveNamespaces(Element element) {
        Set<Namespace> result = new HashSet<Namespace>();
        populateNamespaceList(element, result);
        return result;
    }

    public static Set<Namespace> retrieveNamespaces(Document document) {
        return retrieveNamespaces(document.getRootElement());
    }

    private static void populateNamespaceList(Element element, Set<Namespace> result) {
        Namespace namespace = element.getNamespace();

        if (!namespace.getPrefix().isEmpty()) {
            result.add(namespace);
        }

        List children = element.getChildren();

        if (!children.isEmpty()) {
            for (Element child : (List<Element>) children) {
                populateNamespaceList(child, result);
            }
        }
    }

    public static String generateTempFileName(String root) {
        Random generator = new Random(System.currentTimeMillis());
        int rand = generator.nextInt();
//        return root + getFileSeparator() + "temp_cxf_output_" + rand + ".xml"; todo uncomment later
        return root + getFileSeparator() + "temp_cxf_output_" + ".xml";
    }

    public static boolean isEmpty(String s) {
        return s != null && s.isEmpty();
    }

    public static boolean isNotEmpty(String s) {
        return !isEmpty(s);
    }

    public static File findFile(String path) throws IOException {
        File file = new File(path);

        if (!file.exists()) {
            file.createNewFile();
        }

        return file;
    }

}
