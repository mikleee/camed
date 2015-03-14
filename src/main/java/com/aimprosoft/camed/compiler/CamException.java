package com.aimprosoft.camed.compiler;

/**
 * @author mtkachenko.
 */
public class CamException extends Exception {

    public CamException() {
        super();
    }

    public CamException(String message) {
        super(message);
    }

    public CamException(String message, Throwable cause) {
        super(message, cause);
    }

    public CamException(Throwable cause) {
        super(cause);
    }

    protected CamException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }

}
