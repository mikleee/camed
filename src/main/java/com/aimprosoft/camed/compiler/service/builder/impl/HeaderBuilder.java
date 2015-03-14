package com.aimprosoft.camed.compiler.service.builder.impl;

import com.aimprosoft.camed.compiler.CamException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Header;
import com.aimprosoft.camed.compiler.service.builder.ElementBuilder;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class HeaderBuilder implements ElementBuilder<Compilable> {

    private Element element;

    public HeaderBuilder(CAMTemplate template) {
        this.element = template.getTemplateDocument().getRootElement();
    }

    @Override
    public Header build() throws CamException {
        Element headerNode = element.getChild("Header", CAMConstants.CAM_NAMESPACE);
        return headerNode == null ? null : new Header(headerNode);
    }

}
