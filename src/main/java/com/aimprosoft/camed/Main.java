package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.CamCompiler;

import java.io.File;


public class Main {

    private static String root = "C:\\Users\\Мишаня\\IdeaProjects\\camed\\";

    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();

        File input = new File(root + "resorces\\input\\UDB-cam.cam");
        new CamCompiler(root + "resorces\\output", root + "resorces\\input\\result.cxx").compile(input);

        System.out.println("total time: " + (System.currentTimeMillis() - start));
    }

}
