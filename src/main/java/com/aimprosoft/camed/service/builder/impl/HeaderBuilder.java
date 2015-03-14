package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.CamConstants;
import com.aimprosoft.camed.model.Compilable;
import com.aimprosoft.camed.model.impl.CamTemplate;
import com.aimprosoft.camed.model.impl.Header;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import org.jdom.Element;

/**
 * @author mtkachenko.
 */
public class HeaderBuilder implements ElementBuilder<Compilable> {

    private Element element;

    public HeaderBuilder(CamTemplate template) {
        this.element = template.getTemplateDocument().getRootElement();
    }

    @Override
    public Header build() throws CamException {
        Element headerNode = element.getChild("Header", CamConstants.CAM_NAMESPACE);
        return headerNode == null ? null : new Header(headerNode);
    }

}
