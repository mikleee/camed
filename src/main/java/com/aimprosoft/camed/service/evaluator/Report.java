package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.constants.ReportTarget;
import com.aimprosoft.camed.constants.ReportType;
import com.aimprosoft.camed.model.KeyValuePair;
import org.jdom.Attribute;
import org.jdom.Element;
import org.jdom.Namespace;

import java.util.*;

/**
 * @author mtkachenko.
 */
public class Report {

    private ReportTarget reportTarget;
    private Map<ReportType, Map<String, KeyValuePair>> conflicts = new LinkedHashMap<ReportType, Map<String, KeyValuePair>>();

    public Report(ReportTarget reportTarget) {
        this.reportTarget = reportTarget;
        for (ReportType reportType : ReportType.values()) {
            conflicts.put(reportType, new HashMap<String, KeyValuePair>());
        }
    }

    public void addExtra(String conflict, Element element) {
        conflicts.get(ReportType.EXTRAS).put(conflict, new KeyValuePair(element));
    }

    public void addExtra(String conflict, Namespace namespace) {
        conflicts.get(ReportType.EXTRAS).put(conflict, new KeyValuePair(namespace));
    }

    public void addExtra(String conflict, Attribute attribute) {
        conflicts.get(ReportType.EXTRAS).put(conflict, new KeyValuePair(attribute));
    }

    public void addExtras(Map<String, Element> extras) {
        Map<String, KeyValuePair> map = new HashMap<String, KeyValuePair>();
        for (String key : extras.keySet()) {
            map.put(key, new KeyValuePair(extras.get(key)));
        }
        conflicts.get(ReportType.EXTRAS).putAll(map);
    }

    public void addMiss(String conflict, Element element) {
        conflicts.get(ReportType.MISSES).put(conflict, new KeyValuePair(element));
    }

    public void addMiss(String conflict, Namespace namespace) {
        conflicts.get(ReportType.MISSES).put(conflict, new KeyValuePair(namespace));
    }

    public void addMiss(String conflict, Attribute attribute) {
        conflicts.get(ReportType.MISSES).put(conflict, new KeyValuePair(attribute));
    }

    public void addMisses(Map<String, Element> misses) {
        Map<String, KeyValuePair> map = new HashMap<String, KeyValuePair>();
        for (String key : misses.keySet()) {
            map.put(key, new KeyValuePair(misses.get(key)));
        }
        conflicts.get(ReportType.MISSES).putAll(map);
    }

    public void addMismatch(String conflict, Element element) {
        conflicts.get(ReportType.MISMATCHES).put(conflict, new KeyValuePair(element));
    }

    public void addMismatch(String conflict, Attribute attribute) {
        conflicts.get(ReportType.MISMATCHES).put(conflict, new KeyValuePair(attribute));
    }

    public void setConflicts(Map<ReportType, Map<String, KeyValuePair>> conflicts){
        this.conflicts = conflicts;
    }

    public ReportTarget getReportTarget() {
        return reportTarget;
    }

    public Map<ReportType, Map<String, KeyValuePair>> getConflicts() {
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
            Map<String, KeyValuePair> conflictSection = conflicts.get(type);
            builder.append(type).append(" count: ").append(conflictSection.size()).append("\n\n");

            Set list = conflictSection.keySet();
            for (Object conflict : list) {
                builder.append(conflict).append("\n");
            }

            builder.append("\n");
        }

        return builder.append(line).append(" Report completed ").append(line).append("\n").toString();
    }
}
