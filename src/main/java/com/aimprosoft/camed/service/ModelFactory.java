package com.aimprosoft.camed.service;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.model.impl.*;
import com.aimprosoft.camed.service.builder.impl.*;
import org.jdom.Document;
import org.jdom.Element;

import java.io.File;

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
        return new TemplateBuilder(document).build();
    }

    public static DecompiledCamTemplate createDecompiledCAMTemplate(File file) throws CamException {
        return new DecompiledTemplateBuilder(file).build();
    }

    public static Constraint createConstraint(Element element) throws CamException {
        return new ConstraintBuilder(element).build();
    }

    public static Header createHeader(CamTemplate template) throws CamException {
        return new HeaderBuilder(template).build();
    }
}
