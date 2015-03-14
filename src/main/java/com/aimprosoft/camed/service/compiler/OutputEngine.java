package com.aimprosoft.camed.service.compiler;

import org.jdom.*;
import org.jdom.output.EscapeStrategy;
import org.jdom.output.Format;

import javax.xml.transform.Result;
import java.io.IOException;
import java.io.Serializable;
import java.io.Writer;
import java.util.Comparator;
import java.util.List;
import java.util.Stack;
import java.util.TreeSet;


public class OutputEngine implements Cloneable {

    // For normal output
    private Format userFormat = Format.getRawFormat();
    // For xml:space="preserve"
    protected static final Format preserveFormat = Format.getRawFormat();
    // What's currently in use
    protected Format currentFormat = userFormat;
    //Whether output escaping is enabled for the being processed
    //Element - default is true
    private boolean escapeOutput = true;

    public OutputEngine(Format format) {
        userFormat = format;
        currentFormat = userFormat;
    }


    /**
     * Print out an <code>{@link org.jdom.Element}</code>, including
     * its <code>{@link org.jdom.Attribute}</code>s, and all
     * contained (child) elements, etc.
     *
     * @param element <code>Element</code> to output.
     * @param out     <code>Writer</code> to use.
     */
    public void output(Element element, Writer out) throws IOException {
        // If this is the root element we could pre-initialize the
        // namespace stack with the namespaces
        printElement(out, element, 0, createNamespaceStack());
        out.flush();
    }

    /**
     * This will handle printing of comments.
     *
     * @param comment <code>Comment</code> to write.
     * @param out     <code>Writer</code> to use.
     */
    protected void printComment(Writer out, Comment comment) throws IOException {
        out.write("<!--");
        out.write(comment.getText());
        out.write("-->");
    }

    /**
     * This will handle printing of processing instructions.
     *
     * @param pi  <code>ProcessingInstruction</code> to write.
     * @param out <code>Writer</code> to use.
     */
    protected void printProcessingInstruction(Writer out, ProcessingInstruction pi) throws IOException {
        String target = pi.getTarget();
        boolean piProcessed = false;

        if (!currentFormat.getIgnoreTrAXEscapingPIs()) {
            if (target.equals(Result.PI_DISABLE_OUTPUT_ESCAPING)) {
                escapeOutput = false;
                piProcessed = true;
            } else if (target.equals(Result.PI_ENABLE_OUTPUT_ESCAPING)) {
                escapeOutput = true;
                piProcessed = true;
            }
        }
        if (!piProcessed) {
            String rawData = pi.getData();

            // Write <?target data?> or if no data then just <?target?>
            if (!"".equals(rawData)) {
                out.write("<?");
                out.write(target);
                out.write(" ");
                out.write(rawData);
                out.write("?>");
            } else {
                out.write("<?");
                out.write(target);
                out.write("?>");
            }
        }
    }

    /**
     * This will handle printing a <code>{@link org.jdom.EntityRef}</code>.
     * Only the entity reference such as <code>&amp;entity;</code>
     * will be printed. However, subclasses are free to override
     * this method to print the contents of the entity instead.
     *
     * @param entity <code>EntityRef</code> to output.
     * @param out    <code>Writer</code> to use.
     */
    protected void printEntityRef(Writer out, EntityRef entity) throws IOException {
        out.write("&");
        out.write(entity.getName());
        out.write(";");
    }

    /**
     * This will handle printing of <code>{@link org.jdom.CDATA}</code> text.
     *
     * @param cdata <code>CDATA</code> to output.
     * @param out   <code>Writer</code> to use.
     */
    protected void printCDATA(Writer out, CDATA cdata) throws IOException {
        String str = (currentFormat.getTextMode() == Format.TextMode.NORMALIZE)
                ? cdata.getTextNormalize()
                : ((currentFormat.getTextMode() == Format.TextMode.TRIM) ?
                cdata.getText().trim() : cdata.getText());
        out.write("<![CDATA[");
        out.write(str);
        out.write("]]>");
    }

    /**
     * This will handle printing a string.  Escapes the element entities,
     * trims interior whitespace, etc. if necessary.
     */
    private void printString(Writer out, String str) throws IOException {
        if (currentFormat.getTextMode() == Format.TextMode.NORMALIZE) {
            str = Text.normalizeString(str);
        } else if (currentFormat.getTextMode() == Format.TextMode.TRIM) {
            str = str.trim();
        }
        out.write(escapeElementEntities(str));
    }

