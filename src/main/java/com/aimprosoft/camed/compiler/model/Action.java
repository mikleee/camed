package com.aimprosoft.camed.compiler.model;


import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class Action {
    public enum ActionType {
        makeMandatory(0),
        makeOptional(0),
        makeNillable(1),
        makeRepeatable(0),
        setID(1),
        setChoice(0),
        setDateMask(1),
        setStringMask(1),
        setNumberMask(1),
        setValue(1),
        restrictValues(2),
        setDefault(1),
        setNumberRange(1),
        datatype(1),
        useChoice(0),
        useElement(0),
        useTree(0),
        excludeTree(0),
        excludeElement(0),
        setLimit(1),
        setLength(1),
        makeRecursive(1),
        orderChildren(0),
        //allowAnyContent,
        useAttribute(0),
        excludeAttribute(0),
        lookup(2),
        printMessage(1),
        applyTemplate(2),
        evaluateVariable(1);
        int numOfParams;

        ActionType(int numOfParams) {
            this.numOfParams = numOfParams;
        }

        public int getNumOfParams() {
            return numOfParams;
        }
    }


    public static final String DateMaskText = "Date Masks can either be CAM or Java format\n" +
            "For Java Mask must start with 'J'\n" +
            "CAM Mask Options are:\n" +
            "DD - Day of Month\n" +
            "DDD - Day in Year\n" +
            "DDDD - relative day in Month, i.e. ' 2nd'\n" +
            "MM - Month in number\n" +
            "MMM... - Month is letter (number of 'M' = length required)\n" +
            "YY - last 2 digits of year\n" +
            "YYYY - Full year number - i.e. 2006\n" +
            "W - Day in week\n" +
            "WWW... - Name of day (number of 'W' = length required)\n" +
            "T - if T occurs as the first character of mask then all letter masks are trimmed of extra spaces.";


    public static final String StringMaskText = "String Masks use the following characters:\n" +
            "X - a mandatory character\n" +
            "? - an optional character\n" +
            "* - a series of optional characters\n" +
            "U - a mandatory Uppercase letter\n" +
            "^ - an optional Uppercase letter\n" +
            "L - a mandatory Lowecase letter\n" +
            "_ - (underscore) an optional Lowercase letter\n" +
            "0 - a digit - leading zeros must exist\n" +
            "# - a digit leading zeros may be absent\n" +
            "'' = quoted characters must exist in the string.";


    public static final String NumberMaskText = "Number Masks can either be CAM or Java format\n" +
            "For Java Mask must start with 'J'\n" +
            "CAM Mask Options are:\n" +
            "0 - a digit (0-9)\n" +
            "# - a digit (0-9) trailing or leading zeros may be absent\n" +
            ". - the position of the decimal point";


    private ActionType action;

    private List<String> actionParameters = new ArrayList<String>();

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

}
