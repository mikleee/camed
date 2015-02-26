package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.model.Compilable;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;

import java.util.List;


public class Structure implements Compilable {

    private String id = "";
    private String reference = "";
    private String taxonomy = TaxonomyType.XML.toString();
    private String taxonomyOther = "";
    private Element structure;
    private CAMTemplate template;

    public Structure(Element element) {
        structure = element;
    }

    public Structure(Element structure, TaxonomyType taxonomy, String taxonomyOther) {
        setStructure(structure);
//        setTaxonomy(taxonomy);
        if (taxonomy == TaxonomyType.OTHER) //todo
            setTaxonomyOther(taxonomyOther);

    }

    @Override
    public String compile() throws CAMCompilerException {
        StringBuilder builder = new StringBuilder("<as:Structure ");

        if (id != null) {
            builder.append(" ID=" + QUOTE).append(StringEscapeUtils.escapeXml(id)).append(QUOTE + " ");
        }
        if (reference != null) {
            builder.append(" reference=" + QUOTE).append(StringEscapeUtils.escapeXml(reference)).append(QUOTE + " ");
        }
        if (taxonomy != null) {
            builder.append(" taxonomy=" + QUOTE).append(StringEscapeUtils.escapeXml(taxonomy)).append(QUOTE + " ");
        }
        builder.append(">\n");

        //todo
//            if (template != null && template.getParameters().size() > 0) {
//                out.write("<" + "as:parameters" + ">\n");
//                for (Parameter param : template.getParameters()) {
//                    param.toCXF(out);
//                }
//                out.write("</" + "as:parameters" + ">\n");
//            }

        for (Element structureContent : (List<Element>) structure.getChildren()) {
            compile(builder, structureContent);
        }

        builder.append("</as:Structure>\n");
        return builder.toString();
    }

    private StringBuilder compile(StringBuilder builder, Element element) throws CAMCompilerException {
        StructureElement wrapper = new StructureElement(element, template);
        builder.append(wrapper.compile());

        return builder;
    }

    public String getID() {
        return id;
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

    public void setStructure(Element structure) {
        this.structure = structure;
    }

    public void setTemplate(CAMTemplate template) {
        this.template = template;
    }

    public void setTaxonomy(String taxonomy) {
        this.taxonomy = taxonomy;
//        structure.setAttribute("taxonomy", taxonomy);
    }

    public String getTaxonomyOther() {
        return taxonomyOther;
    }

    public void setTaxonomyOther(String taxonomyOther) {
        this.taxonomyOther = taxonomyOther;
//        structure.setAttribute("taxonomyOther", taxonomyOther);
    }

}