    /**
     * This will handle printing of a <code>{@link org.jdom.Element}</code>,
     * its <code>{@link org.jdom.Attribute}</code>s, and all contained (child)
     * elements, etc.
     *
     * @param element    <code>Element</code> to output.
     * @param out        <code>Writer</code> to use.
     * @param level      <code>int</code> level of indention.
     * @param namespaces <code>List</code> stack of Namespaces in scope.
     */
    protected void printElement(Writer out, Element element, int level, NamespaceStack namespaces) throws IOException {

        List<?> attributes = element.getAttributes();
        List<?> content = element.getContent();

        // Check for xml:space and adjust format settings
        String space = null;
        if (attributes != null) {
            space = element.getAttributeValue("space", Namespace.XML_NAMESPACE);
        }

        Format previousFormat = currentFormat;

        if ("default".equals(space)) {
            currentFormat = userFormat;
        } else if ("preserve".equals(space)) {
            currentFormat = preserveFormat;
        }

        // Print the beginning of the tag plus attributes and any
        // necessary namespace declarations
        out.write("<");
        printQualifiedName(out, element);

        // Mark our namespace starting point
        int previouslyDeclaredNamespaces = namespaces.size();

        // Print the element's namespace, if appropriate
        printElementNamespace(out, element, namespaces);

        // Print out additional namespace declarations
        printAdditionalNamespaces(out, element, namespaces);

        // Print out attributes
        if (attributes != null)
            printAttributes(out, attributes, namespaces);

        // Depending on the settings (newlines, textNormalize, etc), we may
        // or may not want to print all of the content, so determine the
        // index of the start of the content we're interested
        // in based on the current settings.

        int start = skipLeadingWhite(content, 0);
        int size = content.size();
        if (start >= size) {
            // Case content is empty or all insignificant whitespace
            if (currentFormat.getExpandEmptyElements()) {
                out.write("></");
                printQualifiedName(out, element);
                out.write(">");
            } else {
                out.write(" />");
            }
        } else {
            out.write(">");

            // For a special case where the content is only CDATA
            // or Text we don't want to indent after the start or
            // before the end tag.

            if (nextNonText(content, start) < size) {
                // Case Mixed Content - normal indentation
                newline(out);
                printContentRange(out, content, start, size,
                        level + 1, namespaces);
                newline(out);
                indent(out, level);
            } else {
                // Case all CDATA or Text - no indentation
                printTextRange(out, content, start, size);
            }
            out.write("</");
            printQualifiedName(out, element);
            out.write(">");
        }

        // remove declared namespaces from stack
        while (namespaces.size() > previouslyDeclaredNamespaces) {
            namespaces.pop();
        }

        // Restore our format settings
        currentFormat = previousFormat;
    }

    /**
     * This will handle printing of content within a given range.
     * The range to print is specified in typical Java fashion; the
     * starting index is inclusive, while the ending index is
     * exclusive.
     *
     * @param content    <code>List</code> of content to output
     * @param start      index of first content node (inclusive.
     * @param end        index of last content node (exclusive).
     * @param out        <code>Writer</code> to use.
     * @param level      <code>int</code> level of indentation.
     * @param namespaces <code>List</code> stack of Namespaces in scope.
     */
    @SuppressWarnings("StatementWithEmptyBody")
    private void printContentRange(Writer out, List<?> content, int start, int end, int level, NamespaceStack namespaces) throws IOException {
        boolean firstNode; // Flag for 1st node in content
        Object next;       // Node we're about to print
        int first, index;  // Indexes into the list of content

        index = start;
        while (index < end) {
            firstNode = (index == start);
            next = content.get(index);

            //
            // Handle consecutive CDATA, Text, and EntityRef nodes all at once
            //
            if ((next instanceof Text) || (next instanceof EntityRef)) {
                first = skipLeadingWhite(content, index);
                // Set index to next node for loop
                index = nextNonText(content, first);

                // If it's not all whitespace - print it!
                if (first < index) {
                    if (!firstNode)
                        newline(out);
                    indent(out, level);
                    printTextRange(out, content, first, index);
                }
                continue;
            }

            //
            // Handle other nodes
            //
            if (!firstNode) {
                newline(out);
            }

            indent(out, level);

            if (next instanceof Comment) {
                printComment(out, (Comment) next);
            } else if (next instanceof Element) {
                printElement(out, (Element) next, level, namespaces);
            } else if (next instanceof ProcessingInstruction) {
                printProcessingInstruction(out, (ProcessingInstruction) next);
            } else {
                // XXX if we get here then we have a illegal content, for
                //     now we'll just ignore it (probably should throw
                //     a exception)
            }

            index++;
        } /* while */
    }

