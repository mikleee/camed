package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.JDOMException;
import com.aimprosoft.camed.compiler.model.Action.ActionType;
import com.aimprosoft.camed.compiler.util.Parser;
import com.aimprosoft.camed.compiler.util.Parser.ParserException;

import java.io.IOException;
import java.io.Writer;
import java.rmi.server.UID;
import java.util.ArrayList;
import java.util.List;

public class Constraint extends Rule {

    private boolean elementStyle = false;
    private String condition = "";
    private List<Action> actions = new ArrayList<Action>();
    private Annotation annotation = null;

    private String item = "";

    public Constraint(RuleCategory cat) {
        super();
        setType(RuleType.constraint);
        setCategory(cat);
    }

    @SuppressWarnings("unchecked")
    public Constraint(Element constraint, RuleCategory cat)
            throws Exception {
        super();
        setType(RuleType.constraint);
        setCategory(cat);
        // Element element = (Element) constraint.clone();
        // setElement((Element)element.detach());
        // derive from xml constraint
        if (!constraint.getName().equals("constraint")) {
            throw new JDOMException("Element should be a Constraint:"
                    + constraint.getName());
        } else {
            setCondition(constraint.getAttributeValue("condition"));
            if (constraint.getChild("annotation", CAMConstants.CAMNamespace) != null)
                setAnnotation(constraint.getChild("annotation",
                        CAMConstants.CAMNamespace));
            if (constraint.getAttribute("item") != null) {
                // item attribute exists therefore actions are elements
                setItem(constraint.getAttributeValue("item"));
                List<Element> acts = constraint.getChildren("action",
                        CAMConstants.CAMNamespace);
                for (Element act : acts) {
                    try {
                        Parser P = CAMTemplate.getParser();
                        P.makeParser(act.getTextNormalize(), Boolean.TRUE);
                        Parser.Expression expr = P.getExpression();
                        Action action = new Action();
                        action.setAction(ActionType.valueOf(expr
                                .getName()));
                        if (!action.getAction().equals(
                                ActionType.restrictValues)) {
                            List<String> params = new ArrayList<String>();
                            for (int i = 0; i < expr.getParts().length; i++) {
                                if (expr.getPart(i) != null) {
                                    params.add(expr.getPart(i));
                                }
                            }
                            action.setActionParameters(params);
                        } else if (action.getAction().equals(
                                ActionType.restrictValues)) {
                            String parameters = constraint.getAttributeValue(
                                    "action").substring(
                                    constraint.getAttributeValue("action")
                                            .indexOf('(')
                                            + getItem().length()
                                            + 2,
                                    constraint.getAttributeValue("action")
                                            .lastIndexOf(')'));

                            action.setActionParameters(parseParameters(parameters
                                    .split("''")));

                        }
                        addAction(action);
                    } catch (ParserException e) {
                        throw new JDOMException("Parser Exception:\nAction = "
                                + act.getTextNormalize() + "\n"
                                + e.getMessage());
                    }
                }
            } else if (constraint.getAttribute("action") != null) {
                // action attribute must exist
                try {
                    Parser P = CAMTemplate.getParser();
                    P.makeParser(constraint.getAttributeValue("action"),
                            Boolean.TRUE);
                    Parser.Expression expr = P.getExpression();
                    Action action = new Action();
                    action.setAction(ActionType.valueOf(expr.getName()));
                    setItem(P.getExpression().getPart(0));
                    if (!action.getAction().equals(ActionType.restrictValues)) {
                        List<String> params = new ArrayList<String>();
                        for (int i = 1; i < expr.getParts().length; i++) {
                            if (expr.getPart(i) != null) {
                                params.add(expr.getPart(i));
                            }
                        }
                        if (action.getAction().equals(ActionType.setChoice)) {
                            UID uid = new UID();
                            params.add(uid.toString().replace(':', '-'));
                        }
                        action.setActionParameters(params);
                    } else if (action.getAction().equals(
                            ActionType.restrictValues)) {
                        String parameters = constraint.getAttributeValue(
                                "action").substring(
                                constraint.getAttributeValue("action").indexOf(
                                        '(')
                                        + getItem().length() + 2,
                                constraint.getAttributeValue("action")
                                        .lastIndexOf(')'));
                        action.setActionParameters(parseParameters(parameters
                                .split("''")));
                    }
                    addAction(action);
                } catch (ParserException e) {
                    throw new JDOMException("Parser Exception:\nAction = "
                            + constraint.getAttribute("action") + "\n"
                            + e.getMessage());
                }
            } else {
                throw new JDOMException("Constraint malformed");
            }
        }

    }

    private List<String> parseParameters(String[] parts) {
        List<String> params = new ArrayList<String>();
        for (String part : parts) {
            String param = part;
            if (!param.startsWith("'"))
                param = "'" + param;
            if (!param.endsWith("'"))
                param = param + "'";
            params.add(param);
        }
        return params;
    }

    /**
     * @return Returns the condition.
     */
    public String getCondition() {
        return condition;
    }

