package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.model.DecompiledCamTemplate;
import com.aimprosoft.camed.compiler.model.impl.*;
import com.aimprosoft.camed.compiler.service.builder.impl.*;
import org.jdom.Document;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class ModelFactory {

    public static Namespaces createNamespaces(CAMTemplate template) throws CamException {
        return new NamespacesBuilder(template).build();
    }

    public static Structure createStructure(CAMTemplate template) throws CamException {
        return new StructureBuilder(template).build();
    }

    public static CAMTemplate createCAMTemplate(Document document) throws CamException {
        return new CamTemplateBuilder(document).build();
    }

    public static DecompiledCamTemplate createDecompiledCAMTemplate(Document document) throws CamException {
        return new DecompiledCamTemplateBuilder(document).build();
    }

    public static Constraint createConstraint(Element element) throws CamException {
        return new ConstraintBuilder(element).build();
    }

    public static Header createHeader(CAMTemplate template) throws CamException {
        return new HeaderBuilder(template).build();
    }
}
