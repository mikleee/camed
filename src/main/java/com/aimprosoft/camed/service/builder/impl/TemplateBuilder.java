package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.Compilable;
import com.aimprosoft.camed.model.impl.CamTemplate;
import com.aimprosoft.camed.service.ModelFactory;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import com.aimprosoft.camed.service.compiler.ConstraintManager;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class TemplateBuilder implements ElementBuilder<Compilable> {

    private CamTemplate template;

    public TemplateBuilder(Document document) {
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