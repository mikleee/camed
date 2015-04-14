package com.aimprosoft.camed.model.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.TaxonomyType;
import com.aimprosoft.camed.model.Compilable;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;

import java.util.List;

import static com.aimprosoft.camed.constants.CamConstants.QUOTE;


public class Structure implements Compilable {

    private String id = "";
    private String reference = "";
    private String taxonomy = TaxonomyType.XML.toString();
    private String taxonomyOther = ""; //todo
    private Element structure;
    private CamTemplate template;

    public Structure(Element element) {
        structure = element;
    }

    @Override
    public String compile() throws CamException {
        StringBuilder builder = compileHead();

        //noinspection unchecked
        for (Element structureContent : (List<Element>) structure.getChildren()) {
            compile(builder, structureContent);
        }

        builder.append("</as:Structure>\n");
        return builder.toString();
    }

    private StringBuilder compileHead() {
        StringBuilder builder = new StringBuilder("<as:Structure ");

        if (id != null) {
            builder.append(" ID=" + QUOTE).append(StringEscapeUtils.escapeXml(id)).append(QUOTE + " ");
        }
        if (reference != null) {
            builder.append(" reference=" + QUOTE).append(StringEscapeUtils.escapeXml(reference)).append(QUOTE + " ");
        }
        if (taxonomy != null) {
            builder.append(" taxonomy=" + QUOTE).append(StringEscapeUtils.escapeXml(taxonomy)).append(QUOTE + " "); //todo
        }

        builder.append(">\n");
        return builder;
    }

    private StringBuilder compile(StringBuilder builder, Element element) throws CamException {
        StructureElement wrapper = new StructureElement(element, template);
        builder.append(wrapper.compile());

        return builder;
    }


    public void setID(String id) {
        this.id = id;
//        structure.setAttribute("ID", id);
    }

    public void setReference(String reference) {
        this.reference = reference;
//        structure.setAttribute("reference", reference);
    }

    public Element getStructure() {
        return structure;
    }

    public void setTemplate(CamTemplate template) {
        this.template = template;
    }

    public void setTaxonomy(String taxonomy) {
        this.taxonomy = taxonomy;
//        structure.setAttribute("taxonomy", taxonomy);
    }

    public void setTaxonomyOther(String taxonomyOther) {
        this.taxonomyOther = taxonomyOther;
//        structure.setAttribute("taxonomyOther", taxonomyOther);
    }

}