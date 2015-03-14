package com.aimprosoft.camed.constants;

import org.jdom.Namespace;

public interface CamConstants {

    String CAM_NAMESPACE_PREFIX = "as";
    String CAM_NAMESPACE_URI = "http://www.oasis-open.org/committees/cam";

    Namespace CAM_NAMESPACE = Namespace.getNamespace(CAM_NAMESPACE_PREFIX, CAM_NAMESPACE_URI);
    Namespace XML_NAMESPACE = Namespace.getNamespace("xml", "http://www.w3.org/XML/1998/namespace");

    String QUOTE = "\"";

}
