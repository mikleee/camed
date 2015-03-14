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

    public Report(ReportType reportType, List<String> missed, List<String> extra) {
        this.reportType = reportType;
        this.missed = missed;
        this.extra = extra;
        buildReport();
    }

    private void buildReport() {
        if (!missed.isEmpty() || !extra.isEmpty()) {
            report.put(MismatchType.MISSED, missed);
            report.put(MismatchType.EXTRA, missed);
        }
    }

    public ReportType getReportType() {
        return reportType;
    }

    public Map<MismatchType, List<String>> getReport() {
        return report;
    }

    private enum MismatchType {
        MISSED("missed-mismatch-type"), EXTRA("extra-mismatch-type");
        private String key;

        MismatchType(String key) {
            this.key = key;
        }

        public String getKey() {
            return key;
        }
    }
}
