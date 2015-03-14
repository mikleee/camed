package com.aimprosoft.camed.constants;

/**
 * @author mtkachenko.
 */
public enum TaxonomyType {
    XML, XSD, DTD, RNG, EDI, HTML, MERGE, OTHER;

    public static boolean isOther(String taxonomy) {
        return OTHER.toString().equals(taxonomy);
    }
}
