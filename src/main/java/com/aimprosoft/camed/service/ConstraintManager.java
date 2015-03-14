package com.aimprosoft.camed.service;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.ParseStrategy;
import com.aimprosoft.camed.model.impl.Constraint;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConstraintManager {

    private List<Constraint> constraints = new ArrayList<Constraint>();
    private Map<String, List<Constraint>> groupedConstraints = new HashMap<String, List<Constraint>>();


    public static ConstraintManager newInstance(Element element, ParseStrategy strategy) throws CamException {
        return new ConstraintManager(element, strategy);
    }

    private ConstraintManager(Element element, ParseStrategy strategy) throws CamException {
        initConstraints(element, strategy);
        bindConstraintsToXpath();
    }

    public Map<String, List<Constraint>> getGroupedConstraints() {
        return groupedConstraints;
    }

    private void initConstraints(Element element, ParseStrategy strategy) throws CamException {
        if (strategy == ParseStrategy.COMPILE) {
            initRawTemplateConstraints(element);
        } else if (strategy == ParseStrategy.DECOMPILE) {
            initCompiledTemplateConstraints(element);
        }
    }

    private void initRawTemplateConstraints(Element contextNode) throws CamException {
        //noinspection unchecked
        for (Element constraintNode : (List<Element>) contextNode.getChildren()) {
            constraints.add(ModelFactory.createConstraint(constraintNode));
        }
    }

    private void initCompiledTemplateConstraints(Element element) throws CamException {
        //todo
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

}
