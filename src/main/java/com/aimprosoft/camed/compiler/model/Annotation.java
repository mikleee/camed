package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.Namespace;

import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class Annotation {
	
	List<Documentation> documentation_;
	
	private Namespace namespace_ = CAMConstants.CAMNamespace;
	
	public Annotation(List<Documentation> documentation){
		documentation_ = documentation;
	}
	
	public Annotation(Namespace namespace){
		namespace_ = namespace;
	}
	
	public Annotation(Element element){
		setAnnotation(element); 
	}

	@SuppressWarnings("unchecked")
	public void setAnnotation(Element element) {
		if (element.getName().equals("annotation") && element.getNamespace().equals(namespace_)){
			if (element.getChildren("documentation",namespace_).size() > 0){
				documentation_ = new ArrayList<Documentation>();
				for (Element docu: (List<Element>)element.getChildren("documentation",namespace_)){
						Attribute type = docu.getAttribute("type");
						String text = docu.getText();
						if (type == null){
							continue;
						}
						documentation_.add(new Documentation(namespace_,type.getValue(),text));
				}
			} else {
				//handle case where people forget the documentation element and just have text
				if (element.getText().length() > 0){
					setFirstDocumentationText("Definition", element.getText());
				}
			}
		}
	}

	public Annotation(String type, String text) {
		if (documentation_ == null){
			documentation_ = new ArrayList<Documentation>();
			documentation_.add(new Documentation(type,text));
		} else {
			documentation_.set(0,new Documentation(type,text));
		}
		
	}

	public String getFirstDocumentationText(){
		if (documentation_ == null)
			return "";
		else
			return documentation_.get(0).getText();
	}
	
	public void setFirstDocumentationText(String type, String text){
		if (documentation_ == null){
			documentation_ = new ArrayList<Documentation>();
			documentation_.add(new Documentation(namespace_,type,text));
		}
		else{
			documentation_.get(0).setType(type);
			documentation_.get(0).setText(text);
		}
	}
	
	public Collection<Documentation> getDocumentation() {
		return documentation_;
	}

	public int getDocumentationSize(){
		return documentation_!=null?documentation_.size():0;
	}
	
	
	public void setDocumentation(List<Documentation> documentation) {
		this.documentation_ = documentation;
	}
	
	public void updateDocumentation(String text, String type, int index){
		if (index < 0 || index > this.documentation_.size())
			return;
		if (text != null)
			documentation_.get(index).setText(text);
		if (type != null)
			documentation_.get(index).setType(type);
	}

	public Element toXML() {
		Element ann = null;
		if (this.documentation_ != null && this.documentation_.size() > 0) {
			ann = new Element("annotation", namespace_);
			for (Documentation documentation : documentation_) {
				Element docu = documentation.toXML();
				if (docu != null) {
					ann.addContent(docu);
				}
			}
		}
		return ann!=null&&ann.getChildren().size() != 0? ann:null;
	}
	
	public boolean typeExists(String type) {
		if (documentation_ != null)
			for (Documentation doc : documentation_) {
				if (doc.getType().equals(type)) {
					return true;
				}
			}
		return false;
	}



	public Namespace getNamespace() {
		return namespace_;
	}



	public void setNamespace(Namespace namespace) {
		namespace_ = namespace;
	}

	public void toCXF(Writer out) throws IOException {
		if (this.documentation_ != null) {
			out.write("<" + namespace_.getPrefix() + ":" + "annotation" + ">");
			for (Documentation documentation : documentation_) {
				documentation.toCXF(out);
			}
			out.write("</" + namespace_.getPrefix() + ":" + "annotation" + ">");
		}
	}

}

