LOCAL_PATH := ..
include $(CLEAR_VARS)
OPENCV_INSTALL_MODULES:=on
include C:\Users\Shesh\Downloads\opencv-android-sdk\opencv-android-sdk\sdk\native\jni\OpenCV.mk
LOCAL_MODULE := untitled
LOCAL_CFLAGS += -DDEBUG_ANDROID -DMODEL=untitled -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := MW_TCPSendReceive.c ert_main.c untitled.c androidinitialize.c driver_android_camera.cpp driver_android_tcp_log.c 
LOCAL_C_INCLUDES += C:/Users/Shesh/DOWNLO~1/Enigma/SSRP/sigpro C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/android/include C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/SHARED~1/include C:/Users/Shesh/DOWNLO~1/Enigma/SSRP/sigpro/untitled_ert_rtw C:/PROGRA~1/MATLAB/R2023a/extern/include C:/PROGRA~1/MATLAB/R2023a/simulink/include C:/PROGRA~1/MATLAB/R2023a/rtw/c/src C:/PROGRA~1/MATLAB/R2023a/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2023a/rtw/c/ert 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
