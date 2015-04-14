package com.aimprosoft.camed.run;

import java.lang.reflect.Field;

/**
 * @author mtkachenko.
 */
public class TimeTracker {

    public static long total;
    public static long constraintManagerInit;
    public static long structureCcmpilation;
    public static long parseInitTemplate;
    public static long parseCompiledTemplate;

    public static void report() throws IllegalAccessException {
        Field[] fields = TimeTracker.class.getFields();
        for (Field field : fields) {
            if (!field.getName().equals("total")) {
                long value = (Long) field.get(TimeTracker.class);
                System.out.println(field.getName() + " : " + value + " ms (" + (value * 100) / total + " %)");
            }
        }
        System.out.println("Total time: " + total);
    }

}