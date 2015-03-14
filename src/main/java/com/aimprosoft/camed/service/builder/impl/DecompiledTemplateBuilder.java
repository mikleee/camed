package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class DecompiledTemplateBuilder implements ElementBuilder<DecompiledCamTemplate> {

    private DecompiledCamTemplate template;

    public DecompiledTemplateBuilder(Document document) {

    }

    @Override
    public DecompiledCamTemplate build() throws CamException {

        return null;
    }

}