package com.aimprosoft.camed.compiler.util;

/**
 * @author mtkachenko.
 */
public class CommonUtils {

    public static void closeQuietly(AutoCloseable... streams) {
        for (AutoCloseable stream : streams) {
            if (stream != null) {
                try {
                    stream.close();
                } catch (Exception e) {
                    //ignore
                }
            }
        }
    }

    public static boolean isEmpty(String s) {
        return s != null && s.isEmpty();
    }

    public static boolean isNotEmpty(String s) {
        return !isEmpty(s);
    }

}
