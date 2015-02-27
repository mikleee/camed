package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.service.CamCompiler;

import java.io.File;


public class Main {

    private static String root = "C:\\Users\\Мишаня\\IdeaProjects\\camed\\";
    private static File input = new File(root + "resorces\\input\\UDB-cam.cam");
    private static File output = new File(root + "resorces\\output\\result.cxx");

    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();

        {
            new CamCompiler(input).compileToFile(output);
            TestCase.test(root, input);
        }

        System.out.println("total time: " + (System.currentTimeMillis() - start));
    }


}
