package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.model.impl.Structure;
import com.aimprosoft.camed.compiler.service.impl.CAMTemplateBuilder;
import com.aimprosoft.camed.compiler.service.impl.ConstraintBuilder;
import com.aimprosoft.camed.compiler.service.impl.StructureBuilder;
import org.jdom.Document;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class ModelFactory {

    public static Structure createStructure(Element element) throws CAMCompilerException {
        return new StructureBuilder(element).build();
    }

    public static Structure createStructure(Element element, CAMTemplate template) throws CAMCompilerException {
        return new StructureBuilder(element, template).build();
    }

    public static CAMTemplate createCAMTemplate(Document document) throws CAMCompilerException {
        return new CAMTemplateBuilder(document).build();
    }

    public static Constraint createConstraint(Element element) throws CAMCompilerException {
        return new ConstraintBuilder(element).build();
    }
}
