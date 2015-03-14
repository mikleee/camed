package com.aimprosoft.camed.compiler.service.builder.impl;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.impl.CamTemplate;
import com.aimprosoft.camed.compiler.service.ModelFactory;
import com.aimprosoft.camed.compiler.service.builder.ElementBuilder;
import com.aimprosoft.camed.compiler.service.compiler.ConstraintManager;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class CAMTemplateBuilder implements ElementBuilder<Compilable> {

    private CamTemplate template;

    public CAMTemplateBuilder(Document document) {
        template = new CamTemplate(document);
    }

    @Override
    public CamTemplate build() throws CamException {
        template.setStructure(ModelFactory.createStructure(template));
        template.setNamespaces(ModelFactory.createNamespaces(template));
        template.setHeader(ModelFactory.createHeader(template));
        template.setConstraintManager(ConstraintManager.newInstance(template));
        return template;
    }

}