package com.aimprosoft.camed.compiler.service.builder.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.impl.Action;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.service.builder.ElementBuilder;
import com.aimprosoft.camed.compiler.util.Parser;
import org.jdom.Attribute;
import org.jdom.Element;

import java.rmi.server.UID;
import java.util.ArrayList;
import java.util.List;

/**
 * author m.tkachenko
 */
public class ConstraintBuilder implements ElementBuilder<Compilable> {

    private Constraint constraint;
    private Element element;

    public ConstraintBuilder(Element element) {
        this.constraint = new Constraint();
        this.element = element;
    }


    @Override
    public Constraint build() throws CAMCompilerException {
        validate();

        Attribute itemAttribute = element.getAttribute("item");
        Attribute actionAttribute = element.getAttribute("action");

        String condition = element.getAttributeValue("condition"); //todo
        RuleCategory ruleCategory = condition == null ? RuleCategory.DEFAULT : RuleCategory.CONDITIONAL;

        constraint.setCondition(condition);
        constraint.setCategory(ruleCategory);

        String xPath;

        if (itemAttribute != null) {
            // item attribute exists therefore actions are elements
            xPath = itemAttribute.getValue();

            //noinspection unchecked
            List<Element> actions = element.getChildren("action", CAMConstants.CAM_NAMESPACE);

            for (Element action : actions) {
                try {

                    Parser.Expression parserExpression = createParserExpression(action.getTextNormalize());

                    Action result = new Action(condition, xPath);

                    result.setAction(ActionType.valueOf(parserExpression.getName()));

                    if (!result.getAction().equals(ActionType.restrictValues)) {

                        List<String> params = new ArrayList<String>();
                        for (int i = 0; i < parserExpression.getParts().length; i++) {
                            if (parserExpression.getPart(i) != null) {
                                params.add(parserExpression.getPart(i));
                            }
                        }
                        result.setActionParameters(params);

                    } else {

                        String actionValue = element.getAttributeValue("action");

                        String parameters = actionValue.substring(
                                actionValue.indexOf('(') + itemAttribute.getValue().length() + 2,
                                actionValue.lastIndexOf(')')
                        );

                        List<String> paramList = parseParameters(parameters);
                        result.setActionParameters(paramList);

                    }

                    constraint.addAction(result);
                } catch (CAMCompilerException e) {
                    throw new CAMCompilerException("Parser Exception: Action = " + action.getTextNormalize() + " " + e.getMessage());
                }
            }
        } else if (actionAttribute != null) {
            // action attribute must exist
            try {

                Parser.Expression parserExpression = createParserExpression(actionAttribute.getValue());
                xPath = parserExpression.getPart(0);

                Action result = new Action(condition, xPath);
                result.setAction(ActionType.valueOf(parserExpression.getName()));

                if (!result.getAction().equals(ActionType.restrictValues)) {

                    List<String> params = new ArrayList<String>();
                    for (int i = 1; i < parserExpression.getParts().length; i++) {
                        if (parserExpression.getPart(i) != null) {
                            params.add(parserExpression.getPart(i));
                        }
                    }
                    if (result.getAction().equals(ActionType.setChoice)) {
                        UID uid = new UID();
                        params.add(uid.toString().replace(':', '-'));
                    }
                    result.setActionParameters(params);

                } else if (result.getAction().equals(ActionType.restrictValues)) {

                    String actionValue = actionAttribute.getValue();

                    String parameters = actionValue.substring(
                            actionValue.indexOf('(') + constraint.getXPath().length() + 2,
                            actionValue.lastIndexOf(')')
                    );

                    List<String> paramList = parseParameters(parameters);
                    result.setActionParameters(paramList);

                }

                constraint.addAction(result);
            } catch (CAMCompilerException e) {
                throw new CAMCompilerException("Parser Exception: Action = " + actionAttribute + " " + e.getMessage());
            }
        } else {
            throw new CAMCompilerException("Constraint malformed");
        }

        constraint.setXPath(xPath);
        return constraint;
    }


    private void validate() throws CAMCompilerException {
        if (!element.getName().equals("constraint")) {
            throw new CAMCompilerException("Element should be a Constraint: " + element.getName());
        }
    }

    private List<String> parseParameters(String paramsInString) {
        String[] parts = paramsInString.split("''");

        List<String> params = new ArrayList<String>();
        for (String part : parts) {
            String param = part;
            if (!param.startsWith("'")) {
                param = "'" + param;
            }
            if (!param.endsWith("'")) {
                param = param + "'";
            }
            params.add(param);
        }
        return params;
    }

    private Parser.Expression createParserExpression(String inputString) throws CAMCompilerException {
        try {
            Parser parser = new Parser(inputString, true);
            return parser.getExpression();
        } catch (Parser.ParserException e) {
            throw new CAMCompilerException(e.getMessage());
        }
    }

}