package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.TaxonomyType;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Structure;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
import com.aimprosoft.camed.compiler.util.CommonUtils;
import org.apache.commons.lang.StringUtils;
import org.jdom.Element;
import org.jdom.JDOMException;

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

    public StructureBuilder(Element element) {
        this.element = element;
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
            result = StringUtils.EMPTY;
        }
        if (element.getChildren().size() > 1) {
            throw new CAMCompilerException("Structure should only have one root node");
        }
        return result;
    }

//
//    private void AddStructureToTemplate(Element structure, CAMTemplate template) throws JDOMException {
//        String taxonomy = structure.getAttributeValue("taxonomy");
//        String taxonomyOther = "";
//        if (taxonomy.equals(Structure.TaxonomyType.OTHER.toString())) {
//            taxonomyOther = structure.getAttributeValue("taxonomyOther");
//            if (taxonomyOther.equals("")) {
//                throw new JDOMException("taxonomyOther should be populated if taxonomy = OTHER");
//            }
//        }
//        String ID = structure.getAttributeValue("ID");
//        if (ID == null || ID.equals("")) {
//            ID = "default";
//        }
//        String reference = structure.getAttributeValue("reference");
//        if (reference == null)
//            reference = "";
//        if (structure.getChildren().size() > 1) {
//            throw new JDOMException("Structure should only have one root node");
//        }
//        Structure struct = new Structure(structure, Structure.TaxonomyType.valueOf(taxonomy), taxonomyOther);
//        struct.setID(ID);
//        struct.setReference(reference);
//        struct.setTemplate(template);
//
//        template.putStructure(ID, struct);
//
//
//    }

}
