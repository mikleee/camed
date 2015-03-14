package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.DecompiledCamTemplate;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.service.builder.impl.*;
import org.jdom.Document;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class ModelFactory {

    public static Namespaces createNamespaces(CamTemplate template) throws CAMCompilerException {
        return new NamespacesBuilder(template).build();
    }

    public static Structure createStructure(CamTemplate template) throws CAMCompilerException {
        return new StructureBuilder(template).build();
    }

    public static CamTemplate createCAMTemplate(Document document) throws CAMCompilerException {
        return new CamTemplateBuilder(document).build();
    }

    public static DecompiledCamTemplate createDecompiledCAMTemplate(Document document) throws CAMCompilerException {
        return new DecompiledCamTemplateBuilder(document).build();
    }

    public static Constraint createConstraint(Element element) throws CAMCompilerException {
        return new ConstraintBuilder(element).build();
    }

    public static Header createHeader(CamTemplate template) throws CAMCompilerException {
        return new HeaderBuilder(template).build();
    }
}
