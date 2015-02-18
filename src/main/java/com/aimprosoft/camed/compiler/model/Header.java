package com.aimprosoft.camed.compiler.model;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import static com.aimprosoft.camed.compiler.util.CommonUtils.isNotEmpty;

/**
 * author m.tkachenko
 */
public class Header implements Compilable {

    public Header(String description, String owner, String templateVersion) {
        this.description = description;
        this.owner = owner;
        this.templateVersion = templateVersion;
        this.dateTime = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss").format(new Date());
    }

    private String description;
    private String owner;
    private String templateVersion;
    private String dateTime;

    @Override
    public String compile() {

        StringBuilder builder = new StringBuilder("<as:Header>\n");

        if (isNotEmpty(description)) {
            builder.append("<as:Description>").append(description).append("</as:Description>\n");
        }
        if (isNotEmpty(owner)) {
            builder.append("<as:Owner>").append(owner).append("</as:Owner>\n");
        }
        if (isNotEmpty(templateVersion)) {
            builder.append("<as:Version>").append(templateVersion).append("</as:Version>\n");
        }
        if (isNotEmpty(dateTime)) {
            builder.append("<as:DateTime>").append(dateTime).append("</as:DateTime>\n");
        }

        builder.append("</as:Header>\n");
        return builder.toString();

    }
}