    /**
     * This will handle printing of a sequence of <code>{@link org.jdom.CDATA}</code>
     * or <code>{@link org.jdom.Text}</code> nodes.  It is an error to have any other
     * pass this method any other type of node.
     *
     * @param content <code>List</code> of content to output
     * @param start   index of first content node (inclusive).
     * @param end     index of last content node (exclusive).
     * @param out     <code>Writer</code> to use.
     */
    private void printTextRange(Writer out, List<?> content, int start, int end) throws IOException {
        String previous; // Previous text printed
        Object node;     // Next node to print
        String next;     // Next text to print

        previous = null;

        // Remove leading whitespace-only nodes
        start = skipLeadingWhite(content, start);

        int size = content.size();
        if (start < size) {
            // And remove trialing whitespace-only nodes
            end = skipTrailingWhite(content, end);

            for (int i = start; i < end; i++) {
                node = content.get(i);

                // Get the unmangled version of the text
                // we are about to print
                if (node instanceof Text) {
                    next = ((Text) node).getText();
                } else if (node instanceof EntityRef) {
                    next = "&" + ((EntityRef) node).getValue() + ";";
                } else {
                    throw new IllegalStateException("Should see only " +
                            "CDATA, Text, or EntityRef");
                }

                // This may save a little time
                if (next == null || "".equals(next)) {
                    continue;
                }

                // Determine if we need to pad the output (padding is
                // only need in trim or normalizing mode)
                if (previous != null) { // Not 1st node
                    if (currentFormat.getTextMode() == Format.TextMode.NORMALIZE ||
                            currentFormat.getTextMode() == Format.TextMode.TRIM) {
                        if ((endsWithWhite(previous)) ||
                                (startsWithWhite(next))) {
                            out.write(" ");
                        }
                    }
                }

                // Print the node
                if (node instanceof CDATA) {
                    printCDATA(out, (CDATA) node);
                } else if (node instanceof EntityRef) {
                    printEntityRef(out, (EntityRef) node);
                } else {
                    printString(out, next);
                }

                previous = next;
            }
        }
    }

    /**
     * This will handle printing of any needed <code>{@link org.jdom.Namespace}</code>
     * declarations.
     *
     * @param ns  <code>Namespace</code> to print definition of
     * @param out <code>Writer</code> to use.
     */
    private void printNamespace(Writer out, Namespace ns, NamespaceStack namespaces) throws IOException {
        String prefix = ns.getPrefix();
        String uri = ns.getURI();

        // Already printed namespace decl?
        if (uri.equals(namespaces.getURI(prefix))) {
            return;
        }
        newline(out);
        out.write(" xmlns");
        if (!prefix.equals("")) {
            out.write(":");
            out.write(prefix);
        }
        out.write("=\"");
        out.write(uri);
        out.write("\"");
        namespaces.push(ns);
    }

    /**
     * This will handle printing of a <code>{@link org.jdom.Attribute}</code> list.
     *
     * @param attributes <code>List</code> of Attribute objcts
     * @param out        <code>Writer</code> to use
     */
    protected void printAttributes(Writer out, List<?> attributes, NamespaceStack namespaces) throws IOException {

        // I do not yet handle the case where the same prefix maps to
        // two different URIs. For attributes on the same element
        // this is illegal; but as yet we don't throw an exception
        // if someone tries to do this
        // Set prefixes = new HashSet();
        for (Object attribute1 : attributes) {
            Attribute attribute = (Attribute) attribute1;
            Namespace ns = attribute.getNamespace();
            if ((ns != Namespace.NO_NAMESPACE) &&
                    (ns != Namespace.XML_NAMESPACE)) {
                printNamespace(out, ns, namespaces);
            }

            out.write(" ");
            printQualifiedName(out, attribute);
            out.write("=");

            out.write("\"");
            out.write(escapeAttributeEntities(attribute.getValue()));
            out.write("\"");
        }
    }

