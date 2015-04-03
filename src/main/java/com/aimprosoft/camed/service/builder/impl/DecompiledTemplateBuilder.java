package com.aimprosoft.camed.service.builder.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.CamConstants;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.DocumentFactory;
import com.aimprosoft.camed.service.ModelFactory;
import com.aimprosoft.camed.service.builder.ElementBuilder;
import com.aimprosoft.camed.util.CommonUtils;
import com.aimprosoft.camed.util.XPathFunctions;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.File;
import java.util.*;

import static com.aimprosoft.camed.constants.CamConstants.CAM_NAMESPACE;

/**
 * author m.tkachenko
 */
public class DecompiledTemplateBuilder implements ElementBuilder<DecompiledCamTemplate> {

    private Element rootElement;

    public DecompiledTemplateBuilder(File file) throws CamException {
        rootElement = DocumentFactory.createDocument(file).getRootElement();
    }


    @Override
    public DecompiledCamTemplate build() throws CamException {
        DecompiledCamTemplate decompiledCamTemplate = new DecompiledCamTemplate();
        decompiledCamTemplate.setMetaInfo(rootElement.getAttributes());

        buildNamespaces(decompiledCamTemplate);
        if (invalidNamespaces(decompiledCamTemplate)) {
            throw new CamException("Namespaces are invalid: declared namespaces should be identical to compiled namespaces.");
        }

        decompiledCamTemplate.setStructures(buildStructures());
        return decompiledCamTemplate;
    }

    private Map<String, Element> buildStructures() throws CamException {
        Map<String, Element> result = new LinkedHashMap<String, Element>();
        Element structureElement = rootElement.getChild("AssemblyStructure", CAM_NAMESPACE).getChild("Structure", CAM_NAMESPACE);
        result.put(XPathFunctions.absoluteXpathWithPosition(structureElement), structureElement);
        buildChildStructures(structureElement.getChild("Element", CAM_NAMESPACE), result);
        return result;
    }


    private void buildChildStructures(Element element, Map<String, Element> result) throws CamException {
        for (Element child : (List<Element>) element.getChildren()) {
            String xPath = XPathFunctions.absoluteXPathByName(child);
            result.put(xPath, child);
            if (!element.getChildren().isEmpty()) {
                buildChildStructures(child, result);
            }
        }
    }


    private void buildNamespaces(DecompiledCamTemplate template) throws CamException {
        //noinspection unchecked
        List<Element> compiledNamespaces = (List<Element>) rootElement.getChild("Namespaces", CAM_NAMESPACE).getChildren();
        template.setCompiledNamespaces(compiledNamespaces);

        Set<Namespace> declared = new HashSet<Namespace>();
        NamespacesBuilder.populateNamespaceList(rootElement, declared);
        template.setDeclaredNamespaces(new ArrayList<Namespace>(declared));
    }

    public boolean invalidNamespaces(DecompiledCamTemplate template) throws CamException {
        List<Namespace> compiled = new ArrayList<Namespace>();
        List<Namespace> declared = new ArrayList<Namespace>(template.getDeclaredNamespaces());

        for (Element child : template.getCompiledNamespaces()) {
            String prefix = child.getAttribute("prefix").getValue();
            String uri = child.getText();
            compiled.add(CommonUtils.createNamespace(prefix, uri));
        }

        if (declared.size() != compiled.size() - 1) {
            return false;
        }

        if (compiled.contains(CamConstants.XML_NAMESPACE)) {
            compiled.remove(CamConstants.XML_NAMESPACE);
        } else {
            return false;
        }

        for (int i = 0; i < compiled.size(); i++) {
            Namespace cNamespace = compiled.get(i);
            for (int j = 0; j < declared.size(); j++) {
                Namespace dNamespace = declared.get(j);
                if (cNamespace.equals(dNamespace)) {
                    compiled.remove(i--);
                    declared.remove(j);
                    break;
                }
            }
        }

        return !declared.isEmpty() || !compiled.isEmpty();
    }

    public static void main(String[] args) throws CamException {
        File file = new File("/home/stas/Desktop/testTamplate/newTests/output/CreateDialogSession.cxx");
        DecompiledCamTemplate decompiledCamTemplate = ModelFactory.createDecompiledCAMTemplate(file);
    }

}