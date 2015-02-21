package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.CAMTemplate;
import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Constraint;
import com.aimprosoft.camed.compiler.model.Rule;
import com.aimprosoft.camed.compiler.util.DocumentFactory;
import com.aimprosoft.camed.compiler.xpath.JDOMXPathAdapter;
import org.jaxen.JaxenException;
import org.jdom.Document;
import org.jdom.Element;


import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConstraintManager implements Compilable {

    private static final String CONTEXT_PATH = "//as:context";
    private List<Constraint> constraints;
    private Map<String, List<Constraint>> xPathBoundedConstraints;


    public ConstraintManager(CAMTemplate template) throws CAMCompilerException {
        initConstraints(template);
        bindConstraintsToXpath();
    }

    @Override
    public String compile() throws CAMCompilerException {
        return null;
    }

    private void initConstraints(CAMTemplate template) throws CAMCompilerException {
        constraints = new ArrayList<Constraint>();

        try {
            Element contextNode = new JDOMXPathAdapter(CONTEXT_PATH, template).selectNode();
            for (Element constraintNode : (List<Element>) contextNode.getChildren()) {
                constraints.add(ModelFactory.createConstraint(constraintNode)); //todo
            }
        } catch (JaxenException e) {
            throw new CAMCompilerException("Element " + CONTEXT_PATH + " is absent.");
        }
    }

    private void bindConstraintsToXpath() {
        List<Constraint> constraints = new ArrayList<Constraint>(this.constraints);

        xPathBoundedConstraints = new HashMap<String, List<Constraint>>();

        for (int i = 0; i < constraints.size(); i++) {
            String xPath = constraints.get(i).getItem();
            List<Constraint> xPathRelatedConstraints = new ArrayList<Constraint>();
            xPathRelatedConstraints.add(constraints.get(i));

            for (int j = i + 1; j < constraints.size(); ) {
                String thatXPath = constraints.get(j).getItem();

                if (xPath.equals(thatXPath)) {
                    xPathRelatedConstraints.add(constraints.get(j));
                    constraints.remove(j);
                } else {
                    j++;
                }

            }

            xPathBoundedConstraints.put(xPath, xPathRelatedConstraints);
        }
    }


    public static void main(String[] args) throws Exception {
        File input = new File("D:\\work\\camed\\resorces\\input\\UDB-cam.cam");
        Document doc = new DocumentFactory().createDocument(input);
        CAMTemplate result = ModelFactory.createCAMTemplate(doc);
        ConstraintManager constraintManager = new ConstraintManager(result);
    }


}
