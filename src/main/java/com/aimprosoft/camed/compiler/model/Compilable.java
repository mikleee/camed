package com.aimprosoft.camed.compiler.model;

import com.aimprosoft.camed.compiler.CamException;

/**
 * author m.tkachenko
 */
public interface Compilable {

    String compile() throws CamException;

}
