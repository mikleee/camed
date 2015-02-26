package com.aimprosoft.camed.compiler.util;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.io.StreamTokenizer;
import java.io.StringReader;
import java.util.Stack;

public class Parser {


    static Logger logger = LoggerFactory.getLogger(Parser.class);

    private Expression expr;
    private boolean VariableExists = false;
    private Boolean ignoreSingleQuote = Boolean.FALSE;

    public Parser() {

    }


    public Parser(String inputString) throws ParserException {
        makeParser(inputString);

    }

    public Parser(String inputString, Boolean ignoreSingleQuote) throws ParserException {
        this.ignoreSingleQuote = ignoreSingleQuote;
        makeParser(inputString);

    }

    public void makeParser(String inputString, Boolean ignoreSingleQuote) throws ParserException {
        setIgnoreSingleQuote(ignoreSingleQuote);
        makeParser(inputString);
    }

    private void makeParser(String inputString) throws ParserException {
        StringReader in = new StringReader(inputString);
        StreamTokenizer parser = new StreamTokenizer(in);

        expr = new Expression();
        int brackets = 0;
        int squareBrackets = 0;
        int roundBrackets = 0;
        parser.resetSyntax();
        parser.wordChars(32, 255);
        parser.whitespaceChars(0, 31); //tab, line feed, return
        Stack<Object> stack = new Stack<Object>();

        parser.ordinaryChars('(', ')');
        parser.ordinaryChars('[', ']');
        parser.ordinaryChar(',');
        parser.ordinaryChar('$');
        parser.ordinaryChar('\\');
        //parser.quoteChar('"');
        //if (ignoreSingleQuote == Boolean.FALSE){
        parser.quoteChar('\'');
        //}
        try {
            while (parser.nextToken() != StreamTokenizer.TT_EOF) {
                if (parser.ttype == '(') {
                    Character c = Character.valueOf((char) parser.ttype);
                    if (logger.isDebugEnabled())
                        logger.debug("openbracket(");
                    brackets++;
                    if (roundBrackets == 0)
                        roundBrackets++;
                    else {
                        roundBrackets++;
                        expr.setPart(c.toString());
                    }
                    if (logger.isDebugEnabled())
                        logger.debug("brackets:" + brackets + " round:" + roundBrackets);
                } else if (parser.ttype == '[') {
                    Character c = Character.valueOf((char) parser.ttype);
                    if (logger.isDebugEnabled())
                        logger.debug("openbracket[");
                    brackets++;
                    squareBrackets++;
                    expr.setPart(c.toString());
                    if (logger.isDebugEnabled())
                        logger.debug("brackets:" + brackets + " square:" + squareBrackets);
                } else if (parser.ttype == ')') {
                    Character c = Character.valueOf((char) parser.ttype);
                    if (logger.isDebugEnabled())
                        logger.debug("closebracket)");
                    if (brackets == 0) {
                        throw new ParserException("Brackets do not match\n");
                    }
                    if (roundBrackets == 0) {
                        throw new ParserException("Brackets do not match\n");
                    }
                    if (roundBrackets > 1) {
                        roundBrackets--;
                        expr.setPart(c.toString());
                    } else {
                        roundBrackets--;
                    }
                    if (logger.isDebugEnabled())
                        logger.debug("brackets:" + brackets + " Round Brackets:" + roundBrackets);
                } else if (parser.ttype == ']') {
                    Character c = Character.valueOf((char) parser.ttype);
                    if (logger.isDebugEnabled())
                        logger.debug("closebracket]");
                    if (brackets == 0) {
                        throw new ParserException("Brackets do not match\n");
                    }
                    brackets--;
                    if (squareBrackets == 0) {
                        throw new ParserException("Brackets do not match\n");
                    }
                    squareBrackets--;
                    expr.setPart(c.toString());

                    if (logger.isDebugEnabled())
                        logger.debug("brackets:" + brackets + " Square Brackets:" + squareBrackets);
                } else if (parser.ttype == ',') {
                    if (logger.isDebugEnabled())
                        logger.debug("comma");
                    if (roundBrackets == 1)
                        expr.incrementParam();
                    else
                        expr.setPart(",");

                } else if (parser.ttype == '$') {

                    if (logger.isDebugEnabled())
                        logger.debug("variable:");
                    VariableExists = true;
                    expr.setPart("$");

                } else if (parser.ttype == '\\') {

                    if (logger.isDebugEnabled())
                        logger.debug("\\");
                    expr.setPart("\\");

                } else if (parser.ttype == '"') {
                    if (logger.isDebugEnabled())
                        logger.debug("literal:" + parser.sval);
                    expr.setPart(parser.sval);
                } else if (ignoreSingleQuote.equals(Boolean.FALSE) && parser.ttype == '\'') {
                    if (logger.isDebugEnabled())
                        logger.debug("literal(false):" + parser.sval);
                    expr.setPart("'" + parser.sval + "'");
                } else if (parser.ttype == '\'') {
                    if (logger.isDebugEnabled())
                        logger.debug("literal(true):" + parser.sval);
                    expr.setPart("'" + parser.sval + "'");
                } else if (parser.ttype == StreamTokenizer.TT_WORD) {
                    if (brackets == 0) {
                        if (logger.isDebugEnabled())
                            logger.debug("Expresion: " + parser.sval);
                        expr.setName(parser.sval);
                    } else {
                        if (logger.isDebugEnabled())
                            logger.debug("sval: " + parser.sval);
                        expr.setPart(parser.sval);
                    }
                } else if (logger.isDebugEnabled())
                    logger.debug("Error: " + (char) parser.ttype + "sval: " + parser.sval);
            }
        } catch (IOException e) {
            throw new ParserException("IOException:" + e.getMessage());
        } catch (ParserException e) {
            throw new ParserException(e.getMessage());
        }
        if (!(stack.empty())) {
            throw new ParserException("Brackets do not match\n" + stack);
        }
        if (logger.isDebugEnabled()) {
            logger.debug(expr.getName() + ":" + expr.getPart(0) + "-" + expr.getPart(1));
        }
    }

    public Expression getExpression() {
        return expr;
    }


    public static class Expression {
        private String name;
        private int paramNum = 0;
        private String[] parts = new String[10];

        Expression() {
        }

        Expression(String name) {
            this.name = name;
        }

        public String getName() {
            return this.name;
        }

        public String getPart(int index) {
            return this.parts[index];
        }

        public String[] getParts() {
            return parts;
        }

        int incrementParam() {
            paramNum++;
            return paramNum;
        }

        void setName(String string) {
            name = string;
        }

        void setPart(String part1) {

            if (this.parts[paramNum] == null) {
                this.parts[paramNum] = part1;
            } else {
                this.parts[paramNum] = this.parts[paramNum] + part1;
            }
        }

        void setParts(String[] strings) {
            parts = strings;
        }

    }

    /**
     * isVariableExists
     *
     * @return boolean
     */
    public boolean hasVariableExists() {
        return VariableExists;
    }

    static public class ParserException extends Exception {
        /**
         *
         */
        private static final long serialVersionUID = 5028048370981467818L;

        public ParserException() {
            super();
        }

        public ParserException(String s) {
            super(s);
        }
    }

    public Boolean getIgnoreSingleQuote() {
        return ignoreSingleQuote;
    }

    public void setIgnoreSingleQuote(Boolean ignoreSingleQuote) {
        this.ignoreSingleQuote = ignoreSingleQuote;
    }

}
