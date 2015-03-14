package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.model.DecompiledCAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.service.builder.impl.*;
import org.jdom.Document;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class ModelFactory {

    public static Namespaces createNamespaces(CamTemplate template) throws CamException {
        return new NamespacesBuilder(template).build();
    }

    public static Structure createStructure(CamTemplate template) throws CamException {
        return new StructureBuilder(template).build();
    }

    public static CamTemplate createCAMTemplate(Document document) throws CamException {
        return new CAMTemplateBuilder(document).build();
    }

    public static DecompiledCAMTemplate createDecompiledCAMTemplate(Document document) throws CamException {
        return new DecompiledCAMTemplateBuilder(document).build();
    }

    public static Constraint createConstraint(Element element) throws CamException {
        return new ConstraintBuilder(element).build();
    }

    public static Header createHeader(CamTemplate template) throws CamException {
        return new HeaderBuilder(template).build();
    }
}
