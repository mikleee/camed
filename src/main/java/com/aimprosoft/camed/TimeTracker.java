package com.aimprosoft.camed;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author mtkachenko.
 */
public class TimeTracker {

    public static long total;
    public static long constraintManagerInit;
    public static long structureCompilation;
    public static long parseInitTemplate;
    public static long parseCompiledTemplate;
    public static long templateCompilation;
    public static long templateBuilding;

    public static void report() throws IllegalAccessException {
        List<ReportUnit> result = new ArrayList<ReportUnit>();

        Field[] fields = TimeTracker.class.getFields();
        for (Field field : fields) {
            if (!field.getName().equals("total")) {
                long value = (Long) field.get(TimeTracker.class);
                result.add(new ReportUnit(value, field.getName() + " : " + value + " ms (" + (value * 100) / total + " %)"));
            }
        }
        Collections.sort(result);

        for (ReportUnit unit : result) {
            System.out.println(unit);
        }

        System.out.println("Total time: " + total);
    }

    private static class ReportUnit implements Comparable {
        private Long value;
        private String message;

        private ReportUnit(Long value, String message) {
            this.value = value;
            this.message = message;
        }

        @Override
        public int compareTo(Object o) {
            return value.compareTo(((ReportUnit) o).getValue());
        }

        public Long getValue() {
            return value;
        }

        public void setValue(Long value) {
            this.value = value;
        }

        @Override
        public String toString() {
            return message;
        }
    }

}
