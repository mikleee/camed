package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.constants.RuleType;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import org.jdom.Element;
import org.jdom.JDOMException;

public class Context extends Rule {

    private String condition = null;
    private String ID = "";

    public Context(RuleCategory cat) {
        super();
        setType(RuleType.CONTEXT);
        setCategory(cat);

    }

    public String getCondition() {
        return condition;
    }

    public void setCondition(String condition) {
        this.condition = condition;
    }

    @Override
    public String getXpath() {
        return getCondition();
    }

    @Override
    public void setXpath(String xpath) {
        setCondition(xpath);
    }

}