    /**
     * @param condition The condition to set.
     */
    public void setCondition(String condition) {
        this.condition = condition;
    }

    /**
     * @return Returns the item.
     */
    public String getItem() {
        return item;
    }

    /**
     * @param item The item to set.
     */
    public void setItem(String item) {
        this.item = item;
    }

    public List<Action> getActions() {
        return actions;
    }

    public void setActions(List<Action> actions) {
        this.actions = actions;
    }

    public boolean addAction(Action arg0) {
        return actions.add(arg0);
    }

    public Action removeAction(int arg0) {
        return actions.remove(arg0);
    }

    public int actionSize() {
        return actions.size();
    }

    public Element toXML() {
        Element constraint = new Element("constraint", CAMConstants.CAMNamespace);
        if (elementStyle || getActions().size() > 1) {
            if (getCondition() != null) {
                constraint.setAttribute("condition", getCondition());
            }
            constraint.setAttribute(new Attribute("item", getItem()));
            for (Action act : getActions()) {
                constraint.addContent(act.toXML());
            }
        } else {
            if (getCondition() != null && getCondition().length() > 0) {
                constraint.setAttribute("condition", getCondition());
            }
            int i = 0;
            for (Action act : getActions()) {
                if (i == 0) {
                    if (act.getActionParameters().size() > 0
                            && !act.getAction().equals(ActionType.setChoice))
                        constraint.setAttribute("action",
                                act.getAction().toString() + "(" + getItem()
                                        + "," + act.actionParametersToString()
                                        + ")");
                    else
                        constraint.setAttribute("action", act.getAction()
                                .toString() + "(" + getItem() + ")");
                }
            }
        }
        if (getAnnotation() != null) {
            Element anno = annotationToXML();
            if (anno != null)
                constraint.addContent(annotationToXML());
        }
        return constraint;
    }

