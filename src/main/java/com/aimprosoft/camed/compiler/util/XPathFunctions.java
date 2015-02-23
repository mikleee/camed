package com.aimprosoft.camed.compiler.util;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.aimprosoft.camed.compiler.constants.CAMConstants;
import org.jdom.Attribute;
import org.jdom.Element;

public class XPathFunctions {

    public static Set<String> getXpathVariation(Object node) {
        Set<String> list = new HashSet<String>();
        if (node != null) {
            list.add(fullXpathWithPosition(node));
            list.add(xpath(node));
            if (node instanceof Element) {
                list.add(fullXpathWithPosition(node) + "/*");
                list.add(xpath(node) + "/*");

                list.add("/" + ((Element) node).getQualifiedName());
                list.add("/" + ((Element) node).getQualifiedName() + "/*");
                list.add("//" + ((Element) node).getQualifiedName());
                list.add("//" + ((Element) node).getQualifiedName() + "/*");

                list.add("/" + xpathWithPosition(node));
                list.add("/" + xpathWithPosition(node) + "/*");
                list.add("//" + xpathWithPosition(node));
                list.add("//" + xpathWithPosition(node) + "/*");

                if (node != null
                        && ((Element) node).getParentElement() != null
                        && !((Element) node).getParentElement().getName()
                        .equals("Structure")) {
                    list.add("/"
                            + ((Element) node).getParentElement()
                            .getQualifiedName() + "/"
                            + ((Element) node).getQualifiedName());
                    list.add("/"
                            + ((Element) node).getParentElement()
                            .getQualifiedName() + "/"
                            + ((Element) node).getQualifiedName() + "/*");
                    list.add("//"
                            + ((Element) node).getParentElement()
                            .getQualifiedName() + "/"
                            + ((Element) node).getQualifiedName());
                    list.add("//"
                            + ((Element) node).getParentElement()
                            .getQualifiedName() + "/"
                            + ((Element) node).getQualifiedName() + "/*");

                    list.add("/"
                            + xpathWithPosition(((Element) node)
                            .getParentElement()) + "/"
                            + xpathWithPosition((Element) node));
                    list.add("/"
                            + xpathWithPosition(((Element) node)
                            .getParentElement()) + "/"
                            + xpathWithPosition((Element) node)
                            + "/*");
                    list.add("//"
                            + xpathWithPosition(((Element) node)
                            .getParentElement()) + "/"
                            + xpathWithPosition((Element) node));
                    list.add("//"
                            + xpathWithPosition(((Element) node)
                            .getParentElement()) + "/"
                            + xpathWithPosition((Element) node)
                            + "/*");
                }

            } else {
                list.add("/@" + ((Attribute) node).getQualifiedName());
                list.add("//@" + ((Attribute) node).getQualifiedName());

                list.add("/"
                        + ((Attribute) node).getParent().getQualifiedName()
                        + "/@" + ((Attribute) node).getQualifiedName());
                list.add("//"
                        + ((Attribute) node).getParent().getQualifiedName()
                        + "/@" + ((Attribute) node).getQualifiedName());
                list.add("//"
                        + ((Attribute) node).getParent().getParentElement().getQualifiedName()
                        + "/"
                        + ((Attribute) node).getParent().getQualifiedName()
                        + "/@" + ((Attribute) node).getQualifiedName());

                list.add("/"
                        + xpathWithPosition(((Attribute) node)
                        .getParent()) + "/@"
                        + ((Attribute) node).getQualifiedName());
                list.add("//"
                        + xpathWithPosition(((Attribute) node)
                        .getParent()) + "/@"
                        + ((Attribute) node).getQualifiedName());
            }
        }
        return list;
    }

    public static String xpath(Object obj) {
        String path = null;
        if (obj instanceof Element) {
            path = xpath((Element) obj);
        } else if (obj instanceof Attribute) {
            path = xpath((Attribute) obj);
        }
        return path;
    }

