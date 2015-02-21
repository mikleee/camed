package com.aimprosoft.camed.compiler.service.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.service.ElementBuilder;
import com.aimprosoft.camed.compiler.util.Parser;
import org.jdom.Attribute;
import org.jdom.Element;

import java.rmi.server.UID;
import java.util.ArrayList;
import java.util.List;

/**
 * author m.tkachenko
 */
public class ConstraintBuilder implements ElementBuilder {

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

        String condition = element.getAttributeValue("condition");
        Element annotation = element.getChild("annotation", CAMConstants.CAMNamespace);

        constraint.setType(Rule.RuleType.constraint);
        constraint.setCondition(condition);
        constraint.setCategory(condition == null ? Rule.RuleCategory.DEFAULT : Rule.RuleCategory.CONDITIONAL);

        if (annotation != null) {
            constraint.setAnnotation(annotation);
        }

        if (itemAttribute != null) {
            // item attribute exists therefore actions are elements
            constraint.setItem(itemAttribute.getValue());

            List<Element> actions = element.getChildren("action", CAMConstants.CAMNamespace);

            for (Element action : actions) {
                try {

                    Parser.Expression parserExpression = createParserExpression(action.getTextNormalize());

                    Action result = new Action();

                    result.setAction(Action.ActionType.valueOf(parserExpression.getName()));

                    if (!result.getAction().equals(Action.ActionType.restrictValues)) {

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
                    throw new CAMCompilerException("Parser Exception:\nAction = " + action.getTextNormalize() + "\n" + e.getMessage());
                }
            }
        } else if (actionAttribute != null) {
            // action attribute must exist
            try {

                Parser.Expression parserExpression = createParserExpression(actionAttribute.getValue());

                Action result = new Action();
                result.setAction(Action.ActionType.valueOf(parserExpression.getName()));
                constraint.setItem(parserExpression.getPart(0));

                if (!result.getAction().equals(Action.ActionType.restrictValues)) {

                    List<String> params = new ArrayList<String>();
                    for (int i = 1; i < parserExpression.getParts().length; i++) {
                        if (parserExpression.getPart(i) != null) {
                            params.add(parserExpression.getPart(i));
                        }
                    }
                    if (result.getAction().equals(Action.ActionType.setChoice)) {
                        UID uid = new UID();
                        params.add(uid.toString().replace(':', '-'));
                    }
                    result.setActionParameters(params);

                } else if (result.getAction().equals(Action.ActionType.restrictValues)) {

                    String actionValue = actionAttribute.getValue();

                    String parameters = actionValue.substring(
                            actionValue.indexOf('(') + constraint.getItem().length() + 2,
                            actionValue.lastIndexOf(')')
                    );

                    List<String> paramList = parseParameters(parameters);
                    result.setActionParameters(paramList);

                }

                constraint.addAction(result);
            } catch (CAMCompilerException e) {
                throw new CAMCompilerException("Parser Exception:\nAction = " + actionAttribute + "\n" + e.getMessage());
            }
        } else {
            throw new CAMCompilerException("Constraint malformed");
        }

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
            Parser parser = new Parser();
            parser.makeParser(inputString, true);
            return parser.getExpression();
        } catch (Parser.ParserException e) {
            throw new CAMCompilerException(e.getMessage());
        }
    }

}
