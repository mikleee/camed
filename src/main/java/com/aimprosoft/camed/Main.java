package com.aimprosoft.camed;

import java.io.File;


public class Main {

    private static String root = "C:\\Users\\Мишаня\\IdeaProjects\\camed\\";
    private static File input = new File(root + "resorces\\input\\UDB-cam.cam");

    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();


//      new CamCompiler(root + "resorces\\output", root + "resorces\\input\\result.cxx").compile(input);
        TestCase.test(root, input);
        System.out.println("total time: " + (System.currentTimeMillis() - start));
    }


}
