#include <jni.h>

#include "android/log.h"

#include "Utils/includes.h"

using namespace BNM::Structures;
using namespace BNM::Operators;

// bynamemodding.github.io for more info

//void
void (*Update)(Component*) = nullptr;
void new_Update(Component* self) {

    //Do your code stuff
    self->GetTransform()->SetPosition(Vector3(0,0,0));

    Method<void> CallMethod = Class("Namespace", "Class").GetMethod("CallMethod");

    //In the square brackets is the instance
    //In the normal brackets are the parameters
    CallMethod[self](true, 10.0f);

    //makes the original code run
    Update(self);
}

//bool
bool (*booleanthing)(Component *) = nullptr;
bool new_booleanthing(Component* self) {
    return true;
}

//float
float (*floatthing)(Component *) = nullptr;
float new_floatthing(Component* self) {
    return 0.0f;
}

//int
int (*intthing)(Component *) = nullptr;
int new_intthing(Component* self) {
    return 1;
}

void CheatInit(){
    __android_log_print(ANDROID_LOG_INFO, "Mod", "BNM Initialised");

    Class PlayerLocomotion = Class("Namespace", "PlayerLocomotion");
    auto update = PlayerLocomotion.GetMethod("Update");

    //InvokeHook for unity method such as Update and Start
    InvokeHook(update, new_Update, Update);

    auto intThing = PlayerLocomotion.GetMethod("intthing");
    //BasicHook for normal methods
    BasicHook(intThing, new_intthing, intthing);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, [[maybe_unused]] void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
    BNM::Loading::AddOnLoadedEvent(CheatInit);

    BNM::Loading::TryLoadByJNI(env);

    return JNI_VERSION_1_6;
}