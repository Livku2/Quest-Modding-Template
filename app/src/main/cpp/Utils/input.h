#pragma once

#include "../BNM-Android/include/BNM/Loading.hpp"
#include "../BNM-Android/include/BNM/UserSettings/GlobalSettings.hpp"
#include "../BNM-Android/include/BNM/Class.hpp"
#include "../BNM-Android/include/BNM/Field.hpp"
#include "../BNM-Android/include/BNM/Method.hpp"
#include "../BNM-Android/include/BNM/Property.hpp"
#include "../BNM-Android/include/BNM/Defaults.hpp"
#include "../BNM-Android/include/BNM/Operators.hpp"
#include "../BNM-Android/include/BNM/BasicMonoStructures.hpp"

struct InputDevice{
    BNM::Types::ulong m_DeviceId;
    BNM::Types::ulong deviceId;
};
enum XRNode{
    LeftEye,
    RightEye,
    CenterEye,
    Head,
    LeftHand,
    RightHand,
    GameController,
    TrackingReference,
    HardwareTracker
};

enum ButtonType{
    grip,
    trigger,
    primary,
    secondary,
    stickPressed
};

namespace XRInput{
    bool GetButton(ButtonType type, XRNode xrnode);
}
