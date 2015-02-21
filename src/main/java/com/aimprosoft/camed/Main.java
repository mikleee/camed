package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.CamCompiler;

import java.io.File;


public class Main {

    public static void main(String[] args) throws Exception {
        File input = new File("D:\\work\\camed\\resorces\\input\\UDB-cam.cam");
        new CamCompiler("D:\\work\\camed\\resorces\\output", "D:\\work\\camed\\resorces\\input\\result.cxx").compile(input);
    }

}
