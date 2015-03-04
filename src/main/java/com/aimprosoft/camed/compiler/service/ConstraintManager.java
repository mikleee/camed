package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConstraintManager {

    private static final String CONTEXT_PATH = "//as:context";
    private List<Constraint> constraints;
    private Map<String, List<Constraint>> groupedConstraints;
    private Map<String, List<Element>> groupedElements = new HashMap<String, List<Element>>();
    private Map<String, List<Attribute>> groupedAttributes = new HashMap<String, List<Attribute>>();


    public static ConstraintManager newInstance(CAMTemplate template) throws CAMCompilerException {
        return new ConstraintManager(template);
    }

    private ConstraintManager(CAMTemplate template) throws CAMCompilerException {
        initConstraints(template);
        bindConstraintsToXpath();
        bindElementsToXpath(template);
        bindAttributesToXpath(template);

    }

    public Map<String, List<Constraint>> getGroupedConstraints() {
        return groupedConstraints;
    }

    public Map<String, List<Element>> groupedElements() {
        return groupedElements;
    }

    public Map<String, List<Attribute>> getGroupedAttributes() {
        return groupedAttributes;
    }

    private void initConstraints(CAMTemplate template) throws CAMCompilerException {
        constraints = new ArrayList<Constraint>();

        Element contextNode = JDOMXPathAdapter.newInstance(CONTEXT_PATH, template).selectNode();
        //noinspection unchecked
        for (Element constraintNode : (List<Element>) contextNode.getChildren()) {
            constraints.add(ModelFactory.createConstraint(constraintNode)); //todo
        }

    }

    private void bindConstraintsToXpath() {
        List<Constraint> constraints = new ArrayList<Constraint>(this.constraints);

        groupedConstraints = new HashMap<String, List<Constraint>>();

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

    private void bindElementsToXpath(CAMTemplate template) throws CAMCompilerException {
        long start = System.currentTimeMillis();
        for (String boundXPath : groupedConstraints.keySet()) {
            if(boundXPath.contains("/@")){
                continue;
            }
            List<Element> matchedElements = JDOMXPathAdapter.newInstance(boundXPath, template).selectNodes() ;
            groupedElements.put(boundXPath,matchedElements);
        }
        System.out.println("bindElementsToXpath work time " + (System.currentTimeMillis() - start));
    }

    private void bindAttributesToXpath(CAMTemplate template) throws CAMCompilerException {
        long start = System.currentTimeMillis();

        for (String boundXPath : groupedConstraints.keySet()) {
            if(!boundXPath.contains("/@")){
                continue;
            }
            List<Attribute> matchedAttributes = JDOMXPathAdapter.newInstance(boundXPath, template).selectAttributes();
            groupedAttributes.put(boundXPath, matchedAttributes);
        }
        System.out.println("bindAttributesToXpath work time " + (System.currentTimeMillis() - start));
    }

}