    public Element toDoc() {
        Element constraint = new Element("constraint", CAMConstants.CAMNamespace);
        if (elementStyle || getActions().size() > 1) {
            String condition = "";
            if (getCondition() != null) {
                condition = getCondition();
            }
            if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
                condition = getParentCondition(condition);
                constraint.setAttribute("context", getParentCondition());
            }
            if (condition != null && condition.length() > 1)
                constraint.setAttribute("condition", condition);
            constraint.setAttribute(new Attribute("item", getItem()));
            for (Action act : getActions()) {
                constraint.addContent(act.toXML());
            }
        } else {
            String condition = "";
            if (getCondition() != null) {
                condition = getCondition();
            }
            if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
                condition = getParentCondition(condition);
                if (getParentCondition() != null)
                    constraint.setAttribute("context", getParentCondition());
            }
            if (condition != null && condition.length() > 1)
                constraint.setAttribute("condition", condition);
            int i = 0;
            for (Action act : getActions()) {
                if (i == 0) {
                    if (act.getAction().equals(ActionType.setChoice)) {
                        constraint.setAttribute("action", act.getAction()
                                .toString() + "(" + getItem() + ")");
                    } else if (act.getActionParameters().size() > 0)
                        constraint.setAttribute(
                                "action",
                                act.getAction().toString() + "("
                                        + act.actionParametersToString() + ")");
                    else
                        constraint.setAttribute("action", act.getAction()
                                .toString() + "()");
                }
            }
        }
        if (getAnnotation() != null) {
            Element anno = annotationToXML();
            if (anno != null)
                constraint.addContent(annotationToXML());
        }
        constraint.setAttribute("xpath", getItem());
        return constraint;
    }

    private String getParentCondition(String condition) {
        if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
            if (condition.trim().length() > 0 &&
                    ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition() != null)
                condition = ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition() + " and " + condition;
            else if (((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition() != null)
                condition = ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition();
            if (getTemplate().getRuleManager().getRule(getParentUUID()).getParentUUID() != null)
                return ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getParentCondition(condition);
        }
        return condition;
    }

    private String getParentCondition() {
        String condition = "";
        if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
            condition = ((Context) getTemplate().getRuleManager().getRule(getParentUUID())).getCondition();
            if (condition != null && condition.trim().length() > 0)
                return condition;
        }
        return null;
    }

    public String toString() {
        StringBuilder output = new StringBuilder();
        output.append("constraint");
        if (getCondition() != null) {
            output.append(" condition=").append(getCondition()).append("\"");
        }
        for (Action act : getActions()) {
            output.append("(").append(act.toString(getItem())).append(");");
        }

        return output.toString();
    }

    public Annotation getAnnotation() {
        return annotation;
    }

    public void setAnnotation(Element element) {
        annotation = new Annotation(element);
    }

    public void setInitialAnnotation(String type, String text) {
        if (annotation == null)
            annotation = new Annotation(type, text);
        else
            annotation.setFirstDocumentationText(type, text);
    }

    public Element annotationToXML() {
        return annotation.toXML();
    }

    public String getFirstActionString() {
        Action act = getActions().get(0);
        if (act.getActionParameters().size() > 0)
            return act.getAction().toString() + "(" + getItem() + ","
                    + act.actionParametersToString() + ")";
        else
            return act.getAction().toString() + "(" + getItem() + ")";
    }

    public Action getFirstAction() {
        if (getActions().size() > 0)
            return getActions().get(0);
        else
            return null;
    }

    public void removeCondition() {
        condition = null;

    }

    public void toCXF(Writer out, boolean full, int count) throws IOException {
        if (full)
            out.write("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
                    + "constraint" + " ");
        if (elementStyle || getActions().size() > 1) {
            String condition = "";
            if (getCondition() != null) {
                condition = getCondition();
            }
            if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
                condition = getParentCondition(condition);
                out.write(" " + "context" + "=\""
                        + StringEscapeUtils.escapeXml(getParentCondition())
                        + "\" ");
            }
            if (condition != null && condition.length() > 1)
                out.write(" " + "condition" + "=\""
                        + StringEscapeUtils.escapeXml(condition) + "\" ");
            out.write(" " + "item" + "=\""
                    + StringEscapeUtils.escapeXml(getItem()) + "\" ");
            if (full)
                out.write(" " + "xpath" + "=\""
                        + StringEscapeUtils.escapeXml(getItem()) + "\" ");
            out.write(">");
            for (Action act : getActions()) {
                if (full) {
                    act.toCXF(out, getItem());
                } else {
                    out.write(act.toCXF(count));
                }
            }
            if (full)
                out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                        + "constraint" + ">\n");
        } else {
            String condition = "";
            if (getCondition() != null) {
                condition = getCondition();
            }
            if (getParentUUID() != null && getTemplate().getRuleManager().getRule(getParentUUID()).getType().equals(RuleType.context)) {
                condition = getParentCondition(condition);
                if (getParentCondition() != null)
                    if (full)
                        out.write(" "
                                + "context"
                                + "=\""
                                + StringEscapeUtils
                                .escapeXml(getParentCondition())
                                + "\" ");
            }
            if (full && condition != null && condition.length() > 1) {
                out.write(" " + "condition" + "=\""
                        + StringEscapeUtils.escapeXml(condition) + "\" ");
            }
            int i = 0;
            for (Action act : getActions()) {
                if (i == 0) {
                    if (full) {
                        if (act.getAction().equals(ActionType.setChoice)) {
                            out.write(" "
                                    + "action"
                                    + "=\""
                                    + StringEscapeUtils.escapeXml(act
                                    .getAction().toString()
                                    + "("
                                    + getItem() + ")") + "\" ");
                        } else if (act.getActionParameters().size() > 0) {
                            out.write(" "
                                    + "action"
                                    + "=\""
                                    + StringEscapeUtils.escapeXml(act
                                    .getAction().toString()
                                    + "("
                                    + act.actionParametersToString()
                                    + ")") + "\" ");
                        } else {
                            out.write(" "
                                    + "action"
                                    + "=\""
                                    + StringEscapeUtils.escapeXml(act
                                    .getAction().toString() + "()")
                                    + "\" ");
                        }
                    } else {
                        if (act.getAction().equals(ActionType.setChoice)) {
                            if (condition != null && condition.length() > 1) {
                                out.write(" "
                                        + "setChoice"
                                        + "=\""
                                        + getItem()
                                        + "?"
                                        + StringEscapeUtils
                                        .escapeXml(condition) + "\" ");
                            } else {
                                out.write(" " + "setChoice" + "=\"" + getItem()
                                        + "\" ");
                            }
                        } else if (act.getAction().equals(
                                ActionType.makeRepeatable)) {
                            if (condition != null && condition.length() > 1) {
                                out.write(" "
                                        + "makeRepeatable"
                                        + "=\""
                                        + getItem()
                                        + "?"
                                        + StringEscapeUtils
                                        .escapeXml(condition) + "\" ");
                            } else {
                                out.write(" " + "makeRepeatable" + "=\""
                                        + getItem() + "\" ");
                            }
                        } else {
                            if (condition != null && condition.length() > 1) {
                                out.write(act.toCXF(
                                        StringEscapeUtils.escapeXml(condition),
                                        count));
                            } else {
                                out.write(act.toCXF(count));
                            }
                        }

                    }
                }
            }
            if (full) {
                out.write(" " + "xpath" + "=\""
                        + StringEscapeUtils.escapeXml(getItem()) + "\" ");
                out.write(">");
            }
        }

        if (full && getAnnotation() != null
                && getAnnotation().getDocumentationSize() > 0) {
            AnnotationToCXF(out);
        }
        if (full)
            out.write("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
                    + "constraint" + ">\n");
    }

    private void AnnotationToCXF(Writer out) throws IOException {
        annotation.toCXF(out);

    }

    @Override
    public String getXpath() {
        return getItem();
    }

    @Override
    public void setXpath(String xpath) {
        setItem(xpath);
    }

}
