package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.TimeTracker;
import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.util.XPathFunctions;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConstraintManager {

    private List<Constraint> constraints = new ArrayList<Constraint>();
    private Map<String, List<Constraint>> groupedConstraints = new HashMap<String, List<Constraint>>();
    private Map<String, List<Element>> groupedElements = new HashMap<String, List<Element>>();
    private Map<String, List<Attribute>> groupedAttributes = new HashMap<String, List<Attribute>>();


    public static ConstraintManager newInstance(CAMTemplate template) throws CAMCompilerException {
        return new ConstraintManager(template);
    }

    private ConstraintManager(CAMTemplate template) throws CAMCompilerException {
        long start = System.currentTimeMillis();
        initConstraints(template);
        bindConstraintsToXpath();
        TimeTracker.constraintManagerInit = System.currentTimeMillis() - start;
        groupElements(template);
    }

    public Map<String, List<Constraint>> getGroupedConstraints() {
        return groupedConstraints;
    }

    public Map<String, List<Element>> getGroupedElements() {
        return groupedElements;
    }

    public Map<String, List<Attribute>> getGroupedAttributes() {
        return groupedAttributes;
    }

    private void initConstraints(CAMTemplate template) throws CAMCompilerException {
        Element contextNode = template.getContextElement();
        //noinspection unchecked
        for (Element constraintNode : (List<Element>) contextNode.getChildren()) {
            constraints.add(ModelFactory.createConstraint(constraintNode));
        }
    }

    private void bindConstraintsToXpath() {
        for (int i = 0; i < constraints.size(); i++) {

            String xPath = constraints.get(i).getXPath();
            List<Constraint> constraintGroup = new ArrayList<Constraint>();
            constraintGroup.add(constraints.get(i));

            for (int j = i + 1; j < constraints.size(); ) {
                String thatXPath = constraints.get(j).getXPath();

                if (xPath.equals(thatXPath)) {
                    constraintGroup.add(constraints.get(j));
                    constraints.remove(j);
                } else {
                    j++;
                }
            }

            groupedConstraints.put(xPath, constraintGroup);
        }
    }

    private void groupElements(CAMTemplate template) throws CAMCompilerException {
        for (String boundXPath : groupedConstraints.keySet()) {
            JDOMXPathAdapter jdomxPathAdapter = JDOMXPathAdapter.newInstance(boundXPath, template);
            if (XPathFunctions.isAttributePath(boundXPath)) {
                groupedAttributes.put(boundXPath, jdomxPathAdapter.selectAttributes());
            } else {
                groupedElements.put(boundXPath, jdomxPathAdapter.selectNodes());
            }
        }
    }

}
