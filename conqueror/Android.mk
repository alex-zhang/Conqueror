LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#OpenCV
#############################################
OpenCV_INSTALL_MODULES := on
OPENCV_CAMERA_MODULES := off
OPENCV_LIB_TYPE := STATIC
include /Users/alex/mwork/projects/opencv/OpenCV-android-sdk/sdk/native/jni/OpenCV.mk
#############################################

# include /Users/alex/mwork/projects/opencv/aruco-1.3.0/android/Aruco.mk

$(warning "---------------")

LOCAL_MODULE    := conqueror
#LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/*.cpp)
LOCAL_SRC_FILES := conqueror.cpp
LOCAL_LDLIBS += -lm -ldl -llog

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_STATIC_LIBRARY)