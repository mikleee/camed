package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.RuleCategory;
import com.aimprosoft.camed.compiler.constants.RuleType;

import java.util.UUID;

public abstract class Rule implements Cloneable{

    private RuleCategory category;
	private RuleType type;
	private UUID uuid;
	private UUID parentUUID;

    private CAMTemplate template;

	public Rule (){
		setUUID();
	}
	
	public void setUUID(){
		uuid = UUID.randomUUID();
	}

	public RuleCategory getCategory() {
		return category;
	}

	public void setCategory(RuleCategory category) {
		this.category = category;
	}

	public RuleType getType() {
		return type;
	}

	public void setType(RuleType type) {
		this.type = type;
	}

	public UUID getUuid() {
		return uuid;
	}

	public UUID getParentUUID() {
		return parentUUID;
	}

	public void setParentUUID(UUID parentUUID) {
		this.parentUUID = parentUUID;
	}
	
	public Rule cloneRule() throws CloneNotSupportedException{
		return (Rule) clone();
	}

    public CAMTemplate getTemplate() {
        return template;
    }

    public void setTemplate(CAMTemplate template) {
        this.template = template;
    }

    @Override
	protected Object clone() throws CloneNotSupportedException {
		return super.clone();
	}
	
	abstract public String getXpath();
	
	abstract public void setXpath(String xpath);
	
}
