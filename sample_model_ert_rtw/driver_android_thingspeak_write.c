/*
 * driver_android_thingspeak_write.c
 *
 * Driver code
 *
 * Copyright 2016-2017 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;
static jmethodID methodId;

void initThingSpeakWrite(const int id, const int channelID, const char *writeAPIKey, double updateInterval) {
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "initThingSpeakConnection","(IILjava/lang/String;D)V");
    if (methodId == NULL)
        return; /* initThingSpeakConnection method not found */
    
    jstring jstrKey = (*pEnv)->NewStringUTF(pEnv, writeAPIKey);
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, methodId, id, channelID, jstrKey, updateInterval);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_write",
                            "Exception: on calling void method initThingSpeakConnection.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
}


void checkUpdateInterval(const int id, int *sendPost) {
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "checkUpdateInterval","(I)I");
    if (methodId == NULL)
        return; /* checkUpdateInterval method not found */
    
    jint value;
    value = (jint)(*pEnv)->CallIntMethod(pEnv, cachedActivityObj, methodId, id);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_write",
                            "Exception: on calling void method checkUpdateInterval.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
    
    *sendPost = value;
}

void addField(const int id, const int field, const double value) {
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "addField","(IID)V");
    if (methodId == NULL)
        return; /* addField method not found */
    
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, methodId, id, field, value);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_write",
                            "Exception: on calling void method addField.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
}

void addLocation(const int id, const double* location) {
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "addLocation","(I[D)V");
    if (methodId == NULL)
        return; /* addLocation method not found */
    
    jarray val = (*pEnv)->NewDoubleArray(pEnv, 3);
    (*pEnv)->SetDoubleArrayRegion(pEnv, val, 0, 3, location);
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, methodId, id, val);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_write",
                            "Exception: on calling void method addLocation.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
    (*pEnv)->DeleteLocalRef(pEnv, val);
}

void sendPostRequest(const int id) {
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "sendPostRequest","(I)V");
    if (methodId == NULL)
        return; /* sendPostRequest method not found */
    
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, methodId, id);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_write",
                            "Exception: on calling void method sendPostRequest.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
}