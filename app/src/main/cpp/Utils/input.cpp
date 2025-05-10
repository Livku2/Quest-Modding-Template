#import "input.h"

using namespace BNM;
using namespace BNM::Structures;


bool XRInput::GetButton(ButtonType type, XRNode xrnode) {

    bool pressed = false;
    float triggerFloat = 0.0f;

    auto InputDevicesClass = Class("UnityEngine.XR", "InputDevices",
                                   Image("UnityEngine.XRModule.dll"));

    auto TryGetFeatureValue_bool = reinterpret_cast<bool(*)(BNM::Types::ulong, Mono::String*, bool*)>(GetExternMethod("UnityEngine.XR.InputDevices::TryGetFeatureValue_bool"));
    auto TryGetFeatureValue_float = reinterpret_cast<bool (*)(BNM::Types::ulong, Mono::String*, float*)>(GetExternMethod("UnityEngine.XR.InputDevices::TryGetFeatureValue_float"));
    Method<InputDevice> GetDeviceAtXRNode = InputDevicesClass.GetMethod("GetDeviceAtXRNode", 1);

    auto device = GetDeviceAtXRNode(xrnode);
    //BNM_LOG_INFO("Device ID: %llu (isLeft: %d)\n", device.deviceId, xrnode);  // Check the device ID and ensure the correct controller is returned

    switch (type) {
        case ButtonType::grip:
            TryGetFeatureValue_bool(device.m_DeviceId, CreateMonoString("GripButton"), &pressed);
            break;
        case ButtonType::trigger:
            TryGetFeatureValue_float(device.m_DeviceId, CreateMonoString("Trigger"), &triggerFloat);
            pressed = triggerFloat > 0.1f;
            break;
        case ButtonType::secondary:
            TryGetFeatureValue_bool(device.m_DeviceId, CreateMonoString("SecondaryButton"), &pressed);
            break;
        case ButtonType::primary:
            TryGetFeatureValue_bool(device.m_DeviceId, CreateMonoString("PrimaryButton"), &pressed);
            break;
        case ButtonType::stickPressed:
            TryGetFeatureValue_bool(device.m_DeviceId, CreateMonoString("Primary2DAxisClick"), &pressed);
            break;
    }

    return pressed;
}
