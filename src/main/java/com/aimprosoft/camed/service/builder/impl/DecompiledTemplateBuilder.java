package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.DocumentFactory;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import com.aimprosoft.camed.util.XPathFunctions;
import org.jdom.Element;

import java.io.File;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import static com.aimprosoft.camed.constants.CamConstants.CAM_NAMESPACE;

/**
 * author m.tkachenko
 */
public class DecompiledTemplateBuilder implements ElementBuilder<DecompiledCamTemplate> {

    private Element rootElement;
    private DecompiledCamTemplate template;

    public DecompiledTemplateBuilder(File file) throws CamException {
        rootElement = DocumentFactory.createDocument(file).getRootElement();
        template = new DecompiledCamTemplate();
    }

    @Override
    public DecompiledCamTemplate build() throws CamException {
        DecompiledCamTemplate decompiledCamTemplate = new DecompiledCamTemplate();

        decompiledCamTemplate.setStructures(buildStructures());
        return decompiledCamTemplate;
    }

    private Map<String, Element> buildStructures() {
        Map<String, Element> result = new LinkedHashMap<String, Element>();
        Element structureElement = rootElement.getChild("AssemblyStructure", CAM_NAMESPACE).getChild("Structure", CAM_NAMESPACE);
        result.put(XPathFunctions.absoluteXpathWithPosition(structureElement), structureElement);
        buildChildStructures(structureElement.getChild("Element", CAM_NAMESPACE), result);
        return result;
    }

    private void buildChildStructures(Element element, Map<String, Element> result) {
        for (Element child : (List<Element>) element.getChildren()) {
            String xPath = XPathFunctions.absoluteXpathWithPosition(child) + "[@name=" + child.getAttribute("name").getValue() + "]";
            result.put(xPath, child);
            if (!element.getChildren().isEmpty()) {
                buildChildStructures(child, result);
            }
        }
    }

}