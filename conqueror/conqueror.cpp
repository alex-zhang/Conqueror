#include "conqueror.h"

// USING_NS_CQRO

// CameraDetcor* mainCameraDetcor = NULL;

// void destoryCurCameraDetcor() {
//   if(mainCameraDetcor) {
//       mainCameraDetcor->release();
//       delete mainCameraDetcor;
//       mainCameraDetcor = NULL;
//     }
// }

extern "C" {
  //for java debug test
  //com.alo7.conqueror.ConquerorJNI.stringFromJNI
  JNIEXPORT jstring JNICALL Java_com_alo7_conqueror_ConQuerorJNI_stringFromJNI(JNIEnv* env, jclass cls) {
     __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConQuerorJNI_stringFromJNI");
    return env->NewStringUTF("Hello from JNI !");
  }

  JNIEXPORT void JNICALL Java_com_alo7_conqueror_ConquerorJNI_featuresDetect(JNIEnv*, jclass cls, jlong grayMatAddr, jlong rgbaMatAddr) {
    // Mat& grayMat  = *(Mat*)grayMatAddr;
    // Mat& rgbaMat = *(Mat*)rgbaMatAddr;
    // vector<KeyPoint> v;

    // Ptr<FeatureDetector> detector = FastFeatureDetector::create(50);
    // detector->detect(grayMat, v);
    // for( unsigned int i = 0; i < v.size(); i++ ) {
    //     const KeyPoint& kp = v[i];
    //     circle(rgbaMat, Point(kp.pt.x, kp.pt.y), 10, Scalar(255,0,0,255));
    // }
    __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConquerorJNI_featuresDetect");
  }

  JNIEXPORT void JNICALL Java_com_alo7_conqueror_ConquerorJNI_arucoDetect(JNIEnv*, jclass cls, jlong grayMatAddr, jlong rgbaMatAddr) {
    // Mat& grayMat  = *(Mat*)grayMatAddr;
    // Mat& rgbaMat = *(Mat*)rgbaMatAddr;
    // vector<KeyPoint> v;

    // Ptr<FeatureDetector> detector = FastFeatureDetector::create(50);
    // detector->detect(grayMat, v);
    // for( unsigned int i = 0; i < v.size(); i++ ) {
    //     const KeyPoint& kp = v[i];
    //     circle(rgbaMat, Point(kp.pt.x, kp.pt.y), 10, Scalar(255,0,0,255));
    // }
    __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConquerorJNI_arucoDetect");
  }

  //--
}