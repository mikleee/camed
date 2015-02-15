package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Element;
import org.jdom.Namespace;


public class Import {

    private String URI;
    private String alias;

    public String getAlias() {
        return alias;
    }

    public void setAlias(String alias) {
        this.alias = alias;
    }

    public String getURI() {
        return URI;
    }

    public void setURI(String uri) {
        URI = uri;
    }

    @Override
    public String toString() {
        return this.alias + "=" + this.URI;
    }

    public Element toXML() {

        Element imp = new Element("import", Namespace.getNamespace(CAMConstants.CAM_NAMESPACE_PREFIX, CAMConstants.CAMURI));
        imp.setAttribute("URI", getURI());
        imp.setAttribute("alias", getAlias());
        return imp;
    }
}
