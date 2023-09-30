LOCAL_PATH := ..
include $(CLEAR_VARS)
LOCAL_MODULE := audio_sine_wave
LOCAL_CFLAGS += -DMODEL=audio_sine_wave -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := ert_main.c audio_sine_wave.c audio_sine_wave_data.c androidinitialize.c driver_android_accelerometer.c driver_android_datadisplay.c driver_android_plot.c 
LOCAL_C_INCLUDES += C:/Users/ragha/DOCUME~1/IITGN/Sem_3/SSRP/ASSIGN~1 C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/android/include C:/Users/ragha/DOCUME~1/IITGN/Sem_3/SSRP/ASSIGN~1/AUDIO_~1 D:/Programs/MATLAB/R2023a/extern/include D:/Programs/MATLAB/R2023a/simulink/include D:/Programs/MATLAB/R2023a/rtw/c/src D:/Programs/MATLAB/R2023a/rtw/c/src/ext_mode/common D:/Programs/MATLAB/R2023a/rtw/c/ert C:\PROGRA~3\MATLAB\SUPPOR~1\R2023a\toolbox\target\SUPPOR~1\android\include 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
