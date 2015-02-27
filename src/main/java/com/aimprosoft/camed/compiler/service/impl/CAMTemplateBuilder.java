package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.service.ConstraintManager;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
import com.aimprosoft.camed.compiler.service.ModelFactory;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class CAMTemplateBuilder implements ElementBuilder {

    private CAMTemplate template;

    public CAMTemplateBuilder(Document document) {
        template = new CAMTemplate(document);
    }

    @Override
    public CAMTemplate build() throws CAMCompilerException {
        template.setStructure(ModelFactory.createStructure(template));
        template.setNamespaces(ModelFactory.createNamespaces(template));
        template.setHeader(ModelFactory.createHeader(template));
        template.setConstraintManager(ConstraintManager.newInstance(template));
        return template;
    }

}