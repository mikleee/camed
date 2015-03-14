package com.aimprosoft.camed.compiler.service.builder;

import com.aimprosoft.camed.compiler.CAMCompilerException;

/**
 * author m.tkachenko
 */
public interface ElementBuilder<T> {
    T build() throws CAMCompilerException;
}
