package com.aimprosoft.camed.compiler.constants;

import org.jdom.Namespace;

public class CAMConstants {

    public static final Namespace CAMNamespace = Namespace.getNamespace(CAMConstants.CAM_NAMESPACE_PREFIX, CAMConstants.CAMURI);

    public static final String ATTR_CAMERROR = "CAMERROR";
    public static final String CAM_EDITOR_PROJECT = "CAMEditor";
    public static final String CAM_NAMESPACE_PREFIX = "as";
    public static final String CAMURI = "http://www.oasis-open.org/committees/cam";
}
