package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.model.impl.CamsTemplate;
import com.aimprosoft.camed.compiler.model.impl.Constraint;
import com.aimprosoft.camed.compiler.service.DocumentFactory;
import com.aimprosoft.camed.compiler.service.ModelFactory;
import org.jdom.Document;

import java.io.*;
import java.util.List;

/**
 * @author mtkachenko.
 */
public class TestCase {


    public static void test(File input, File compiled) throws Exception {
        Document doc = DocumentFactory.createDocument(input);
        CamsTemplate result = ModelFactory.createCAMTemplate(doc);

        String compiledTemplate = compilesTemplate(compiled);

        int i = 0;
        for (List<Constraint> group : result.getConstraintManager().getGroupedConstraints().values()) {
            for (Constraint constraint : group) {
                String condition = constraint.getCondition();
                if (condition == null) {
                    continue;
                }
                condition = condition.replaceAll(">", "&gt;").replaceAll("<", "&lt;");
                if (!compiledTemplate.contains(condition)) {
                    System.out.println("Condition : " + condition + " was not added");
                    i++;
                }
            }
        }

        System.out.println("total count " + i);
    }

    private static String compilesTemplate(File compiled) throws IOException {
        Reader reader = new BufferedReader(new FileReader(compiled));

        StringBuilder compiledString = new StringBuilder();

        int c = 0;
        while ((c = reader.read()) != -1) {
            compiledString.append((char) c);
        }

        return compiledString.toString();
    }

}
