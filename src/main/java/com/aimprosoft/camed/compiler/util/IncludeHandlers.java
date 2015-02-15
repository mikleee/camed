package com.aimprosoft.camed.compiler.util;

import com.aimprosoft.camed.compiler.model.CAMTemplate;
import org.jdom.Element;

import com.aimprosoft.camed.compiler.model.Include;

public class IncludeHandlers {

    private CAMTemplate template;

    public static boolean isIncluded(Object object, CAMTemplate template) {
        boolean result = false;
        if (template != null && template.getIncludes() != null) {
            for (Include incl : template.getIncludes().values()) {
                if (incl.isRoot(object) && !incl.isIgnoreRoot()) {
                    result = true;
                    break;
                } else if (incl.containsElement(object)) {
                    result = true;
                    break;
                }
            }
        }
        return result;
    }

    public static Include getInclude(Object object, CAMTemplate template) {
        Include result = null;
        if (template != null && template.getIncludes() != null) {
            for (Include incl : template.getIncludes().values()) {
                if (incl.isRoot(object) && !incl.isIgnoreRoot()) {
                    result = incl;
                    break;
                } else if (incl.containsElement(object)) {
                    result = incl;
                    break;
                }
            }
        }
        return result;
    }


    public static boolean includedRootElement(Element element, CAMTemplate template) {
        if (template == null) return false;
        if (template.getIncludes() == null) return false;
        for (Include incl : template.getIncludes().values()) {
            if (incl.isRoot(element) && !incl.isIgnoreRoot())
                return true;
            else if (incl.isIgnoreRoot()) {
                if (incl.getParentElement() != null && incl.getParentElement().getChildren() != null &&
                        element.equals((incl.getParentElement().getChildren().get(0)))) {
                    return true;
                }
            }
        }
        return false;
    }

//    public static String getURIForIncludedRootElement(Element element) {
//        if (CAMEditor.getTemplate() == null) return null;
//        if (CAMEditor.getTemplate().getIncludes() == null) return null;
//        for (Include incl : CAMEditor.getTemplate().getIncludes().values()) {
//            if (incl.isRoot(element) && !incl.isIgnoreRoot())
//                return incl.getUri();
//        }
//        return null;
//    }
//
//    public static String getURIForIncludedElement(Element element) {
//        if (CAMEditor.getTemplate() == null) return null;
//        if (CAMEditor.getTemplate().getIncludes() == null) return null;
//        for (Include incl : CAMEditor.getTemplate().getIncludes().values()) {
//            if (incl.isRoot(element) && !incl.isIgnoreRoot())
//                return incl.getUri();
//            if (incl.containsElement(element))
//                return incl.getUri();
//        }
//        return null;
//    }

    public static boolean includeNotIgnoringRoot(Element element, CAMTemplate template) {
        if (template == null) return false;
        if (template.getIncludes() == null) return false;
        for (Include incl : template.getIncludes().values()) {
            if (incl.isRoot(element))
                return !incl.isIgnoreRoot();
            if (incl.containsElement(element))
                return !incl.isIgnoreRoot();
        }
        return false;
    }

    public CAMTemplate getTemplate() {
        return template;
    }

    public void setTemplate(CAMTemplate template) {
        this.template = template;
    }
}
