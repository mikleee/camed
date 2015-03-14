package com.aimprosoft.camed.model.impl;

import com.aimprosoft.camed.constants.CamConstants;
import com.aimprosoft.camed.model.Compilable;
import org.jdom.Element;

import java.text.SimpleDateFormat;
import java.util.Date;

import static com.aimprosoft.camed.util.CommonUtils.isNotEmpty;

/**
 * author m.tkachenko
 */
public class Header implements Compilable {

    public Header(String description, String owner, String templateVersion) {
        this.description = description;
        this.owner = owner;
        this.templateVersion = templateVersion;
    }

    public Header(Element element) {
        this(
                element.getChildText("Description", CamConstants.CAM_NAMESPACE),
                element.getChildText("Owner", CamConstants.CAM_NAMESPACE),
                element.getChildText("Version", CamConstants.CAM_NAMESPACE)
        );
    }

    private String description;
    private String owner;
    private String templateVersion;
    private String dateTime = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss").format(new Date());

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
