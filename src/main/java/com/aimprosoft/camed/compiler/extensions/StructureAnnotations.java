package com.aimprosoft.camed.compiler.extensions;

import java.util.HashMap;

public class StructureAnnotations {

    private static HashMap<String,StructureAnnotation> annotations = new HashMap<String, StructureAnnotation>();

    public final static String name = "uk.org.jcam.camed.extensions.StructureAnnotations";

    public StructureAnnotation get(String key) {
        return annotations.get(key);
    }

}
