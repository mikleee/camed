package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.DecompiledCAMTemplate;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class DecompiledTemplateBuilder implements ElementBuilder<DecompiledCAMTemplate> {

    private DecompiledCAMTemplate template;

    public DecompiledTemplateBuilder(Document document) {

    }

    @Override
    public DecompiledCAMTemplate build() throws CamException {

        return null;
    }

}