package com.aimprosoft.camed.model.impl;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.constants.RuleCategory;
import com.aimprosoft.camed.constants.RuleType;
import com.aimprosoft.camed.model.Compilable;

import java.util.ArrayList;
import java.util.List;

public class Constraint implements Compilable {

    private RuleCategory category;
    private static final RuleType TYPE = RuleType.CONSTRAINT;

    private String condition = "";
    private List<Action> actions = new ArrayList<Action>();

    private String xPath = "";

    public Constraint() {
        super();
    }

    public String getCondition() {
        return condition;
    }

    public void setCondition(String condition) {
        this.condition = condition;
    }

    public String getXPath() {
        return xPath;
    }

    public void setXPath(String xPath) {
        this.xPath = xPath;
    }

    public List<Action> getActions() {
        return actions;
    }

    public boolean addAction(Action action) {
        return actions.add(action);
    }

    public RuleCategory getCategory() {
        return category;
    }

    public void setCategory(RuleCategory category) {
        this.category = category;
    }

    @Override
    public String compile() throws CamException {

        StringBuilder result = new StringBuilder();

        for (Action action : getActions()) {
            String compiledAction = action.compile();
            result.append(compiledAction);
        }

        return result.toString();
    }

}