    private void printElementNamespace(Writer out, Element element, NamespaceStack namespaces) throws IOException {
        // Add namespace decl only if it's not the XML namespace and it's
        // not the NO_NAMESPACE with the prefix "" not yet mapped
        // (we do output xmlns="" if the "" prefix was already used and we
        // need to reclaim it for the NO_NAMESPACE)
        Namespace ns = element.getNamespace();
        if (ns == Namespace.XML_NAMESPACE) {
            return;
        }
        if (!((ns == Namespace.NO_NAMESPACE) && (namespaces.getURI("") == null))) {
            printNamespace(out, ns, namespaces);
        }
    }

    private void printAdditionalNamespaces(Writer out, Element element, NamespaceStack namespaces) throws IOException {
        List<?> list = element.getAdditionalNamespaces();
        if (list != null) {
//            for (int i = 0; i < list.size(); i++) {
//                Namespace additional = (Namespace)list.get(i);
//                printNamespace(out, additional, namespaces);
//            }
            TreeSet<Namespace> sorted = new TreeSet<Namespace>(new NamespaceComparator());
            for (Object aList : list) {
                Namespace ns = (Namespace) aList;
                sorted.add(ns);
            }
            for (Namespace additional : sorted) {
                printNamespace(out, additional, namespaces);
            }
        }
    }

    // * * * * * * * * * * Support methods * * * * * * * * * *
    // * * * * * * * * * * Support methods * * * * * * * * * *

    /**
     * This will print a new line only if the newlines flag was set to
     * true.
     *
     * @param out <code>Writer</code> to use
     */
    private void newline(Writer out) throws IOException {
        if (currentFormat.getIndent() != null) {
            out.write(currentFormat.getLineSeparator());
        }
    }

    /**
     * This will print indents (only if the newlines flag was
     * set to <code>true</code>, and indent is non-null).
     *
     * @param out   <code>Writer</code> to use
     * @param level current indent level (number of tabs)
     */
    private void indent(Writer out, int level) throws IOException {
        if (currentFormat.getIndent() == null ||
                currentFormat.getIndent().equals("")) {
            return;
        }

        for (int i = 0; i < level; i++) {
            out.write(currentFormat.getIndent());
        }
    }

    // Returns the index of the first non-all-whitespace CDATA or Text,
    // index = content.size() is returned if content contains
    // all whitespace.
    // @param start index to begin search (inclusive)
    private int skipLeadingWhite(List<?> content, int start) {
        if (start < 0) {
            start = 0;
        }

        int index = start;
        int size = content.size();
        if (currentFormat.getTextMode() == Format.TextMode.TRIM_FULL_WHITE
                || currentFormat.getTextMode() == Format.TextMode.NORMALIZE
                || currentFormat.getTextMode() == Format.TextMode.TRIM) {
            while (index < size) {
                if (!isAllWhitespace(content.get(index))) {
                    return index;
                }
                index++;
            }
        }
        return index;
    }

    // Return the index + 1 of the last non-all-whitespace CDATA or
    // Text node,  index < 0 is returned
    // if content contains all whitespace.
    // @param start index to begin search (exclusive)
    private int skipTrailingWhite(List<?> content, int start) {
        int size = content.size();
        if (start > size) {
            start = size;
        }

        int index = start;
        if (currentFormat.getTextMode() == Format.TextMode.TRIM_FULL_WHITE
                || currentFormat.getTextMode() == Format.TextMode.NORMALIZE
                || currentFormat.getTextMode() == Format.TextMode.TRIM) {
            while (index >= 0) {
                if (!isAllWhitespace(content.get(index - 1)))
                    break;
                --index;
            }
        }
        return index;
    }

    // Return the next non-CDATA, non-Text, or non-EntityRef node,
    // index = content.size() is returned if there is no more non-CDATA,
    // non-Text, or non-EntiryRef nodes
    // @param start index to begin search (inclusive)
    private static int nextNonText(List<?> content, int start) {
        if (start < 0) {
            start = 0;
        }

        int index = start;
        int size = content.size();
        while (index < size) {
            Object node = content.get(index);
            if (!((node instanceof Text) || (node instanceof EntityRef))) {
                return index;
            }
            index++;
        }
        return size;
    }

