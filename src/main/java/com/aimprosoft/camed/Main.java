package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.service.compiler.CamCompiler;

import java.io.File;


public class Main {

    private static String root = "C:\\Users\\Мишаня\\IdeaProjects\\camed\\";
    private static File input = new File(root + "resorces\\input\\UDB-cam.cam");
    //    private static File input = new File(root + "resorces\\input\\FM4-UDB-OTC-01.cam");
    //        private static File input = new File(root + "resorces\\input\\MoveToFront.cam");
//    private static File input = new File(root + "resorces\\input\\GetDialogData.cam");
    private static File output = new File(root + "resorces\\output\\result.cxx");

    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();

        {
            CamCompiler camCompiler = new CamCompiler(input);
            camCompiler.compileAndSave(output);
//            camCompiler.compileAndSave();
//            TestCase.test(input, output);
        }
        TimeTracker.total = System.currentTimeMillis() - start;
        TimeTracker.report();
    }


}
