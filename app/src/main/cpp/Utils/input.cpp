#import "Input.h"

using namespace BNM;

bool OVRInput::Get(int Button, int Controller) {
    Class inputClass = Class("", "OVRInput", Image("Oculus.VR.dll"));
    Method<bool> method = inputClass.GetMethod("Get", 2);
    return method.Call(Button);
}