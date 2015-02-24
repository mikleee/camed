package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.util.XPathFunctions;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jaxen.JaxenException;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * author m.tkachenko
 */
public class StructureConstraintBridge {

    private static StructureConstraintBridge instance = new StructureConstraintBridge();

    public static StructureConstraintBridge getInstance() {
        if (instance == null) {
            instance = new StructureConstraintBridge();
        }
        return instance;
    }

    public List<Constraint> findNodeConstraints(Object node, CAMTemplate template) throws CAMCompilerException {
        if (node instanceof Element) {
            return getConstraints((Element) node, template);
        } else if (node instanceof Attribute) {
            return getConstraints((Attribute) node, template);
        } else {
            return null; // it wont be happen
        }
    }

    private List<Constraint> getConstraints(Element element, CAMTemplate template) throws CAMCompilerException {
        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();
        String currentXpath = XPathFunctions.fullXpathWithPosition(element);

        List<Constraint> result = new ArrayList<Constraint>();
        for (String boundXPath : groupedConstraints.keySet()) {

            if (boundXPath.contains("/@")) {
                continue;
            }

            List<Element> matchedNodes = JDOMXPathAdapter.newInstance(boundXPath, template).selectNodes();

            for (Element matchedNode : matchedNodes) {

                String xPathOfCandidate = XPathFunctions.fullXpathWithPosition(matchedNode);
                if (currentXpath.equals(xPathOfCandidate)) {
                    result.addAll(groupedConstraints.get(boundXPath));
                }

            }

        }

        return result;
    }

    private List<Constraint> getConstraints(Attribute attribute, CAMTemplate template) throws CAMCompilerException {
        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();
        String currentXpath = XPathFunctions.fullXpathWithPosition(attribute);

        List<Constraint> result = new ArrayList<Constraint>();
        for (String boundXPath : groupedConstraints.keySet()) {

            if (!boundXPath.contains("/@" + attribute.getQualifiedName())) {
                continue;
            }

            List<Attribute> matchedAttributes = JDOMXPathAdapter.newInstance(boundXPath, template).selectAttributes();
            for (Attribute matchedAttribute : matchedAttributes) {

                String xPathOfCandidate = XPathFunctions.fullXpathWithPosition(matchedAttribute);
                if (currentXpath.equals(xPathOfCandidate)) {
                    result.addAll(groupedConstraints.get(boundXPath));
                }

            }

        }

        return result;
    }

}
