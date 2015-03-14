package com.aimprosoft.camed.compiler.service.builder.impl;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Structure;
import com.aimprosoft.camed.compiler.service.builder.ElementBuilder;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import org.jdom.Element;

import java.util.HashMap;
import java.util.Map;

/**
 * author m.tkachenko
 */
public class StructureBuilder implements ElementBuilder<Compilable> {

    private final static String TAXONOMY = "taxonomy";
    private final static String TAXONOMY_OTHER = "taxonomyOther";
    private final static String ID = "ID";
    private final static String REFERENCE = "reference";
    private final static String DEFAULT_ID = "default";

    private Element element;
    private CAMTemplate template;


    public StructureBuilder(CAMTemplate template) {
        this.template = template;
        this.element = template.getStructureElement();
    }

    @Override
    public Structure build() throws CamException {
        Map<String, String> taxonomies = defineTaxonomies();
        String id = defineId();
        String reference = defineReference();

        Structure result = new Structure(element);
        result.setTaxonomy(taxonomies.get(TAXONOMY));
        result.setTaxonomyOther(taxonomies.get(TAXONOMY_OTHER)); //todo
        result.setID(id);
        result.setReference(reference);
        result.setTemplate(template);

        return result;
    }


    private Map<String, String> defineTaxonomies() throws CamException {
        Map<String, String> result = new HashMap<String, String>();

        String taxonomy = element.getAttributeValue(TAXONOMY);
        String taxonomyOther = element.getAttributeValue(TAXONOMY_OTHER);

        if (TaxonomyType.isOther(taxonomy) && CommonUtils.isEmpty(taxonomy)) {
            throw new CamException("taxonomyOther should be populated if taxonomy = OTHER");
        }

        result.put(TAXONOMY, taxonomy);
        result.put(TAXONOMY_OTHER, taxonomyOther);
        return result;
    }

    private String defineId() {
        String result = element.getAttributeValue(ID);
        if (result == null || result.isEmpty()) {
            result = DEFAULT_ID;
        }
        return result;
    }

    private String defineReference() throws CamException {
        String result = element.getAttributeValue(REFERENCE);
        if (result == null) {
            result = "";
        }
        if (element.getChildren().size() > 1) {
            throw new CamException("Structure should only have one root node");
        }
        return result;
    }

    public CAMTemplate getTemplate() {
        return template;
    }

    public void setTemplate(CAMTemplate template) {
        this.template = template;
    }
}