    // Determine if a Object is all whitespace
    private boolean isAllWhitespace(Object obj) {
        String str;

        if (obj instanceof String) {
            str = (String) obj;
        } else if (obj instanceof Text) {
            str = ((Text) obj).getText();
        } else if (obj instanceof EntityRef) {
            return false;
        } else {
            return false;
        }

        for (int i = 0; i < str.length(); i++) {
            if (!isWhitespace(str.charAt(i)))
                return false;
        }
        return true;
    }

    // Determine if a string starts with a XML whitespace.
    private boolean startsWithWhite(String str) {
        return (str != null) &&
                (str.length() > 0) &&
                isWhitespace(str.charAt(0));
    }

    // Determine if a string ends with a XML whitespace.
    private boolean endsWithWhite(String str) {
        return (str != null) &&
                (str.length() > 0) &&
                isWhitespace(str.charAt(str.length() - 1));
    }

    // Determine if a character is a XML whitespace.
    // XXX should this method be in Verifier
    private static boolean isWhitespace(char c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r';
    }

    /**
     * This will take the pre-defined entities in XML 1.0 and
     * convert their character representation to the appropriate
     * entity reference, suitable for XML attributes.  It does not convert
     * the single quote (') because it's not necessary as the outputter
     * writes attributes surrounded by double-quotes.
     *
     * @param str <code>String</code> input to escape.
     * @return <code>String</code> with escaped content.
     */
    public String escapeAttributeEntities(String str) {
        StringBuffer buffer;
        char ch;
        String entity;
        EscapeStrategy strategy = currentFormat.getEscapeStrategy();

        buffer = null;
        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            switch (ch) {
                case '<':
                    entity = "&lt;";
                    break;
                case '>':
                    entity = "&gt;";
                    break;
/*
                case '\'' :
                    entity = "&apos;";
                    break;
*/
                case '\"':
                    entity = "&quot;";
                    break;
                case '&':
                    entity = "&amp;";
                    break;
                case '\r':
                    entity = "&#xD;";
                    break;
                case '\t':
                    entity = "&#x9;";
                    break;
                case '\n':
                    entity = "&#xA;";
                    break;
                default:
                    if (strategy.shouldEscape(ch)) {
                        entity = "&#x" + Integer.toHexString(ch) + ";";
                    } else {
                        entity = null;
                    }
                    break;
            }
            if (buffer == null) {
                if (entity != null) {
                    // An entity occurred, so we'll have to use StringBuffer
                    // (allocate room for it plus a few more entities).
                    buffer = new StringBuffer(str.length() + 20);
                    // Copy previous skipped characters and fall through
                    // to pickup current character
                    buffer.append(str.substring(0, i));
                    buffer.append(entity);
                }
            } else {
                if (entity == null) {
                    buffer.append(ch);
                } else {
                    buffer.append(entity);
                }
            }
        }

