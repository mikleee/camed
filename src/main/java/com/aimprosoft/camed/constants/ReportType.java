package com.aimprosoft.camed.constants;

/**
 * @author mtkachenko.
 */
public enum ReportType {
    MISSES("missed-mismatch-type"), EXTRAS("extra-mismatch-type"), MISMATCHES("mismatch-mismatch-type");
    private String key;

    ReportType(String key) {
        this.key = key;
    }

    public String getKey() {
        return key;
    }
}
