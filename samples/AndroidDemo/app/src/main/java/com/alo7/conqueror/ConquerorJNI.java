package com.alo7.conqueror;

/**
 * Created by alex on 15/11/19.
 */
public class ConquerorJNI {

    //for debug test
    static public native String stringFromJNI();
    static public native void featuresDetect(long imgMatAddr);
    static public native void arucoDetect(long imgSrcMatAddr, long imgBinMatAddr);
}