        // If there were any entities, return the escaped characters
        // that we put in the StringBuffer. Otherwise, just return
        // the unmodified input string.
        return (buffer == null) ? str : buffer.toString();
    }


    /**
     * This will take the three pre-defined entities in XML 1.0
     * (used specifically in XML elements) and convert their character
     * representation to the appropriate entity reference, suitable for
     * XML element content.
     *
     * @param str <code>String</code> input to escape.
     * @return <code>String</code> with escaped content.
     */
    public String escapeElementEntities(String str) {
        if (!escapeOutput) return str;

        StringBuffer buffer;
        char ch;
        String entity;
        EscapeStrategy strategy = currentFormat.getEscapeStrategy();

        buffer = null;
        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            switch (ch) {
                case '<':
                    entity = "&lt;";
                    break;
                case '>':
                    entity = "&gt;";
                    break;
                case '&':
                    entity = "&amp;";
                    break;
                case '\r':
                    entity = "&#xD;";
                    break;
                case '\n':
                    entity = currentFormat.getLineSeparator();
                    break;
                default:
                    if (strategy.shouldEscape(ch)) {
                        entity = "&#x" + Integer.toHexString(ch) + ";";
                    } else {
                        entity = null;
                    }
                    break;
            }
            if (buffer == null) {
                if (entity != null) {
                    // An entity occurred, so we'll have to use StringBuffer
                    // (allocate room for it plus a few more entities).
                    buffer = new StringBuffer(str.length() + 20);
                    // Copy previous skipped characters and fall through
                    // to pickup current character
                    buffer.append(str.substring(0, i));
                    buffer.append(entity);
                }
            } else {
                if (entity == null) {
                    buffer.append(ch);
                } else {
                    buffer.append(entity);
                }
            }
        }

        // If there were any entities, return the escaped characters
        // that we put in the StringBuffer. Otherwise, just return
        // the unmodified input string.
        return (buffer == null) ? str : buffer.toString();
    }

    /**
     * Returns a copy of this XMLOutputter.
     */
    @Override
    public Object clone() throws CloneNotSupportedException {
        // Implementation notes: Since all state of an XMLOutputter is
        // embodied in simple private instance variables, Object.clone
        // can be used.  Note that since Object.clone is totally
        // broken, we must catch an exception that will never be
        // thrown.
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            // even though this should never ever happen, it's still
            // possible to fool Java into throwing a
            // CloneNotSupportedException.  If that happens, we
            // shouldn't swallow it.
            throw new RuntimeException(e.toString());
        }
    }

    /**
     * Return a string listing of the settings for this
     * XMLOutputter instance.
     *
     * @return a string listing the settings for this XMLOutputter instance
     */
    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        for (int i = 0; i < userFormat.getLineSeparator().length(); i++) {
            char ch = userFormat.getLineSeparator().charAt(i);
            switch (ch) {
                case '\r':
                    buffer.append("\\r");
                    break;
                case '\n':
                    buffer.append("\\n");
                    break;
                case '\t':
                    buffer.append("\\t");
                    break;
                default:
                    buffer.append("[")
                            .append((int) ch)
                            .append("]");
                    break;
            }
        }

        return (
                "XMLOutputter[omitDeclaration = " + userFormat.getOmitDeclaration() + ", " +
                        "encoding = " + userFormat.getEncoding() + ", " +
                        "omitEncoding = " + userFormat.getOmitEncoding() + ", " +
                        "indent = '" + userFormat.getIndent() + "'" + ", " +
                        "expandEmptyElements = " + userFormat.getExpandEmptyElements() + ", " +
                        "lineSeparator = '" + buffer.toString() + "', " +
                        "textMode = " + userFormat.getTextMode() + "]"
        );
    }


    private NamespaceStack createNamespaceStack() {
        return new NamespaceStack();
    }

    // Support method to print a name without using elt.getQualifiedName()
    // and thus avoiding a StringBuffer creation and memory churn
    private void printQualifiedName(Writer out, Element e) throws IOException {
        if (e.getNamespace().getPrefix().length() == 0) {
            out.write(e.getName());
        } else {
            out.write(e.getNamespace().getPrefix());
            out.write(':');
            out.write(e.getName());
        }
    }

    // Support method to print a name without using att.getQualifiedName()
    // and thus avoiding a StringBuffer creation and memory churn
    private void printQualifiedName(Writer out, Attribute a) throws IOException {
        String prefix = a.getNamespace().getPrefix();
        if ((prefix != null) && (!prefix.equals(""))) {
            out.write(prefix);
            out.write(':');
            out.write(a.getName());
        } else {
            out.write(a.getName());
        }
    }


    private class NamespaceStack {

        private Stack prefixes;
        private Stack uris;

        public NamespaceStack() {
            prefixes = new Stack();
            uris = new Stack();
        }

        @SuppressWarnings("unchecked")
        public void push(Namespace ns) {
            prefixes.push(ns.getPrefix());
            uris.push(ns.getURI());
        }

        public String pop() {
            String prefix = (String) prefixes.pop();
            uris.pop();

            return prefix;
        }

        public int size() {
            return prefixes.size();
        }

        public String getURI(String prefix) {
            int index = prefixes.lastIndexOf(prefix);
            if (index == -1) {
                return null;
            }
            return (String) uris.elementAt(index);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            String separator = System.getProperty("line.separator");
            builder
                    .append("Stack: ")
                    .append(prefixes.size())
                    .append(separator);
            for (int i = 0; i < prefixes.size(); i++) {
                builder
                        .append(prefixes.elementAt(i))
                        .append("&")
                        .append(uris.elementAt(i))
                        .append(separator);
            }
            return builder.toString();
        }

    }

    private class NamespaceComparator implements Comparator<Namespace>, Serializable {

        private static final long serialVersionUID = 1L;

        @Override
        public int compare(Namespace ns1, Namespace ns2) {
            return ns1.getPrefix().compareToIgnoreCase(ns2.getPrefix());
        }

    }

}