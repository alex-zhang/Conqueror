LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libconqueror
LOCAL_SRC_FILES := conqueror.cpp

include $(BUILD_SHARED_LIBRARY)