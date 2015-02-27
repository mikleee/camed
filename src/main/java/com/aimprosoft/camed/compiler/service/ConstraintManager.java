package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConstraintManager {

    private static final String CONTEXT_PATH = "//as:context";
    private List<Constraint> constraints;
    private Map<String, List<Constraint>> groupedConstraints;


    public static ConstraintManager newInstance(CAMTemplate template) throws CAMCompilerException {
        return new ConstraintManager(template);
    }

    private ConstraintManager(CAMTemplate template) throws CAMCompilerException {
        initConstraints(template);
        bindConstraintsToXpath();

    }

    public Map<String, List<Constraint>> getGroupedConstraints() {
        return groupedConstraints;
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
            String xPath = constraints.get(i).getItem();
            List<Constraint> constraintGroup = new ArrayList<Constraint>();
            constraintGroup.add(constraints.get(i));

            for (int j = i + 1; j < constraints.size(); ) {
                String thatXPath = constraints.get(j).getItem();

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

}
