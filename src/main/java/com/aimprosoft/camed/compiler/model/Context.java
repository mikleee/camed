package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Element;
import org.jdom.JDOMException;

public class Context extends Rule {

    private String condition = null;
    private String ID = "";
    private String description = "";

    public Context(RuleCategory cat) {
        super();
        setType(RuleType.context);
        setCategory(cat);

    }

    public Context(Element context, RuleCategory cat) throws Exception {
        super();
        setType(RuleType.context);
        setCategory(cat);
        //setElement(context);
        if (!context.getName().equals("context")) {
            throw new JDOMException("Element should be a Context:" + context.getName());
        } else {

            if (context.getChildren().size() == 0) {
                return;
                //throw new JDOMException("Context must have child rules");
            }
            setID(context.getAttributeValue("ID"));
            setCondition(context.getAttributeValue("condition"));
            if (context.getChild("Description", CAMConstants.CAMNamespace) != null)
                setDescription(context.getChildText("Description", CAMConstants.CAMNamespace));
        }
    }

    public String getCondition() {
        return condition;
    }

    public void setCondition(String condition) {
        this.condition = condition;
    }

    public String getID() {
        return ID;
    }

    public void setID(String id) {
        ID = id;
    }

    public Element toXML() {
        Element contx = new Element("context", CAMConstants.CAMNamespace);
        if (getID() != null && getID().length() > 0) {
            contx.setAttribute("ID", getID());
        }

        if (getCondition() != null && getCondition().length() > 0)
            contx.setAttribute("condition", getCondition());
        if (getDescription().length() > 0) {
            Element desc = new Element("Description", CAMConstants.CAMNamespace);
            desc.setText(getDescription());
            contx.addContent(desc);
        }

        for (Rule childRule : getTemplate().getRuleManager().getRuleMap().values()) {
            if (childRule.getParentUUID() != null && childRule.getParentUUID().equals(getUuid())) {
                if (childRule.getType() == RuleType.context)
                    contx.addContent(((Context) childRule).toXML());
                else
                    contx.addContent(((Constraint) childRule).toXML());
            }
        }
        return contx;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getParentCondition(String condition) {
        if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
            if (condition.length() > 0)
                condition = ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition() + " and " + condition;
            else
                condition = ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition();
        }
        return condition;
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
