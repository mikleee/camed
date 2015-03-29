package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.ReportTarget;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.ModelFactory;
import org.jdom.Attribute;
import org.jdom.Element;

import java.io.File;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import static com.aimprosoft.camed.util.XPathFunctions.*;


/**
 * @author mtkachenko.
 */
public class TemplateEvaluator {


    public List<Report> evaluate(File referenceFile, File comparedFile) throws CamException {
        DecompiledCamTemplate referenceTemplate = ModelFactory.createDecompiledCAMTemplate(referenceFile);
        DecompiledCamTemplate comparedTemplate = ModelFactory.createDecompiledCAMTemplate(comparedFile);
        List<Report> result = new LinkedList<Report>();

        Report structureReport = evaluateStructures(referenceTemplate, comparedTemplate);
        result.add(structureReport);

        return result;
    }

    private Report evaluateStructures(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) {
        Report report = new Report(ReportTarget.STRUCTURE);

        Map<String, Element> referenceStructure = new ConcurrentHashMap<String, Element>(referenceTemplate.getStructures());
        Map<String, Element> comparedStructure = new ConcurrentHashMap<String, Element>(comparedTemplate.getStructures());

        for (String key : referenceStructure.keySet()) {
            Element reference = referenceStructure.get(key);
            Element compared = comparedStructure.get(key);

            if (compared == null) {
                report.addMiss(key);
            }

            findAttrDiffs(reference, compared, report);

            referenceStructure.remove(key);
            comparedStructure.remove(key);
        }

        report.addExtras(comparedStructure.keySet());
        report.addMisses(referenceStructure.keySet());

        return report;
    }

    private void findAttrDiffs(Element reference, Element compared, Report report) { //todo
        List<Attribute> referenceAttributes = new ArrayList<Attribute>(reference.getAttributes());
        List<Attribute> comparedAttributes = new ArrayList<Attribute>(compared.getAttributes());

        for (int i = 0; i < referenceAttributes.size(); i++) {
            Attribute refAttr = referenceAttributes.get(i);
            String refName = normalizeAttributeName(refAttr);

            for (int j = 0; j < comparedAttributes.size(); j++) {
                Attribute comparedAttr = comparedAttributes.get(j);
                String comparedName = normalizeAttributeName(comparedAttr);

                if (refName.equals(comparedName)) {
                    if (sameAttrContent(refAttr, comparedAttr)) {
                        referenceAttributes.remove(i--);
                        comparedAttributes.remove(j);
                        break;
                    } else if (nonNumberedAttrPair(refAttr, comparedAttr)) {
                        report.addMismatch(absoluteXPathByName(comparedAttr));
                        referenceAttributes.remove(i--);
                        comparedAttributes.remove(j);
                        break;
                    }
                }
            }
        }

        for (Attribute attr : referenceAttributes) {
            report.addMiss(absoluteXPathByName(attr));
        }

        for (Attribute attr : comparedAttributes) {
            report.addExtra(absoluteXPathByName(attr));
        }

    }

    private boolean nonNumberedAttrPair(Attribute attr1, Attribute attr2) {
        return !isNumberedAttribute(attr2) && !isNumberedAttribute(attr1);
    }

    private boolean sameAttrContent(Attribute attr1, Attribute attr2) {
        return attr1.getValue().equals(attr2.getValue());
    }


/*    public boolean evaluate(String string1, String string2) throws CamException, ParserConfigurationException {

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
    }*/

    public static void main(String[] args) throws CamException {
        File file = new File("C:\\Users\\Мишаня\\IdeaProjects\\camed\\resorces\\compiled-example\\UDB-cam.cxx");
        File file2 = new File("C:\\Users\\Мишаня\\IdeaProjects\\camed\\resorces\\output\\result.cxx");
        TemplateEvaluator ev = new TemplateEvaluator();
        List<Report> result = ev.evaluate(file, file2);

        for (Report report : result) {
            System.out.println(report);
        }
    }

}
