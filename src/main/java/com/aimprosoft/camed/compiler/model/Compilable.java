package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.CAMCompilerException;

/**
 * author m.tkachenko
 */
public interface Compilable {

    String QUOTE = "\"";

    String compile() throws CAMCompilerException;
}
