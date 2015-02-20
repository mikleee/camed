package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.model.Rule;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jaxen.JaxenException;
import org.jdom.Element;


import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RuleWrapper implements Compilable {

    private static final String RULE_XPATH = "//as:context";
    private CAMTemplate template;
    private Map<String, Constraint> mapRule = new HashMap<String, Constraint>();



    public RuleWrapper(CAMTemplate template) throws CAMCompilerException {
        this.template = template;
        init();
    }

    @Override
    public String compile() throws CAMCompilerException {
        return null;
    }

    public Map<String, Constraint> getMapRule() {
        return mapRule;
    }

    private void init() throws CAMCompilerException {
        try {
            JDOMXPathAdapter jdomxPathAdapter = new JDOMXPathAdapter(RULE_XPATH, template);
            Element ruleNode = jdomxPathAdapter.selectNode();
            List<Element> children = ruleNode.getChildren();
            for (Element rule : children) {
                addRuleToConstraint(rule);
            }


        } catch (JaxenException e) {
            throw new CAMCompilerException("Element " + RULE_XPATH + " is absent.");
        }
    }

    private void addRuleToConstraint(Element element) {
        try {
            Constraint constraint = new Constraint(element, Rule.RuleCategory.CONDITIONAL);
            mapRule.put(element.getName(), constraint);
        } catch (Exception e) {
            e.printStackTrace(); //todo
        }


    }

}
