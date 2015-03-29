package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.constants.ReportTarget;
import com.aimprosoft.camed.constants.ReportType;

import java.util.*;

/**
 * @author mtkachenko.
 */
public class Report {

    private ReportTarget reportTarget;
    private Map<ReportType, List<String>> conflicts = new LinkedHashMap<ReportType, List<String>>();

    public Report(ReportTarget reportTarget) {
        this.reportTarget = reportTarget;
        for (ReportType reportType : ReportType.values()) {
            conflicts.put(reportType, new ArrayList<String>());
        }
    }

    public void addExtra(String conflict) {
        conflicts.get(ReportType.EXTRAS).add(conflict);
    }

    public void addExtras(Collection<String> extras) {
        conflicts.get(ReportType.EXTRAS).addAll(extras);
    }

    public void addMiss(String conflict) {
        conflicts.get(ReportType.MISSES).add(conflict);
    }

    public void addMisses(Collection<String> misses) {
        conflicts.get(ReportType.MISSES).addAll(misses);
    }

    public void addMismatch(String conflict) {
        conflicts.get(ReportType.MISMATCHES).add(conflict);
    }


    public ReportTarget getReportTarget() {
        return reportTarget;
    }

    public Map<ReportType, List<String>> getConflicts() {
        return conflicts;
    }

    @Override
    public String toString() {
        final String line = "::::::::::::";
        StringBuilder builder = new StringBuilder("\n").append(line).append(" ")
                .append("Report. Target: ")
                .append(reportTarget)
                .append(" ")
                .append(line).append("\n\n");

        for (ReportType type : conflicts.keySet()) {
            List<String> conflictSection = conflicts.get(type);
            builder.append(type).append(" count: ").append(conflictSection.size()).append("\n\n");

            for (String conflict : conflictSection) {
                builder.append(conflict).append("\n");
            }

            builder.append("\n");
        }

        return builder.append(line).append(" Report completed ").append(line).append("\n").toString();
    }
}
