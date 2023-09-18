LOCAL_PATH := ..
include $(CLEAR_VARS)
LOCAL_MODULE := reciever
LOCAL_CFLAGS += -DMODEL=reciever -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := ert_main.c reciever.c androidinitialize.c driver_android_datadisplay.c driver_android_thingspeak_read.c 
LOCAL_C_INCLUDES += C:/Users/Shesh/DOWNLO~1/Enigma/SSRP/sigpro C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/android/include C:/Users/Shesh/DOWNLO~1/Enigma/SSRP/sigpro/reciever_ert_rtw C:/PROGRA~1/MATLAB/R2023a/extern/include C:/PROGRA~1/MATLAB/R2023a/simulink/include C:/PROGRA~1/MATLAB/R2023a/rtw/c/src C:/PROGRA~1/MATLAB/R2023a/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2023a/rtw/c/ert 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
