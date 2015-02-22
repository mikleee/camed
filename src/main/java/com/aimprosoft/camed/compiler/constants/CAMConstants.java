package com.aimprosoft.camed.compiler.constants;

import org.jdom.Namespace;

public class CAMConstants {

    public static final String CAM_NAMESPACE_PREFIX = "as";
    public static final String CAM_NAMESPACE_URI = "http://www.oasis-open.org/committees/cam";

    public static final Namespace CAMNamespace = Namespace.getNamespace(CAMConstants.CAM_NAMESPACE_PREFIX, CAMConstants.CAM_NAMESPACE_URI);

    public static final Namespace CAM_NAMESPACE = Namespace.getNamespace(CAM_NAMESPACE_PREFIX, CAM_NAMESPACE_URI);

    public static final String ATTR_CAMERROR = "CAMERROR";
    public static final String CAM_EDITOR_PROJECT = "CAMEditor";

    public static final String DateMaskText = "Date Masks can either be CAM or Java format\n" +
            "For Java Mask must start with 'J'\n" +
            "CAM Mask Options are:\n" +
            "DD - Day of Month\n" +
            "DDD - Day in Year\n" +
            "DDDD - relative day in Month, i.e. ' 2nd'\n" +
            "MM - Month in number\n" +
            "MMM... - Month is letter (number of 'M' = length required)\n" +
            "YY - last 2 digits of year\n" +
            "YYYY - Full year number - i.e. 2006\n" +
            "W - Day in week\n" +
            "WWW... - Name of day (number of 'W' = length required)\n" +
            "T - if T occurs as the first character of mask then all letter masks are trimmed of extra spaces.";
    public static final String StringMaskText = "String Masks use the following characters:\n" +
            "X - a mandatory character\n" +
            "? - an optional character\n" +
            "* - a series of optional characters\n" +
            "U - a mandatory Uppercase letter\n" +
            "^ - an optional Uppercase letter\n" +
            "L - a mandatory Lowecase letter\n" +
            "_ - (underscore) an optional Lowercase letter\n" +
            "0 - a digit - leading zeros must exist\n" +
            "# - a digit leading zeros may be absent\n" +
            "'' = quoted characters must exist in the string.";
    public static final String NumberMaskText = "Number Masks can either be CAM or Java format\n" +
            "For Java Mask must start with 'J'\n" +
            "CAM Mask Options are:\n" +
            "0 - a digit (0-9)\n" +
            "# - a digit (0-9) trailing or leading zeros may be absent\n" +
            ". - the position of the decimal point";
}
