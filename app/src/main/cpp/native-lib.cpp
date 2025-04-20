#include <jni.h>

#include "android/log.h"

#include "Utils/includes.h"

using namespace BNM::Structures;
using namespace BNM::Operators;

void CheatInit(){
    __android_log_print(ANDROID_LOG_INFO, "Mod", "BNM Initialised");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, [[maybe_unused]] void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
    BNM::Loading::AddOnLoadedEvent(CheatInit);

    BNM::Loading::TryLoadByJNI(env);

    return JNI_VERSION_1_6;
}