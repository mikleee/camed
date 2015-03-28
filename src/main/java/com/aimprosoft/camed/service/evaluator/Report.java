package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.constants.ReportType;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author mtkachenko.
 */
public class Report {

    private ReportType reportType;
    private Map<MismatchType, List<String>> report = new HashMap<MismatchType, List<String>>();
    private List<String> missed;
    private List<String> extra;
    private List<String> mismatched;

    public Report(ReportType reportType, List<String> missed, List<String> extra, List<String> mismatched) {
        this.reportType = reportType;
        this.missed = missed;
        this.extra = extra;
        this.mismatched = mismatched;
        buildReport();
    }

    private void buildReport() {
        if (!missed.isEmpty()) {
            report.put(MismatchType.MISSED, missed);
        }
        if (!extra.isEmpty()) {
            report.put(MismatchType.EXTRA, missed);
        }
        if (!mismatched.isEmpty()) {
            report.put(MismatchType.MISMATCHED, mismatched);
        }
    }

    public ReportType getReportType() {
        return reportType;
    }

    public Map<MismatchType, List<String>> getReport() {
        return report;
    }

    private enum MismatchType {
        MISSED("missed-mismatch-type"), EXTRA("extra-mismatch-type"), MISMATCHED("mismatch-mismatch-type");
        private String key;

        MismatchType(String key) {
            this.key = key;
        }

        public String getKey() {
            return key;
        }
    }
}
