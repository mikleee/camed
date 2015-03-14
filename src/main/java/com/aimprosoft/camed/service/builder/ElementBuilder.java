package com.aimprosoft.camed.service.builder;

import com.aimprosoft.camed.CamException;

/**
 * author m.tkachenko
 */
public interface ElementBuilder<T> {
    T build() throws CamException;
}
