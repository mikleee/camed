package com.aimprosoft.camed.compiler.util;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.model.impl.Action;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.model.Context;
import com.aimprosoft.camed.compiler.model.Rule;
import com.aimprosoft.camed.compiler.model.impl.CAMTemplate;
import com.aimprosoft.camed.compiler.xpath.Xpath;
import org.jaxen.SimpleNamespaceContext;
import org.jdom.Document;

import java.util.*;
import java.util.Map.Entry;

public class RuleManager {

    public RuleManager(CAMTemplate template) {
        this.template = template;
    }

    CAMTemplate template;
    private Map<String, List<UUID>> xpathRulesMap;
    private Map<UUID, Rule> ruleMap;

    public Map<UUID, Rule> getRuleMap() {
        if (ruleMap == null)
            ruleMap = new HashMap<UUID, Rule>();
        return ruleMap;
    }

    public Rule getRule(UUID ruleUUID) {
        return getRuleMap().get(ruleUUID);
    }

}
