package com.aimprosoft.camed.compiler.extensions;

import java.io.IOException;
import java.io.Writer;
import java.util.List;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Annotation;
import com.aimprosoft.camed.compiler.model.Documentation;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;


/**
 * @author 802051682
 */
public class StructureAnnotation extends Annotation implements Cloneable {

    private String xpath_ = "";

    public StructureAnnotation(Element annotation) {
        super(CAMConstants.CAMNamespace);
        setAnnotation(annotation);
        xpath_ = annotation.getAttributeValue("item");
    }

    public StructureAnnotation(String xpath, List<Documentation> documentation) {
        super(CAMConstants.CAMNamespace);
        setDocumentation(documentation);
        xpath_ = xpath;
    }

    public StructureAnnotation(String xpath, String type, String text) {
        super(CAMConstants.CAMNamespace);
        setFirstDocumentationText(type, text);
        xpath_ = xpath;
    }

    @Override
    public Element toXML() {
        Element ann = new Element("annotation", CAMConstants.CAMNamespace);
        ann.setAttribute("item", xpath_);
        if (getDocumentation() != null) {
            for (Documentation documentation : getDocumentation()) {
                Element docu = documentation.toXML();
                if (docu != null)
                    ann.addContent(docu);
            }
            return ann;
        } else {
            return null;
        }
    }

    @Override
    public void toCXF(Writer out) throws IOException {
        out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":" + "annotation" + " ");
        out.write(" " + "item" + "=\"" + StringEscapeUtils.escapeXml(xpath_) + "\" ");
        out.write(">\n");
        if (getDocumentation() != null) {
            for (Documentation documentation : getDocumentation()) {
                documentation.toCXF(out);
            }
        }
        out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":" + "annotation" + ">\n");
    }

    public String getXpath() {
        return xpath_;
    }

    public void setXpath(String xpath) {
        this.xpath_ = xpath;
    }

    public StructureAnnotation cloneAnnotation() throws CloneNotSupportedException {
        return (StructureAnnotation) clone();
    }

    /* (non-Javadoc)
     * @see java.lang.Object#clone()
     */
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

}
