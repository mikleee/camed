package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.DecompiledCamsTemplate;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import org.jdom.Document;

/**
 * author m.tkachenko
 */
public class DecompiledTemplateBuilder implements ElementBuilder<DecompiledCamsTemplate> {

    private DecompiledCamsTemplate template;

    public DecompiledTemplateBuilder(Document document) {

    }

    @Override
    public DecompiledCamsTemplate build() throws CamException {

        return null;
    }

}