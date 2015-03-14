package com.aimprosoft.camed.service.compiler;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.model.impl.Action;
import com.aimprosoft.camed.model.impl.CamTemplate;
import com.aimprosoft.camed.model.impl.Constraint;
import com.aimprosoft.camed.util.XPathFunctions;
import org.jdom.Attribute;
import org.jdom.Element;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

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

    public List<Constraint> findNodeConstraints(Object node, CamTemplate template) throws CamException {
        if (node instanceof Element) {
            return getConstraints((Element) node, template);
        } else if (node instanceof Attribute) {
            return getConstraints((Attribute) node, template);
        } else {
            return null; // it wont be happen
        }
    }

    private List<Constraint> getConstraints(Element element, CamTemplate template) throws CamException {
        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();
        Set<String> variations = XPathFunctions.getXpathVariation(element);

        List<Constraint> result = new ArrayList<Constraint>();
        for (String boundXPath : groupedConstraints.keySet()) {
            if (!XPathFunctions.isAttributePath(boundXPath)) {

                for (String variation : variations) {
                    if (variation.equals(boundXPath)) {
                        result.addAll(groupedConstraints.get(boundXPath));
                        break;
                    }
                }

            }
        }

        return assignOrderNumbers(result);
    }

    private List<Constraint> getConstraints(Attribute attribute, CamTemplate template) throws CamException {
        Map<String, List<Constraint>> groupedConstraints = template.getConstraintManager().getGroupedConstraints();
        Set<String> variations = XPathFunctions.getXpathVariation(attribute);

        List<Constraint> result = new ArrayList<Constraint>();
        for (String boundXPath : groupedConstraints.keySet()) {
            if (XPathFunctions.isAttributePath(boundXPath)) {

                for (String variation : variations) {
                    if (variation.equals(boundXPath)) {
                        result.addAll(groupedConstraints.get(boundXPath));
                        break;
                    }
                }

            }
        }

        return assignOrderNumbers(result);
    }

    private List<Constraint> assignOrderNumbers(List<Constraint> constraintGroup) {
        for (int i = 0; i < constraintGroup.size(); i++) {
            Constraint constraint = constraintGroup.get(i);
            for (Action action : constraint.getActions()) {
                action.setOrderNumber(i + 1);
            }
        }
        return constraintGroup;
    }

}
