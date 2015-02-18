package com.aimprosoft.camed.compiler.service;

import com.aimprosoft.camed.compiler.CAMCompilerException;
import com.aimprosoft.camed.compiler.model.Compilable;

/**
 * author m.tkachenko
 */
public interface ElementBuilder {
    Compilable build() throws CAMCompilerException;
}
