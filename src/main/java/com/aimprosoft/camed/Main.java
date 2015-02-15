package com.aimprosoft.camed;

import com.aimprosoft.camed.compiler.CamCompiler;

import java.io.File;


public class Main {

    public static void main(String[] args) throws Exception {
        File input = new File("C:\\Users\\Мишаня\\Desktop\\cam\\UDB-cam.txt");
        new CamCompiler("C:\\Users\\Мишаня\\Desktop\\cam", "C:\\Users\\Мишаня\\Desktop\\cam\\result.cxx").compile(input);
    }

}
