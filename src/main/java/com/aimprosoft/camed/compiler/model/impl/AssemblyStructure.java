package com.aimprosoft.camed.compiler.model.impl;

import com.aimprosoft.camed.compiler.model.Compilable;
import com.aimprosoft.camed.compiler.model.Structure;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import static com.aimprosoft.camed.compiler.util.CommonUtils.isNotEmpty;

/**
 * author m.tkachenko
 */
public class AssemblyStructure implements Compilable {

    private List<Structure> structures;

    public AssemblyStructure(List<Structure> structures) {
        this.structures = structures;
    }


    @Override
    public String compile() {

        StringBuilder builder = new StringBuilder("<as:AssemblyStructure>\n");

        for (Structure structure : structures) {
            //todo
//            struct.toCXF(out, full);
        }

        builder.append("</as:AssemblyStructure>\n");
        return builder.toString();
    }

}
