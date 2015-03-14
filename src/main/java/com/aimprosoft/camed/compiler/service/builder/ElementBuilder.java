package com.aimprosoft.camed.compiler.service.builder;

import com.aimprosoft.camed.compiler.CamException;

/**
 * author m.tkachenko
 */
public interface ElementBuilder<T> {
    T build() throws CamException;
}
