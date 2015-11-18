LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libsmartcode
LOCAL_SRC_FILES := smartcode.h

include $(BUILD_SHARED_LIBRARY)