package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.ReportType;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.DocumentFactory;
import com.aimprosoft.camed.service.ModelFactory;
import com.aimprosoft.camed.util.XPathFunctions;
import org.jdom.Attribute;
import org.jdom.Element;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;


/**
 * @author mtkachenko.
 */
public class TemplateEvaluator {

    Document header;
    Document namespaces;
    Document structure;


    public List<Report> evaluate(File referenceFile, File comparedFile) throws CamException {
        DecompiledCamTemplate referenceTemplate = ModelFactory.createDecompiledCAMTemplate(referenceFile);
        DecompiledCamTemplate comparedTemplate = ModelFactory.createDecompiledCAMTemplate(comparedFile);
        List<Report> result = new LinkedList<Report>();

        Report structureReport = evaluateStructures(referenceTemplate, comparedTemplate);
        result.add(structureReport);

        return result;
    }

    private Report evaluateStructures(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) {
        List<String> missed = new ArrayList<String>();
        List<String> mismatched = new ArrayList<String>();

        Map<String, Element> referenceStructure = new ConcurrentHashMap<String, Element>(referenceTemplate.getStructures());
        Map<String, Element> comparedStructure = new ConcurrentHashMap<String, Element>(comparedTemplate.getStructures());

        for (String key : referenceStructure.keySet()) {
            Element reference = referenceStructure.get(key);
            Element compared = comparedStructure.get(key);

            if (compared == null) {
                missed.add(key);
            } else if (elementsDifferent(reference, compared)) {
                mismatched.add(key);
            }

            referenceStructure.remove(key);
            comparedStructure.remove(key);
        }

        List<String> extra = new ArrayList<String>(comparedStructure.keySet());

        return new Report(ReportType.STRUCTURE, missed, extra, mismatched);
    }

    private boolean elementsDifferent(Element reference, Element compared) {
        return elementNamesDifferent(reference, compared) ||
                attributesCountDifferent(reference, compared) ||
                attributesDifferent(reference, compared);

    }

    private boolean elementNamesDifferent(Element reference, Element compared) {
        return !reference.getQualifiedName().equals(compared.getQualifiedName());
    }


    private boolean attributesCountDifferent(Element reference, Element compared) {
        return reference.getAttributes().size() != compared.getAttributes().size();
    }

    private boolean attributesDifferent(Element reference, Element compared) {
        List<Attribute> referenceAttributes = new ArrayList<Attribute>(reference.getAttributes()); //todo
        List<Attribute> comparedAttributes = new ArrayList<Attribute>(compared.getAttributes());

        for (int i = 0; i < referenceAttributes.size(); i++) {
            Attribute refAttr = referenceAttributes.get(i);
            String refName = XPathFunctions.normalizeAttributeName(refAttr);

            for (Attribute comparedAttr : comparedAttributes) {
                String comparedName = XPathFunctions.normalizeAttributeName(refAttr);

                if (refName.equals(comparedName)) {
                    if (refAttr.getValue().equals(comparedAttr.getValue())) {
                        referenceAttributes.remove(i--);
                        comparedAttributes.remove(comparedAttr);
                        break;
                    }
                }
            }
        }

        return !referenceAttributes.isEmpty() || !comparedAttributes.isEmpty();
    }


    public boolean evaluate(String string1, String string2) throws CamException, ParserConfigurationException {

        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        header = builder.newDocument();
        namespaces = builder.newDocument();
        structure = builder.newDocument();


        Document documentIn = (Document) DocumentFactory.createW3Document(string1);
        Document documentOut = (Document) DocumentFactory.createW3Document(string2);


        documentIn.normalizeDocument();
        documentOut.normalizeDocument();
        header.normalizeDocument();
        namespaces.normalizeDocument();
        structure.normalizeDocument();


        Node node = documentIn.getChildNodes().item(0);


        NodeList list = node.getChildNodes();

        for (int i = 0; i < list.getLength(); i++) {
            if (list.item(i).getNodeName().equals("as:Header")) {
                header.importNode(list.item(i), true);
            }
            if (list.item(i).getNodeName().equals("as:Namespaces")) {
                namespaces.importNode(list.item(i), true);
            }
            if (list.item(i).getNodeName().equals("as:AssemblyStructure")) {
                structure.importNode(list.item(i), true);
            }
        }


        return documentIn.isEqualNode(documentOut);
    }

    public static void main(String[] args) throws CamException {
        File file = new File("C:\\Users\\Мишаня\\IdeaProjects\\camed\\resorces\\output\\result.cxx");
        File file2 = new File("C:\\Users\\Мишаня\\IdeaProjects\\camed\\resorces\\output\\result-copy.cxx");
        TemplateEvaluator ev = new TemplateEvaluator();
        List<Report> result = ev.evaluate(file, file2);
    }

}
