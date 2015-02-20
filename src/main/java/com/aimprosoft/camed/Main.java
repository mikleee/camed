package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.CamCompiler;

import java.io.File;


public class Main {

    public static void main(String[] args) throws Exception {
        File input = new File("/home/stas/Work/Projects/camed/resorces/input/UDB-cam.cam");
        new CamCompiler("/home/stas/Work/Projects/camed/resorces/output", "/home/stas/Work/Projects/camed/resorces/output/result.cxx").compile(input);

    }

}