    private static String xpath(Element element) {
        String path = "/" + element.getQualifiedName();
        String parent = "";
        if (element.getParentElement() != null) {
            if (parentIsNotOnTop(element)) {
                parent = xpath(element.getParentElement());
            }
        }
        return parent + path;
    }

    private static String xpath(Attribute attribute) {
        String path = "/" + attribute.getParent().getQualifiedName() + "/@" + attribute.getQualifiedName();
        Element element = attribute.getParent();
        String parent = "";
        if (element.getParentElement() != null) {
            if (parentIsNotOnTop(element)) {
                parent = xpath(element.getParentElement());
            }
        }
        return parent + path;
    }

    public static String fullXpathWithPosition(Object obj) {
        String path = null;
        if (obj instanceof Element) {
            path = fullXpathWithPosition((Element) obj);
        } else if (obj instanceof Attribute) {
            path = fullXpathWithPosition((Attribute) obj);
        }
        return path;
    }

    private static String fullXpathWithPosition(Element element) {

        String path = "/" + element.getQualifiedName() + "[" + getPosition(element) + "]";
        String parent = "";
        if (element.getParentElement() != null) {
            if (parentIsNotOnTop(element)) {
                parent = fullXpathWithPosition(element.getParentElement());
            }
        }
        return parent + path;
    }

    private static String fullXpathWithPosition(Attribute attribute) {
        String path = "/" + attribute.getParent().getQualifiedName() + "[" + getPosition(attribute.getParent()) + "]" + "/@" + attribute.getQualifiedName();
        Element element = attribute.getParent();
        String parent = "";
        if (element.getParentElement() != null && !element.isRootElement()) {
            if (parentIsNotStructureAndTemp(element)) {
                parent = fullXpathWithPosition(element.getParentElement());
            }
        }
        return parent + path;
    }

    public static String xpathParentAndAll(Object obj) {
        String path = null;
        if (obj instanceof Element) {
            path = xpathParentAndAll((Element) obj);
        } else if (obj instanceof Attribute) {
            path = xpathParentAndAll((Attribute) obj);
        }
        return path;
    }

    private static String xpathParentAndAll(Element elem) {
        String path = elem.getQualifiedName();
        if (elem.getParentElement() == null) {
            return "//" + path;
        }
        if (!(elem.getParentElement().getName().equals("Structure") && elem.getParentElement().getNamespace().equals(CAMConstants.CAM_NAMESPACE))) {
            if (!path.startsWith("/")) {
                path = elem.getParentElement().getQualifiedName() + "/" + path;
            } else {
                path = elem.getParentElement().getQualifiedName() + path;
            }
        }
        return "//" + path;
    }

    private static String xpathParentAndAll(Attribute attr) {
        String path = "@" + attr.getQualifiedName();
        if (!(attr.getParent().getName().equals("Structure") && attr.getParent().getNamespace().equals(CAMConstants.CAM_NAMESPACE))) {
            if (!path.startsWith("/"))
                path = attr.getParent().getQualifiedName() + "/" + path;
            else
                path = attr.getParent().getQualifiedName() + path;
        }
        return "//" + path;
    }

    public static String xpathWithPosition(Object obj) {
        String path = null;
        if (obj instanceof Element) {
            path = xpathWithPosition((Element) obj);
        } else if (obj instanceof Attribute) {
            path = xpathWithPosition((Attribute) obj);
        }
        return path;
    }

    private static String xpathWithPosition(Attribute attribute) {
        return attribute.getParent().getQualifiedName() + "[" + getPosition(attribute.getParent()) + "]" + "/@" + attribute.getQualifiedName();
    }

    private static String xpathWithPosition(Element element) {
        return "/" + element.getQualifiedName() + "[" + getPosition(element) + "]";
    }

    public static List<String> xpathRelativeAll(Object obj) {
        List<String> paths = new ArrayList<String>();
        if (obj instanceof Element) {
            paths = xpathRelativeAll((Element) obj);
        } else if (obj instanceof Attribute) {
            paths = xpathRelativeAll((Attribute) obj);
        }
        return paths;
    }

