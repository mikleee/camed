package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.constants.RuleType;
import com.aimprosoft.camed.compiler.model.Compilable;

import java.util.ArrayList;
import java.util.List;

public class Constraint implements Compilable {

    private RuleCategory category;
    private static final RuleType TYPE = RuleType.CONSTRAINT;

    private String condition = "";
    private List<Action> actions = new ArrayList<Action>();

    private String item = "";

    public Constraint() {
        super();
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

    public RuleCategory getCategory() {
        return category;
    }

    public void setCategory(RuleCategory category) {
        this.category = category;
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
