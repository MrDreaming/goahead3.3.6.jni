package com.jni.libgo;

public class NDKgoahead {
	static {
        System.loadLibrary("go");  
    }
	
	public native void  StartGoaheadServer();
}
