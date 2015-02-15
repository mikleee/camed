package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Element;

import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class Parameter {
    private String name = "";
    private List<String> values = new ArrayList<String>();
    private String defaultValue = "";
    private String datatype = "";
    private String xpath = "";

    public static enum Usage {local, override, global}

    private Usage use;

    public Parameter(String name) {
        this.name = name;
        use = Usage.global;
    }

    public String getDatatype() {
        return datatype;
    }

    public void setDatatype(String datatype) {
        this.datatype = datatype;
    }

    public String getDefaultValue() {
        if (getValues() != null && getValues().size() > 0) {
            if (defaultValue.length() > 0 && !getValues().contains(defaultValue)) {
                return defaultValue + " not allowed";
            }
        }
        return defaultValue;
    }

    public void setDefaultValue(String defaultValue) {
        this.defaultValue = defaultValue;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUse() {
        return use.toString();
    }

    public void setUse(String use) {
        this.use = Usage.valueOf(use);
    }

    public List<String> getValues() {
        return values;
    }

    public void setValues(List<String> values) {
        this.values = values;
    }

    public String getXpath() {
        if (xpath == null || xpath.length() == 0) {
            if (getUse().equals(Usage.local.toString())) {
                return "xpath must exist";
            }
        }
        return xpath;
    }

    public void setXpath(String xpath) {
        if (xpath.equals("xpath must exist")) {
            xpath = "";
        } else {
            this.xpath = xpath;
        }
    }

    public Element toXML() {
        Element par = new Element("Parameter", CAMConstants.CAMNamespace);
        par.setAttribute("name", getName());
        if (getValues().size() > 0) {
            par.setAttribute("values", getValuesString());
        }
        if (getDefaultValue().length() > 0) {
            par.setAttribute("default", getDefaultValue());
        }
        if (getDatatype().length() > 0) {
            par.setAttribute("datatype", getDatatype());
        }
        if (getXpath().length() > 0) {
            par.setAttribute("xpath", getXpath());
        }
        if (getUse().length() > 0) {
            par.setAttribute("use", getUse());
        }
        return par;
    }

    public void toCXF(Writer out) throws IOException {
        out.write("<as:Parameter ");
        out.write("name=\"" + getName() + "\" ");
        if (getValues().size() > 0) {
            out.write("values=\"" + getValuesString() + "\" ");
        }
        if (getDefaultValue().length() > 0) {
            out.write("default=\"" + getDefaultValue() + "\" ");
        }
        if (getDatatype().length() > 0) {
            out.write("datatype=\"" + getDatatype() + "\" ");
        }
        if (getXpath().length() > 0) {
            out.write("xpath=\"" + getXpath() + "\" ");
        }
        if (getUse().length() > 0) {
            out.write("use=\"" + getUse() + "\" ");
        }
        out.write("/>\n");
    }

    private String getValuesString() {
        StringBuilder values = new StringBuilder();
        if (getValues().size() > 0) {
            for (String value : getValues()) {
                if (values.length() > 0) {
                    values.append("|");
                }
                values.append("'").append(value).append("'");
            }
        }
        return values.toString();
    }

    @Override
    public String toString() {

        return getName() + "(" + getValuesString() + "," + getDefaultValue() + ") " + getXpath() + " usage=" + getUse();
    }

    public boolean isValid() {
        if (getName() == null || getName().length() == 0) {
            return false;
        } else if (getUse().equals(Usage.local.toString()) && (xpath == null || xpath.length() == 0)) {
            return false;
        } else if (getUse().equals(Usage.global.toString()) && xpath != null && xpath.length() > 0) {
            return false;
        } else if (getDefaultValue() != null && getDefaultValue().length() > 0) {
            if (getValues() != null && getValues().size() > 0 && !getValues().contains(getDefaultValue())) {
                return false;
            }
        }
        return true;
    }
}
