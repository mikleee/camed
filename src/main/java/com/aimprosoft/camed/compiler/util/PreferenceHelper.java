package com.aimprosoft.camed.compiler.util;

import java.net.URL;

import org.eclipse.core.runtime.Platform;
import org.eclipse.ui.PlatformUI;


public class PreferenceHelper {

	public static String getPreference(String preferenceConstant,
			String defaultValue) {
		String result = PlatformUI.getPreferenceStore().getString(
				preferenceConstant);
		if (result == null || result.length() <= 0) {
			result = defaultValue;
		}
		if (result != null) {
			URL url = Platform.getBundle("cameditor")
					.getEntry(result);
			if (url != null) {
				result = url.toExternalForm();
			}
		}
		return result;
	}

	public static boolean getBoolean(String preferenceConstant) {
		return PlatformUI.getPreferenceStore().getBoolean(preferenceConstant);
	}
}
