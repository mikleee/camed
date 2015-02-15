package com.aimprosoft.camed.compiler.util;

/**
 * @author mtkachenko.
 */
public class CommonUtils {

    public static String getFileSeparator(){
        return System.getProperty("file.separator");
    }

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
}
