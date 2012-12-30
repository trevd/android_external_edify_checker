# Copyright 2009 The Android Open Source Project

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := builtins.c \
	edify_checker.c
LOCAL_STATIC_LIBRARIES += libedify
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../bootable/recovery
LOCAL_MODULE := edify_checker

LOCAL_FORCE_STATIC_EXECUTABLE := true

include $(BUILD_HOST_EXECUTABLE)
