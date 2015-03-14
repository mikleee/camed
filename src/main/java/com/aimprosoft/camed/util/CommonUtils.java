package com.aimprosoft.camed.util;

import java.io.File;

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

    public static File changeFileExtension(File file, String newExtension) {
        String path = file.getAbsolutePath();
        int extIndex = path.lastIndexOf('.');
        path = path.substring(0, extIndex + 1) + newExtension;
        return new File(path);
    }

}
