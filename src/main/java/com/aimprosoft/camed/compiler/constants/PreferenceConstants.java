package com.aimprosoft.camed.compiler.constants;

import org.eclipse.swt.graphics.RGB;

/**
 * Constant definitions for plug-in preferences
 */
public class PreferenceConstants {

	public final static String V_XSL_ROOT_DIRECTORY = "xsl/"; 
	
	public static final String P_XSD2CAM_ROOT_DIRECTORY = "xsd2cam_root_directory";
	
	public final static String V_XSD2CAM_ROOT_DIRECTORY = V_XSL_ROOT_DIRECTORY + "xsd2cam/"; 
	
	public static final String P_VIEW_SOURCEXSL = "viewSourceXSLPreference";
	
	public static final String V_VIEW_SOURCEXSL = V_XSL_ROOT_DIRECTORY + "viewSource.xsl";
	
	public static final String P_VIEW_WANTLISTXSL = "viewWantListXSLPreference";
	
	public static final String V_VIEW_WANTLISTXSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-to-wantlist.xsl";

	public static final String P_VIEW_DOCUMENTATIONXSL = "viewDocumentationXSLPreference";
	
	public static final String V_VIEW_DOCUMENTATIONXSL = V_XSL_ROOT_DIRECTORY + "viewDocumentation.xsl";

	public static final String P_VIEW_TABLE_DOCUMENTATIONXSL = "viewTableDocumentationXSLPreference";
	
	public static final String V_VIEW_TABLE_DOCUMENTATIONXSL = V_XSL_ROOT_DIRECTORY + "viewDocumentationTable.xsl";

	public static final String P_RUN_DOCUMENTATIONXSL = "runDocumentationXSLPreference";
	
	public static final String V_RUN_DOCUMENTATIONXSL = V_XSL_ROOT_DIRECTORY + "runDocumentation.xsl";
	
	public static final String P_CSS_STYLESHEET = "cssStylesheet";
	
	public static final String V_CSS_STYLESHEET = "styles.css";
	
	//TODO Find more elegant solution
	public static final String P_RUN_POSTRUN_XSLTSHEET = "runPostRunXSLTSuccessSheet";
	
	public static final String P_SHOW_EXCEPTION_DIALOG = "showExceptionDialog";
	
	public static final String P_EXCEPTION_PRINTSTACK = "exceptionPrintStack";
	
	public static final String P_XSD2SCHEMA = "XSD2Schema_Transformer";
	
	public static final String V_XSD2SCHEMA = V_XSD2CAM_ROOT_DIRECTORY + "xsd2schema.xsl";
	
	public static final String P_XSD2CAM = "XSD2CAM_Transformer";
	
	public final static String V_XSD2CAM = V_XSD2CAM_ROOT_DIRECTORY + "xsd2cam.xsl"; 
	
	public static final String P_CAM2EXAMPLE_XSL = "cam2example";
	
	public static final String V_CAM2EXAMPLE_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-2-example.xsl";
	
	public static final String P_HINTSEXPORT_XSL = "hints_export";
	
	public static final String V_HINTSEXPORT_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-hints-export.xsl";
	
	public static final String P_HINTSIMPORT_XSL = "hints_import";
	
	public static final String V_HINTSIMPORT_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-hints-import.xsl";
	
	public static final String P_UBLCODELIST_TRANSFORM_XSL = "UBL_codelist_transform";
	
	public static final String V_UBLCODELIST_TRANSFORM_XSL = V_XSD2CAM_ROOT_DIRECTORY + "UBLCodeList-to-CAM.xsl";
	
	public static final String P_CXF_to_CAM_Transform_XSL = "CXF_to_CAM_transform";
	
	public static final String V_CXF_to_CAM_Transform_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cxf2cam.xsl";
	
	public static final String P_CAM_2_XSD_Transform_XSL = "CAM_2_XSD_transform";
	
	public static final String V_CAM_2_XSD_Transform_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-2-xsd.xsl";
	
	public static final String P_WANTLIST_2_CAM_XSL = "WANTLIST_2_CAM_transform";
	
	public static final String V_WANTLIST_2_CAM_XSL = V_XSD2CAM_ROOT_DIRECTORY + "wantlist-2-cam.xsl";
	
	public static final String P_APPLY_WANTLIST_XSL = "Apply_Wantlist_transform";
	
	public static final String V_APPLY_WANTLIST_XSL = V_XSD2CAM_ROOT_DIRECTORY + "compress-cam-cxf.xsl";
	
	public static final String P_CREATE_DICT_XSL = "create_dict";
	
	public static final String V_CREATE_DICT_XSL = V_XSD2CAM_ROOT_DIRECTORY + "CXF-2-dictionary.xsl";
	
	public static final String P_COMPARE_2_DICT_XSL = "compare_2_dict";
	
	public static final String V_COMPARE_2_DICT_XSL = V_XSD2CAM_ROOT_DIRECTORY + "Compare-2-dictionary.xsl";
	
	public static final String P_RENAMER_XSL = "CXF-rename-util.xsl";
	
