package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.model.Structure;
import com.aimprosoft.camed.compiler.service.impl.CAMTemplateBuilder;
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

    public static CAMTemplate createCAMTemplate(Document document) throws CAMCompilerException {
        return new CAMTemplateBuilder(document).build();
    }
}
