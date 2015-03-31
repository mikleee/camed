package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.ReportTarget;
import com.aimprosoft.camed.model.DecompiledCamTemplate;
import com.aimprosoft.camed.service.ModelFactory;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.File;
import java.util.*;
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

        Report metaInfoReport = evaluateMetaInfo(referenceTemplate, comparedTemplate);
        Report namespacesReport = evaluateNamespace(referenceTemplate, comparedTemplate);
        Report elementNamespaceReport = evaluateCompileNamespace(referenceTemplate, comparedTemplate);
        Report structureReport = evaluateStructures(referenceTemplate, comparedTemplate);
        result.add(metaInfoReport);
        result.add(namespacesReport);
        result.add(elementNamespaceReport);
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

            if (compared != null) {
                findAttrDiffs(reference, compared, report);
                comparedStructure.remove(key);
                referenceStructure.remove(key);
            }

        }

        report.addExtras(comparedStructure);
        report.addMisses(referenceStructure);

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
                        report.addMismatch(absoluteXPathByName(comparedAttr), comparedAttr);
                        referenceAttributes.remove(i--);
                        comparedAttributes.remove(j);
                        break;
                    }
                }
            }
        }

        for (Attribute attr : referenceAttributes) {
            report.addMiss(absoluteXPathByName(attr), attr);
        }

        for (Attribute attr : comparedAttributes) {
            report.addExtra(absoluteXPathByName(attr), attr);
        }

    }


    private Report evaluateMetaInfo(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) {
        Report report = new Report(ReportTarget.META_INFO);
        List<Attribute> refMetaInfo = new ArrayList<Attribute>(referenceTemplate.getMetaInfo());
        List<Attribute> compileMetaInfo = new ArrayList<Attribute>(comparedTemplate.getMetaInfo());

        for (int i = 0; i < refMetaInfo.size(); i++) {
            for (int j = 0; j < compileMetaInfo.size(); j++) {
                if (sameAttrContent(refMetaInfo.get(i), compileMetaInfo.get(j))) {
                    refMetaInfo.remove(i);
                    compileMetaInfo.remove(j--);
                }
            }
        }

        for (Attribute attr : refMetaInfo) {
            report.addMiss(xpath(attr), attr);
        }
        for (Attribute attr : compileMetaInfo) {
            report.addExtra(xpath(attr), attr);
        }

        return report;
    }

    private Report evaluateNamespace(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) {
        Report report = new Report(ReportTarget.NAMESPACES);
        Set<Namespace> refNamespaces = new HashSet<Namespace>(referenceTemplate.getDeclaredNamespaces());
        Set<Namespace> refNamespacesCopy = new HashSet<Namespace>(refNamespaces);
        Set<Namespace> compileNamespaces = new HashSet<Namespace>(comparedTemplate.getDeclaredNamespaces());
        refNamespaces.removeAll(compileNamespaces);
        compileNamespaces.removeAll(refNamespacesCopy);

//        for (Namespace attr : refNamespaces) {
//            report.addMiss(attr.toString());
//        }
//
//        for (Namespace attr : compileNamespaces) {
//            report.addExtra(attr.toString(), attr);
//        }

        return report;
    }

    private Report evaluateCompileNamespace(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) {
        Report report = new Report(ReportTarget.NAMESPACES);
        List<Element> refNamespaces = new ArrayList<Element>(referenceTemplate.getCompiledNamespaces());
        List<Element> compileNamespaces = new ArrayList<Element>(comparedTemplate.getCompiledNamespaces());

        for (int i = 0; i < refNamespaces.size(); i++) {
            for (int j = 0; j < compileNamespaces.size(); j++) {
                if (refNamespaces.get(i).getAttribute("prefix").getValue().equals(compileNamespaces.get(j).getAttribute("prefix").getValue()) &&
                        refNamespaces.get(i).getText().equals(compileNamespaces.get(j).getText())) {
                    refNamespaces.remove(i--);
                    compileNamespaces.remove(j);
                    break;
                }
            }
        }

        for (Element element : refNamespaces) {
            report.addMiss(xpath(element), element);
        }

        for (Element element : compileNamespaces) {
            report.addExtra(xpath(element), element);
        }

        return report;
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
        File file = new File("/home/stas/Work/Projects/camed/resorces/compiled-example/UDB-cam.cxx");
        File file2 = new File("/home/stas/Work/Projects/camed/resorces/output/result.cxx");
        TemplateEvaluator ev = new TemplateEvaluator();
        List<Report> result = ev.evaluate(file, file2);

        for (Report report : result) {
            System.out.println(report);
        }
    }

}
