package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.model.Compilable;



public class Element implements Compilable {

//    private String name;
//    private String path;
//    private String namespace;



    @Override
    public String compile() {
        StringBuilder builder = new StringBuilder("<as:Element\n"  + ">");
        return null;
    }
}
