package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.apache.commons.lang.StringEscapeUtils;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.IOException;
import java.io.Writer;


public class Documentation {
	
	private Namespace namespace_ = CAMConstants.CAMNamespace;
	
	private String type_ = "";
	private String text_= "";
	
	public Documentation(String type,String text){
		setText(text);
		setType(type);
	}	
	
	public Documentation(Namespace namespace,String type,String text){
		setNamespace(namespace);
		setText(text);
		setType(type);
	}	

	public String getText() {
		return text_;
	}

	public void setText(String text) {
		this.text_ = text;
	}

	public String getType() {
		return type_;
	}

	public void setType(String type) {
		this.type_ = type;
	}



	public Element toXML() {
		if (getText().trim() != null && getText().trim().length() > 0){
			Element element = new Element("documentation",namespace_);
			element.setText(text_);
			element.setAttribute("type", type_);
			return element;
		} else {
			return null;
		}
	}

	public Namespace getNamespace() {
		return namespace_;
	}

	public void setNamespace(Namespace namespace) {
		this.namespace_ = namespace;
	}

	public void toCXF(Writer out) throws IOException {
		if (getText().trim() != null && getText().trim().length() > 0){
			out.write("<"+namespace_.getPrefix()+":"+"documentation"+" ");
			out.write(" "+"type"+"=\""+StringEscapeUtils.escapeXml(type_)+"\" ");
			out.write(">\n");
			out.write(StringEscapeUtils.escapeXml(text_));
			out.write("</"+namespace_.getPrefix()+":"+"documentation"+">\n");
		}
	}
	
}
