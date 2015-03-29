package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.constants.ReportTarget;

import java.util.ArrayList;
import java.util.List;

/**
 * @author mtkachenko.
 */
public class Report {

    private ReportType reportType;
    private ReportTarget reportTarget;
    private List<String> conflicts = new ArrayList<String>();

    public Report(ReportTarget reportTarget, ReportType reportType, List<String> conflicts) {
        this(reportTarget, reportType);
        this.conflicts = conflicts;
    }

    public Report(ReportTarget reportTarget, ReportType reportType) {
        this.reportType = reportType;
        this.reportTarget = reportTarget;
    }

    public ReportTarget getReportTarget() {
        return reportTarget;
    }

    public List<String> getConfilcts() {
        return conflicts;
    }

    public ReportType getReportType() {
        return reportType;
    }

    public void addConflict(String conflictXpath) {
        conflicts.add(conflictXpath);
    }

}
