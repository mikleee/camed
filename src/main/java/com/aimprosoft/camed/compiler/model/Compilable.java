package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.CAMCompilerException;

/**
 * author m.tkachenko
 */
public interface Compilable {

    String QUOTE = "\"";
     String ELEMENT = "as:Element";
     String ATTRIBUTE = "as:Attribute";


    String compile() throws CAMCompilerException;
}
