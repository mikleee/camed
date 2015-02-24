package com.aimprosoft.camed.compiler;

/**
 * @author mtkachenko.
 */
public class CAMCompilerException extends Exception {

    public CAMCompilerException() {
        super();
    }

    public CAMCompilerException(String message) {
        super(message);
    }

    public CAMCompilerException(String message, Throwable cause) {
        super(message, cause);
    }

    public CAMCompilerException(Throwable cause) {
        super(cause);
    }

    protected CAMCompilerException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }

}
