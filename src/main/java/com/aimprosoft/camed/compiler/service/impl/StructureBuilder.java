package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Structure;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import org.apache.commons.lang.StringUtils;
import org.jdom.Element;

import java.util.HashMap;
import java.util.Map;

/**
 * author m.tkachenko
 */
public class StructureBuilder implements ElementBuilder {

    private final static String TAXONOMY = "taxonomy";
    private final static String TAXONOMY_OTHER = "taxonomyOther";
    private final static String ID = "ID";
    private final static String REFERENCE = "reference";
    private final static String DEFAULT_ID = "default";

    private Element element;
    private CAMTemplate template;


    public StructureBuilder(CAMTemplate template) {
        this.template = template;
        this.element = template.getTemplateDocument().getRootElement()
                .getChild("AssemblyStructure", CAMConstants.CAM_NAMESPACE)
                .getChild("Structure", CAMConstants.CAM_NAMESPACE);
    }

    @Override
    public Structure build() throws CAMCompilerException {
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


    private Map<String, String> defineTaxonomies() throws CAMCompilerException {
        Map<String, String> result = new HashMap<String, String>();

        String taxonomy = element.getAttributeValue(TAXONOMY);
        String taxonomyOther = element.getAttributeValue(TAXONOMY_OTHER);

        if (TaxonomyType.isOther(taxonomy) && CommonUtils.isEmpty(taxonomy)) {
            throw new CAMCompilerException("taxonomyOther should be populated if taxonomy = OTHER");
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

    private String defineReference() throws CAMCompilerException {
        String result = element.getAttributeValue(REFERENCE);
        if (result == null) {
            result = "";
        }
        if (element.getChildren().size() > 1) {
            throw new CAMCompilerException("Structure should only have one root node");
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
