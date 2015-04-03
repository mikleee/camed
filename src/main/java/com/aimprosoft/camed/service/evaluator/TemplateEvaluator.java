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

        Report metaInfoReport = evaluateMetaInfo(referenceTemplate, comparedTemplate);
        result.add(metaInfoReport);

        Report elementNamespaceReport = evaluateCompiledNamespace(referenceTemplate, comparedTemplate);
        result.add(elementNamespaceReport);

        Report structureReport = evaluateStructures(referenceTemplate, comparedTemplate);
        result.add(structureReport);

        return result;
    }

    private Report evaluateStructures(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) throws CamException {
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

    private void findAttrDiffs(Element reference, Element compared, Report report) throws CamException { //todo
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
            Attribute ref = refMetaInfo.get(i);
            for (int j = 0; j < compileMetaInfo.size(); j++) {
                Attribute comp = compileMetaInfo.get(j);

                if (sameAttrNames(ref, comp)) {
                    if (!sameAttrContent(ref, comp)) {
                        report.addMismatch(xpath(comp), comp);
                    }
                    refMetaInfo.remove(i--);
                    compileMetaInfo.remove(j);
                    break;
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

    private Report evaluateCompiledNamespace(DecompiledCamTemplate referenceTemplate, DecompiledCamTemplate comparedTemplate) throws CamException {
        Report report = new Report(ReportTarget.NAMESPACES);
        List<Element> refNamespaces = new ArrayList<Element>(referenceTemplate.getCompiledNamespaces());
        List<Element> compileNamespaces = new ArrayList<Element>(comparedTemplate.getCompiledNamespaces());

        final String prefix = "prefix";

        for (int i = 0; i < refNamespaces.size(); i++) {
            for (int j = 0; j < compileNamespaces.size(); j++) {

                Attribute refPrefix = refNamespaces.get(i).getAttribute(prefix);
                Attribute compiledPrefix = compileNamespaces.get(j).getAttribute(prefix);
                String refUri = refNamespaces.get(i).getText();
                String compiledUri = compileNamespaces.get(j).getText();

                if (sameAttrContent(refPrefix, compiledPrefix)) {
                    if (!refUri.equals(compiledUri)) {
                        report.addMismatch(xpathByAttr(compileNamespaces.get(j), prefix), compileNamespaces.get(j));
                    }
                    refNamespaces.remove(i--);
                    compileNamespaces.remove(j);
                    break;
                }
            }
        }

        for (Element element : refNamespaces) {
            report.addMiss(xpathByAttr(element, prefix), element);
        }

        for (Element element : compileNamespaces) {
            report.addExtra(xpathByAttr(element, prefix), element);
        }

        return report;
    }


    private boolean nonNumberedAttrPair(Attribute attr1, Attribute attr2) {
        return !isNumberedAttribute(attr2) && !isNumberedAttribute(attr1);
    }

    private boolean sameAttrContent(Attribute attr1, Attribute attr2) {
        return !(attr1 == null || attr2 == null) && attr1.getValue().equals(attr2.getValue());
    }

    private boolean sameAttrNames(Attribute attr1, Attribute attr2) {
        return attr1.getQualifiedName().equals(attr2.getQualifiedName());
    }

    public static void main(String[] args) throws CamException {
        File file = new File("/home/stas/Desktop/testTamplate/newTests/compiled-example/CloseDialogSession.cxx");
        File file2 = new File("/home/stas/Desktop/testTamplate/newTests/output/CloseDialogSession.cxx");
        TemplateEvaluator ev = new TemplateEvaluator();
        List<Report> result = ev.evaluate(file, file2);

        for (Report report : result) {
            System.out.println(report);
        }
    }

}
