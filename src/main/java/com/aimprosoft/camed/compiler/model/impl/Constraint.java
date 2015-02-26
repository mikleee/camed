package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.ActionType;
import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.constants.RuleType;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.util.Parser;
import com.aimprosoft.camed.compiler.util.Parser.ParserException;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.JDOMException;

import java.io.IOException;
import java.io.Writer;
import java.rmi.server.UID;
import java.util.ArrayList;
import java.util.List;

public class Constraint extends Rule implements Compilable {

    private String condition = "";
    private List<Action> actions = new ArrayList<Action>();
    private Annotation annotation = null;

    private String item = "";

    public Constraint() {
        super();
        setType(RuleType.CONSTRAINT);
    }

    public String getCondition() {
        return condition;
    }

    public void setCondition(String condition) {
        this.condition = condition;
    }

    public String getItem() {
        return item;
    }

    public void setItem(String item) {
        this.item = item;
    }

    public List<Action> getActions() {
        return actions;
    }

    public boolean addAction(Action arg0) {
        return actions.add(arg0);
    }

    public void setAnnotation(Element element) {
        annotation = new Annotation(element);
    }

    @Override
    public String getXpath() {
        return getItem();
    }

    @Override
    public void setXpath(String xpath) {
        setItem(xpath);
    }


    @Override
    public String compile() throws CAMCompilerException {

        StringBuilder result = new StringBuilder();

        for (Action action : getActions()) {
            String compiledAction = action.compile();
            result.append(compiledAction);
        }

        return result.toString();
    }

}
