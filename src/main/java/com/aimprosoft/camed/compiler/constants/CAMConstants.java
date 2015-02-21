package com.aimprosoft.camed.compiler.constants;

import org.jdom.Namespace;

public class CAMConstants {

    public static final String CAM_NAMESPACE_PREFIX = "as";
    public static final String CAM_NAMESPACE_URI = "http://www.oasis-open.org/committees/cam";

    public static final Namespace CAMNamespace = Namespace.getNamespace(CAMConstants.CAM_NAMESPACE_PREFIX, CAMConstants.CAM_NAMESPACE_URI);

    public static final Namespace CAM_NAMESPACE = Namespace.getNamespace(CAM_NAMESPACE_PREFIX, CAM_NAMESPACE_URI);

    public static final String ATTR_CAMERROR = "CAMERROR";
    public static final String CAM_EDITOR_PROJECT = "CAMEditor";

}
