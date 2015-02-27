package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.service.impl.*;
import org.jdom.Document;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class ModelFactory {

    public static Namespaces createNamespaces(CAMTemplate template) throws CAMCompilerException {
        return new NamespacesBuilder(template).build();
    }

    public static Structure createStructure(CAMTemplate template) throws CAMCompilerException {
        return new StructureBuilder(template).build();
    }

    public static CAMTemplate createCAMTemplate(Document document) throws CAMCompilerException {
        return new CAMTemplateBuilder(document).build();
    }

    public static Constraint createConstraint(Element element) throws CAMCompilerException {
        return new ConstraintBuilder(element).build();
    }

    public static Header createHeader(CAMTemplate template) throws CAMCompilerException {
        return new HeaderBuilder(template).build();
    }
}
