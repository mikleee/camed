package com.aimprosoft.camed.compiler.model;


import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class Action implements Compilable {


    private ActionType action;
    private String condition;
    private String xPath;
    private List<String> actionParameters = new ArrayList<String>();

    private int orderNumber; //todo

    public Action() {
    }

    public Action(String condition, String xPath) {
        this.condition = StringEscapeUtils.escapeXml(condition);
        this.xPath = xPath;
    }

    public int getOrderNumber() {
        return orderNumber;
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

    public List<String> getActionParameters() {
        return actionParameters;
    }

    public void setActionParameters(List<String> actionParameters) {
        this.actionParameters.clear();
        for (String param : actionParameters) {
            if (param.length() > 0)
                this.actionParameters.add(param);

        }
        this.actionParameters = actionParameters;
    }

    public Element toXML() {
        Element action = new Element("action", CAMConstants.CAMNamespace);
        action.addContent(this.action + "(" + actionParametersToString() + ")");
        return action;
    }


    public String actionParametersToString() {
        StringBuilder params = new StringBuilder();
        for (String parameter : actionParameters) {
            params.append(parameter);
        }
        return params.toString();
    }

    @Override
    public String toString() {
        return this.action.toString() + "(" + actionParametersToString() + ")";
    }

    public String toCXF() {
        String param = actionParametersToString();
        return this.action.toString() + "=\"" + (param.length() > 0 ? param : "true") + "\" ";
    }

    public String toCXF(String condition, int count) {
        String param = actionParametersToString();
        return " " + this.action.toString() + (count != -1 ? "_" + String.valueOf(count) : "") + "=\"" + (param.length() > 0 ? param : "true") + "?" + condition + "\" ";
    }

    public String toStringScreen() {
        if (this.action.equals(ActionType.setChoice)) {
            return this.action.toString() + "()";
        }
        return this.action.toString() + "(" + actionParametersToString() + ")";
    }

    public String toString(String item) {
        if (actionParametersToString().length() > 0)
            return this.action.toString() + "(" + item + "," + actionParametersToString() + ")";
        else
            return this.action.toString() + "(" + item + ")";
    }

    public void toCXF(Writer out, String item) throws IOException {
        Namespace namespace = CAMConstants.CAMNamespace;
        out.write("<" + namespace.getPrefix() + ":" + "action" + ">" + StringEscapeUtils.escapeXml(item) + "</" + namespace.getPrefix() + ":" + "action" + ">\n");
    }

    public String toCXF(int count) {
        String param = actionParametersToString();
        return this.action.toString() + (count != -1 ? "_" + String.valueOf(count) : "") + "=\"" + (param.length() > 0 ? param : "true") + "\" ";
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
                .append(orderNumber != 0 ? "_" + String.valueOf(orderNumber) : "")
                .append("=\"")
                .append(param.isEmpty() ? "true" : param);

        if (condition != null) {
            builder.append("?").append(condition);
        }

        builder.append("\" ");
        return builder.toString();
    }

    private String compileSpecialAction() {
        StringBuilder builder = new StringBuilder()
                .append(" ")
                .append(action)
                .append("=\"")
                .append(xPath);

        if (condition != null) {
            builder
                    .append("?")
                    .append(condition);
        }

        builder.append("\" ");
        return builder.toString();
    }

}
