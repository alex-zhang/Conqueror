#include "conqueror.h"

using namespace std;
using namespace cv;
using namespace aruco;

extern "C" {
  //for java debug test
  JNIEXPORT jstring JNICALL Java_com_alo7_conqueror_ConquerorJNI_stringFromJNI(JNIEnv* env, jclass cls) {
     __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConQuerorJNI_stringFromJNI");
    return env->NewStringUTF("Hello from JNI !");
  }

  JNIEXPORT void JNICALL Java_com_alo7_conqueror_ConquerorJNI_featuresDetect(JNIEnv*, jclass cls, jlong imgMatAddr) {
    Mat& imgMat = *(Mat*)imgMatAddr;
    vector<KeyPoint> keyPoints;
    Ptr<FeatureDetector> detector = FastFeatureDetector::create(50);
    detector->detect(imgMat, keyPoints);

    const int n = keyPoints.size();
    //debug draw.
    Scalar color = Scalar(255, 0, 0, 255);
    for(unsigned int i = 0; i < n; i++ ) {
        const KeyPoint& kp = keyPoints[i];
        circle(imgMat, Point(kp.pt.x, kp.pt.y), 10, color);
    }
    
    // test draw 
    //circle(imgMat, Point(50, 50), 10, Scalar(255,0,0,255));
    __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConquerorJNI_featuresDetect");
  }

  JNIEXPORT void JNICALL Java_com_alo7_conqueror_ConquerorJNI_arucoDetect(JNIEnv*, jclass cls, jlong imgSrcMatAddr, jlong imgBinMatAddr) {
    Mat& imgSrcMat = *(Mat*)imgSrcMatAddr;
    Mat& imgBinMat = *(Mat*)imgBinMatAddr;

    MarkerDetector arucoMarkerDetector;
    vector<Marker> arucoMarkers;
    int n = 0;

    // if(waitKey (30) >= 0) return;

    try {
      arucoMarkerDetector.detect(imgBinMat, arucoMarkers);
      n = arucoMarkers.size();
    }
    catch (exception &ex) {
      cout<<"Java_com_alo7_conqueror_ConquerorJNI_arucoDetect :"<<ex.what()<<endl;
    }

    //debug draw.
    //for each marker, draw info and its boundaries in the image
    Scalar color = Scalar(255, 0, 0, 255);
    for (unsigned int i = 0; i < n; i++ ) {
      // CvDrawingUtils::draw3dCube(imgSrcMat, marker, params_);
        arucoMarkers[i].draw(imgSrcMat, color);
    }
  
    //waitKey(0);//wait for key to be pressed

    // test draw 
    // circle(imgMat, Point(50, 50), 30, Scalar(255,0,0,255));    
    __android_log_print(ANDROID_LOG_DEBUG, CQRO_LOG_TAG, "Java_com_alo7_conqueror_ConquerorJNI_arucoDetect n: %d", n);
  }

  //--
}