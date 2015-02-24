package com.aimprosoft.camed.compiler.util;

import org.apache.log4j.Logger;
import org.jdom.Document;

/**
 * @author mtkachenko.
 */
public class CAMEditorUtils {

    private static Logger logger = Logger.getLogger(CAMEditorUtils.class);

    public static Document translateCXFFile(String filename) {
//        DocumentFactory df = new DocumentFactory();
//        Document doc;
//        String xsl = PreferenceHelper.getPreference(PreferenceConstants.P_CXF_to_CAM_Transform_XSL, PreferenceConstants.V_CXF_to_CAM_Transform_XSL);
//
//        try {
//            doc = df.createDocument(filename);
//            TransformationEngine te = new TransformationEngine();
//            return te.transform(doc, xsl);
//        } catch (Exception e) {
//            logger.error(e, e);
//        }
        return null;
    }

}