    private static List<String> xpathRelativeAll(Element element) {
        List<String> paths = new ArrayList<String>();
        List<Element> nodes = new ArrayList<Element>();
        Element elem = element;
        String path = "";
        while (!(elem.getName().equals("Structure") && elem.getNamespace()
                .equals(CAMConstants.CAM_NAMESPACE))) {
            if (elem.equals(element)) {
                paths.add(".");
                if (!(elem.getParentElement().getName().equals("Structure") && elem.getParentElement().getNamespace().equals(CAMConstants.CAM_NAMESPACE))) {
                    paths.add("/.");
                    paths.add("..");
                }
                path = "./";
                drillDown(element, elem, path, paths, nodes);
                elem = elem.getParentElement();
                nodes.add(elem);
                path = "../";
            } else {
                drillDown(element, elem, path, paths, nodes);
                elem = elem.getParentElement();
                path = path + "../";
            }
        }

        return paths;
    }

    private static List<String> xpathRelativeAll(Attribute attribute) {
        List<String> paths = new ArrayList<String>();
        List<Element> nodes = new ArrayList<Element>();
        Element elem = attribute.getParent();
        paths.add(".");
        if (!(elem.getParentElement().getName().equals("Structure") && elem.getParentElement().getNamespace().equals(CAMConstants.CAM_NAMESPACE))) {
            paths.add("/.");
            paths.add("..");
        }
        StringBuilder path = new StringBuilder("../");
        while (!(elem.getName().equals("Structure") && elem.getNamespace()
                .equals(CAMConstants.CAMNamespace))) {
            drillDown(attribute, elem, path.toString(), paths, nodes);
            elem = elem.getParentElement();
            path.append("../");
        }

        return paths;
    }

    @SuppressWarnings("unchecked")
    private static int getPosition(Element element) {
        if (element.getParentElement() != null) {
            Element parent = element.getParentElement();
            List<Element> list = parent.getChildren();
            int count = 0;
            for (Element elem : list) {
                if (elem.getName().equals(element.getName()) && elem.getNamespace().equals(element.getNamespace()))
                    count++;
                if (elem.equals(element)) {
                    return count;
                }
            }
        }
        return 1;
    }

    @SuppressWarnings("unchecked")
    private static void drillDown(Object original, Element element, String path, List<String> paths, List<Element> nodes) {
        for (Object attr : (List<Object>) element.getAttributes()) {
            if (!attr.equals(original)) {
                if (!nodes.contains(attr)) {
                    paths.add(path + "@" + ((Attribute) attr).getName());
                }
            }
        }
        for (Element child : (List<Element>) element.getChildren()) {
            if (!child.equals(original)) {
                if (!nodes.contains(child)) {
                    paths.add(path + child.getName());
                    nodes.add(child);
                    drillDown(original, child, path + child.getName() + "/",
                            paths, nodes);
                }
            }

        }

    }

    public static String getParentXpath(String attributeXpath) {
        int index = attributeXpath.indexOf("/@");
        String result = attributeXpath.substring(0, index);

        if (result.equals("/")) {
            result = "//UDBFile";
        }

        return result;
    }

    public static boolean isAttributePresent(Attribute attribute, Element parent) {

        String attrName = attribute.getQualifiedName();

        if (parent.getAttribute(attrName) != null) {
            return true;
        } else {
            List<Element> children = parent.getChildren();
            for (Element child : children) {
                if (isAttributePresent(attribute, child)) {
                    return true;
                }
            }
            return false;
        }

    }

    private static boolean parentIsNotOnTop(Element element) {
        Element parent = element.getParentElement();
        return !parent.isRootElement() && parentIsNotStructureAndTemp(element);
    }

    private static boolean parentIsNotStructureAndTemp(Element element) {
        String parentName = element.getParentElement().getQualifiedName();
        return !parentName.equals("as:Structure") && !parentName.equals("as:Temp");
    }

    private static boolean isNotTemp(Element element) {
        return !element.getParentElement().getQualifiedName().equals("as:Temp");
    }
}
