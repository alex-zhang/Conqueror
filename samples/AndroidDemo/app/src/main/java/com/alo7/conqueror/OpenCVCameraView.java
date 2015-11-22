package com.alo7.conqueror;

import android.content.Context;
import android.hardware.Camera;
import android.util.AttributeSet;

import org.opencv.android.JavaCameraView;

/**
 * Created by alex on 15/11/21.
 */
public class OpenCVCameraView extends JavaCameraView {
    public OpenCVCameraView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

//    public Camera getCamera() {
//        return mCamera;
//    }
}
