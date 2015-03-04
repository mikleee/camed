package com.aimprosoft.camed.compiler.model.impl;


import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.model.Compilable;
import org.apache.commons.lang.StringEscapeUtils;

import java.util.ArrayList;
import java.util.List;

import static com.aimprosoft.camed.compiler.constants.CAMConstants.QUOTE;

public class Action implements Compilable {

    private ActionType action;
    private String condition;
    private String xPath;
    private List<String> actionParameters = new ArrayList<String>();

    private int orderNumber; //todo

    public Action(String condition, String xPath) {
        this.condition = StringEscapeUtils.escapeXml(condition);
        this.xPath = xPath;
    }

    public void setOrderNumber(int orderNumber) {
        this.orderNumber = orderNumber;
    }

    public ActionType getAction() {
        return action;
    }

    public void setAction(ActionType action) {
        this.action = action;
    }

    public void setActionParameters(List<String> actionParameters) {
        this.actionParameters.clear();
        for (String param : actionParameters) {
            if (param.length() > 0) {
                this.actionParameters.add(param);
            }
        }
        this.actionParameters = actionParameters;
    }


    @Override
    public String compile() throws CAMCompilerException {
        String result;

        if (action == ActionType.setChoice || action == ActionType.makeRepeatable) {
            result = compileSpecialAction();
        } else {
            result = compileCommonAction();
        }

        return result;
    }

    private String compileCommonAction() {
        String param = actionParametersToString();

        StringBuilder builder = new StringBuilder()
                .append(" ")
                .append(action.toString())
                .append(orderNumber != 0 ? "_" + orderNumber : "")
                .append("=" + QUOTE)
                .append(param.isEmpty() ? "true" : param);

        if (condition != null) {
            builder.append("?").append(condition);
        }

        builder.append(QUOTE + " ");
        return builder.toString();
    }

    private String compileSpecialAction() {
        StringBuilder builder = new StringBuilder()
                .append(" ")
                .append(action)
                .append("=" + QUOTE)
                .append(xPath);

        if (condition != null) {
            builder.append("?").append(condition);
        }

        builder.append(QUOTE);
        return builder.toString();
    }

    public String actionParametersToString() {
        StringBuilder params = new StringBuilder();
        for (String parameter : actionParameters) {
            params.append(parameter);
        }
        return params.toString();
    }

}
