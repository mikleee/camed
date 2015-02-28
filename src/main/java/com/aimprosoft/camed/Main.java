package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.service.CAMCompiler;

import java.io.File;


public class Main {

    private static String root = "C:\\Users\\Мишаня\\IdeaProjects\\camed\\";
    //    private static File input = new File(root + "resorces\\input\\UDB-cam.cam");
    private static File input = new File(root + "resorces\\input\\MoveToFront.cam");
    private static File output = new File(root + "resorces\\output\\result.cxx");

    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();

        {
            CAMCompiler camCompiler = new CAMCompiler(input);
            camCompiler.compileAndSave();
            TestCase.test(input, output);
        }

        System.out.println("total time: " + (System.currentTimeMillis() - start));
    }


}
