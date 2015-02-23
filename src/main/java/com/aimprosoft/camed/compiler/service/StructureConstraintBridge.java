package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.util.XPathFunctions;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jaxen.JaxenException;
import org.jdom.Attribute;
import org.jdom.Element;

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

        try {
            for (String boundXPath : groupedConstraints.keySet()) {

                if (boundXPath.contains("/@")) {
                    continue;
                }

                List<Element> matchedNodes = new JDOMXPathAdapter(boundXPath, template).selectNodes();

                for (Element matchedNode : matchedNodes) {

                    String xPathOfCandidate = XPathFunctions.fullXpathWithPosition(matchedNode);

                    if (currentXpath.equals(xPathOfCandidate)) {
                        return groupedConstraints.get(boundXPath);
                    }

                }

            }

            return null;
        } catch (JaxenException e) {
            throw new CAMCompilerException();
        }
    }

    private List<Constraint> getConstraints(Attribute attribute, CAMTemplate template) throws CAMCompilerException {
        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();

        for (String boundXPath : groupedConstraints.keySet()) {

            if (!boundXPath.contains("@" + attribute.getQualifiedName())) {
                continue;
            }

            String parentXpath = XPathFunctions.getParentXpath(boundXPath);
            if (isAttributeMapped(attribute, parentXpath, template)) {
                return groupedConstraints.get(boundXPath);
            }

        }
        return null;
    }

    private boolean isAttributeMapped(Attribute attribute, String parentXpath, CAMTemplate template) throws CAMCompilerException {
        try {
            List<Element> matchedParentNodes = new JDOMXPathAdapter(parentXpath, template).selectNodes();

            if (parentXpath.equals("//UDBFile")) { // example "//@attr"
                for (Element matchedParentNode : matchedParentNodes) {
                    // if attr consist in one of children of  "UDBFile"
                    if (XPathFunctions.isAttributePresent(attribute, matchedParentNode)) {
                        return true;
                    }
                }
            } else {
                for (Element matchedParentNode : matchedParentNodes) {
                    // if attr consist in one of matched nodes
                    if (matchedParentNode.getAttribute(attribute.getQualifiedName()) != null) {
                        return true;
                    }
                }
            }

            return false;
        } catch (JaxenException e) {
            throw new CAMCompilerException(e.getMessage());
        }
    }
}
