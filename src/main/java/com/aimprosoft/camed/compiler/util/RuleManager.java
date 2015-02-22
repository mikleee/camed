package com.aimprosoft.camed.compiler.util;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import org.jaxen.SimpleNamespaceContext;
import org.jdom.Document;
import com.aimprosoft.camed.compiler.model.*;
import com.aimprosoft.camed.compiler.xpath.Xpath;

import java.util.*;
import java.util.Map.Entry;

public class RuleManager {

    public RuleManager(CAMTemplate template) {
        this.template = template;
    }

    CAMTemplate template;
    private Map<String, List<UUID>> xpathRulesMap;
    private Map<UUID, Rule> ruleMap;


    public List<Rule> getRootRules() {
        List<Rule> rules = null;
        if (getRuleMap().size() > 0) {
            for (Rule rule : getRuleMap().values()) {
                if (rule.getParentUUID() == null) {
                    if (rules == null) {
                        rules = new ArrayList<Rule>();
                    }
                    if (rule instanceof Context
                            && ((Context) rule).getCondition() == null) {
                        rules.add(0, rule);
                    } else {
                        rules.add(rule);
                    }
                }
            }
        }
        return rules;
    }


    public Map<UUID, Rule> getRuleMap() {
        if (ruleMap == null)
            ruleMap = new HashMap<UUID, Rule>();
        return ruleMap;
    }

    private boolean isRuleExists(Rule rule) throws Exception {
        if (rule instanceof Constraint && rule.getXpath() != null && rule.getCategory().equals(RuleCategory.DEFAULT)) {
            Action action = ((Constraint) rule).getActions().get(0);
            if (rule.getXpath().contains("[")) {
                Document structureDocument = template.toDocument();
                Xpath xpath = new Xpath();
                SimpleNamespaceContext ns = template.getNamespaceContext();
                xpath.setUpXPath(rule.getXpath(), ns);
                for (Object node : xpath.getXPath().selectNodes(structureDocument)) {
                    if (getXpathRulesMap().containsKey(XPathFunctions.xpath(node))) {
                        for (UUID uuid : getXpathRulesMap().get(XPathFunctions.xpath(node))) {
                            if (((Constraint) getRuleMap().get(uuid)).getActions().get(0).equals(action))
                                return true;
                        }
                    }
                }
            } else {
                if (getXpathRulesMap().containsKey(rule.getXpath())) {
                    for (UUID uuid : getXpathRulesMap().get(rule.getXpath())) {
                        if (((Constraint) getRuleMap().get(uuid)).getActions().get(0).getAction().equals(action.getAction()))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    private Map<String, List<UUID>> getXpathRulesMap() throws Exception {
        if (xpathRulesMap == null || xpathRulesMap.isEmpty())
            setUpXpathRulesMap();
        return xpathRulesMap;
    }

    public void setUpXpathRulesMap() throws Exception {
        this.xpathRulesMap = new HashMap<String, List<UUID>>();
        String item = null;
        Document structureDocument = template.toDocument();
        Xpath xpath = new Xpath();
        SimpleNamespaceContext ns = template.getNamespaceContext();
        for (Entry<UUID, Rule> ruleEntry : getRuleMap().entrySet()) {
            item = ruleEntry.getValue().getXpath();
            if (item != null) {
                if (!item.contains("[")) {
                    addXpathRule(item, ruleEntry.getKey());
                } else {
                    xpath.setUpXPath(item, ns);
                    for (Object node : xpath.getXPath().selectNodes(
                            structureDocument)) {
                        addXpathRule(XPathFunctions.xpath(node),
                                ruleEntry.getKey());
                    }
                }
            }
        }
    }

    private void addXpathRule(String xpath, UUID uuid) throws Exception {
        if (this.xpathRulesMap.containsKey(xpath)) {
            this.xpathRulesMap.get(xpath).add(uuid);
        } else {
            List<UUID> list = new ArrayList<UUID>();
            list.add(uuid);
            this.xpathRulesMap.put(xpath, list);
        }
    }

    public List<Rule> getNodeRules(Object node) throws CAMCompilerException {
        try {
            List<Rule> rules = new ArrayList<Rule>();
            for (String xpath : XPathFunctions.getXpathVariation(node)) {
                if (getXpathRulesMap().containsKey(xpath))
                    for (UUID uuid : getXpathRulesMap().get(xpath)) {
                        rules.add(getRuleMap().get(uuid));
                    }
            }
            return rules;
        } catch (Exception e) {
            throw new CAMCompilerException(e.getMessage()); //todo
        }
    }

    public Rule getRule(UUID ruleUUID) {
        return getRuleMap().get(ruleUUID);
    }

}