	public static final String V_RENAMER_XSL = V_XSD2CAM_ROOT_DIRECTORY + "CXF-rename-util.xsl";
	
	public static final String P_EXPANDER_XSL = "CAM_Expander";
	
	public static final String V_EXPANDER_XSL = V_XSD2CAM_ROOT_DIRECTORY + "cam-expander.xsl";

	public static final String P_ERWIN_XSL = "ERwin_refactor";
	
	public static final String V_ERWIN_XSL = V_XSD2CAM_ROOT_DIRECTORY + "tools/ERwin-refactor.xsl";

	public static final String P_SHRINK_XSL = "shrink_dictionary";
	
	public static final String V_SHRINK_XSL = V_XSD2CAM_ROOT_DIRECTORY + "tools/shrink-dictionary-context.xsl";	

	public static final String P_LOOKUPS_XSL = "XSD_2_Lookups";
	
	public static final String V_LOOKUPS_XSL = V_XSD2CAM_ROOT_DIRECTORY + "xsd2Lookup.xsl";
	
	public static final String P_CAM_LOOKUP_CONVERTER = "CAM_2_Lookup_Converter";
	
	public static final String V_CAM_LOOKUP_CONVERTER = V_XSD2CAM_ROOT_DIRECTORY + "tools/cam-lookup-xvert.xsl";
	
	public static final String P_CAM_DICTIONARIES_LOCATION = "CAM_Dictionaries_Location";
	
	public static final String V_CAM_DICTIONARIES_LOCATION = "dictionary/collection-examples";
	
	public static final String P_CAM_DICTIONARIES_CONTROL_FILE = "CAM_Dictionaries_Control_File";
	
	public static final String V_CAM_DICTIONARIES_CONTROL_FILE = V_CAM_DICTIONARIES_LOCATION + "/maritime-collection-control-file.xml";
	
	public static final String P_CAM_DICTIONARY_LOADER_XSL = "CAM_Dictionary_Loader_XSL";
	
	public static final String V_CAM_DICTIONARY_LOADER_XSL = V_XSD2CAM_ROOT_DIRECTORY +"tools/cam-dictionary-loader.xsl";
		
	public static final String P_CAM_STRUCTURE_ELEMENT_COLOR = "CAM_Structure_Element_Color";
	
	public static final RGB V_CAM_STRUCTURE_ELEMENT_COLOR = new RGB(107, 66, 38);

	public static final String P_CAM_STRUCTURE_ROOT_ELEMENT_COLOR = "CAM_Structure_Root_Element_Color";
	
	public static final RGB V_CAM_STRUCTURE_ROOT_ELEMENT_COLOR = new RGB(0, 0, 0);

	public static final String P_CAM_STRUCTURE_ELEMENT_WITH_CHILDREN_COLOR = "CAM_Structure_Element_With_Children_Color";
	
	public static final RGB V_CAM_STRUCTURE_ELEMENT_WITH_CHILDREN_COLOR = new RGB(0, 0, 156);
	
	public static final String P_CAM_STRUCTURE_ATTRIBUTE_COLOR = "CAM_Structure_Attribute_Color";
	
	public static final RGB V_CAM_STRUCTURE_ATTRIBUTE_COLOR = new RGB(0, 100, 0);
	
	public static final String P_CAM_STRUCTURE_COMMENT_COLOR = "CAM_Structure_Comment_Color";
	
	public static final RGB V_CAM_STRUCTURE_COMMENT_COLOR = new RGB(50, 205, 50);
	
	public static final String P_CAM_STRUCTURE_EXCLUDED_COLOR = "CAM_Structure_Excluded_Color";
	
	public static final RGB V_CAM_STRUCTURE_EXCLUDED_COLOR = new RGB(190, 190, 190);
	
	public static final String P_CAM_STRUCTURE_CONSTANT_COLOR = "CAM_Structure_Constant_Color";
	
	public static final RGB V_CAM_STRUCTURE_CONSTANT_COLOR = new RGB(255, 0, 0);

	public static final String P_CAM2MODEL_XSL = "CAM_2_Model";
	
	public static final String V_CAM2MODEL_XSL = V_XSD2CAM_ROOT_DIRECTORY + "tools/cam-2-model.xsl";
	
	public static final String P_CAMDICT2MODEL_XSL = "CAM_Dict_2_Model";
	
	public static final String V_CAMDICT2MODEL_XSL = V_XSD2CAM_ROOT_DIRECTORY + "tools/cam-dictionary-model.xsl";

	public static final String P_MIND_MAP_VIEWER_FILE = "Mind_Map_Viewer_Location";
	
	public static final String P_MIND_MAP_NONE_DETAILS = "Mind_Map_None_Details";
	
	public static final String P_MIND_MAP_CONTENT_DETAILS = "Mind_Map_Content_Details";
	
	public static final String P_MIND_MAP_CARDINALITY_DETAILS = "Mind_Map_Cardinality_Details";
	
	public static final String P_MIND_MAP_DESCRIPTION_DETAILS = "Mind_Map_Description_Details";
	
}
