//package com.aimprosoft.camed.compiler.model.impl;
//
//import com.aimprosoft.camed.compiler.constants.CAMConstants;
//import com.aimprosoft.camed.compiler.extensions.AllowedExtensions;
//import com.aimprosoft.camed.compiler.extensions.StructureAnnotation;
//import com.aimprosoft.camed.compiler.extensions.StructureAnnotations;
//import com.aimprosoft.camed.compiler.model.CAMTemplate;
//import com.aimprosoft.camed.compiler.model.Compilable;
//import com.aimprosoft.camed.compiler.model.Constraint;
//import com.aimprosoft.camed.compiler.model.Rule;
//import com.aimprosoft.camed.compiler.util.IncludeHandlers;
//import com.aimprosoft.camed.compiler.util.XPathFunctions;
//import org.apache.commons.lang.StringEscapeUtils;
//import org.jdom.Attribute;
//
//import java.io.Writer;
//import java.util.List;
//
//
//public class AttributeWrapper implements Compilable {
//
//    private Attribute attribute;
//    private CAMTemplate template;
//
//    @Override
//    public String compile() {
//        StringBuilder builder = new StringBuilder("<as:Attribute\n" + ">");
//        return null;
//    }
//
//
//    private void toCXF() throws Exception {
//        StringBuilder builder = new StringBuilder();
//
//
//        boolean full = false;
//
//        builder.append("<as:Attribute ");
//        builder.append(" name=\"" + StringEscapeUtils.escapeXml(attribute.getQualifiedName()) + "\" ");
//
//
//        List<Rule> nodeRules = template.getRuleManager().getNodeRules(attribute);
//
//        if (nodeRules != null && nodeRules.size() > 0) {
//            if (full)
//                builder.append("<" + CAMConstants.CAMNamespace.getPrefix() + ":" + "Rule" + ">\n");
//            int count = 1;
//            boolean duplicates = checkDuplicates();
//            for (Rule rule : nodeRules) {
//                if (rule instanceof Constraint) {
//                    Constraint cons = (Constraint) rule;
//                    if (duplicates) {
//                        cons.toCXF(out, full, count++);
//                    } else {
//                        cons.toCXF(out, full, -1);
//                    }
//                }
//            }
//            if (full)
//                builder.append("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                        + "Rule" + ">\n");
//        } else {
//            if (full) {
//                builder.append("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                        + "Rule" + ">\n");
//                builder.append("<" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                        + "constraint" + " ");
//                builder.append(" " + "action" + "=\""
//                        + StringEscapeUtils.escapeXml("makeMandatory()")
//                        + "\" ");
//                builder.append("/>");
//                builder.append("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                        + "Rule" + ">\n");
//            } else {
//                builder.append(" " + "makeMandatory" + "=\"true\" ");
//            }
//        }
//        if (full) {
//            StructureAnnotations sa = (StructureAnnotations) AllowedExtensions
//                    .getExtension(StructureAnnotations.name);
//            if (sa != null) {
//                String xpath = XPathFunctions.xpathParentAndAll(attribute);
//                StructureAnnotation anno = sa.get(xpath);
//                if (anno != null) {
//                    anno.toCXF(out);
//                }
//            }
//        }
//        if (!full)
//            builder.append("/>\n");
//        if (full)
//            builder.append("</" + CAMConstants.CAMNamespace.getPrefix() + ":"
//                    + "Attribute" + ">\n");
//    }
//
//}
