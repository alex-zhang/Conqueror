package com.alo7.conqueror;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceView;
import android.view.WindowManager;
import android.widget.Toast;

import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.imgproc.Imgproc;

public class MainActivity extends AppCompatActivity implements CvCameraViewListener2 {
    static private String TAG = "MainActivity";

    private OpenCVCameraView opencvCameraSurfaceView;

    private int mCameraViewColorMode = R.id.menuitem_RGBA;
    private Mat mCameraViewFrameColorMat;

    private int cameraSizeWidth;
    private int cameraSizeHeight;

    static {
        System.loadLibrary("opencv_java3");
        System.loadLibrary("conqueror");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        opencvCameraSurfaceView = (OpenCVCameraView) findViewById(R.id.opencv_camera_surface_view);
        opencvCameraSurfaceView.setVisibility(SurfaceView.VISIBLE);
        opencvCameraSurfaceView.setCvCameraViewListener(this);

        opencvCameraSurfaceView.enableFpsMeter();
        opencvCameraSurfaceView.enableView();
    }

    @Override
    public void onPause() {
        super.onPause();

        if (opencvCameraSurfaceView != null)
            opencvCameraSurfaceView.disableView();
    }

    @Override
    public void onResume() {
        super.onResume();

        if (opencvCameraSurfaceView != null)
            opencvCameraSurfaceView.enableView();
    }

    public void onDestroy() {
        super.onDestroy();
        if (opencvCameraSurfaceView != null)
            opencvCameraSurfaceView.disableView();
    }

    //CvCameraViewListener2 Impl
    //----------------------------------------------------------------------------------------------
    public void onCameraViewStarted(int width, int height) {
        cameraSizeWidth = width;
        cameraSizeHeight = height;
//        opencvCameraSurfaceView.setCameraIndex();
    }

    private void destorCurCameraViewFrameColorMat() {
        if(mCameraViewFrameColorMat != null) {
            mCameraViewFrameColorMat.release();;
            mCameraViewFrameColorMat = null;
        }
    }

    public void onCameraViewStopped() {
        destorCurCameraViewFrameColorMat();
    }

    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {
        destorCurCameraViewFrameColorMat();

        Mat cameraViewFrameRGBAColorMat = inputFrame.rgba();
        Mat cameraViewFrameGRAYColorMat = inputFrame.gray();

        mCameraViewFrameColorMat = cameraViewFrameRGBAColorMat;

         switch(mCameraViewColorMode) {
            case R.id.menuitem_GRAY:
                mCameraViewFrameColorMat = cameraViewFrameGRAYColorMat;
                break;

            case R.id.menuitem_CANNY:
                mCameraViewFrameColorMat = new Mat(cameraSizeHeight, cameraSizeWidth, CvType.CV_8UC4);
                Imgproc.Canny(cameraViewFrameGRAYColorMat, mCameraViewFrameColorMat, 80, 100);
                Imgproc.cvtColor(mCameraViewFrameColorMat, cameraViewFrameRGBAColorMat, Imgproc.COLOR_GRAY2RGBA, 4);
                break;

            case R.id.menuitem_FeatureDetect:
                ConquerorJNI.featuresDetect(mCameraViewFrameColorMat.getNativeObjAddr());
                break;

            case R.id.menuitem_ConquerorDetect:
                ConquerorJNI.arucoDetect(cameraViewFrameRGBAColorMat.getNativeObjAddr(), cameraViewFrameGRAYColorMat.getNativeObjAddr());
                break;
        }

        return mCameraViewFrameColorMat;
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        int itemId = item.getItemId();

        mCameraViewColorMode = itemId;

        if(itemId == R.id.menuitem_CallNativeTest) {
//            ConquerorJNI.stringFromJNI();
            Toast.makeText(this, ConquerorJNI.stringFromJNI(), Toast.LENGTH_LONG).show();
        }

        Log.d(TAG, "MenuIemSelected " + item.getTitle());
        return super.onOptionsItemSelected(item);
    }
}
