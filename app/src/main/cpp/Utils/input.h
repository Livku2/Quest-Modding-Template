#include "../BNM-Android/include/BNM/Loading.hpp"
#include "../BNM-Android/include/BNM/UserSettings/GlobalSettings.hpp"
#include "../BNM-Android/include/BNM/Class.hpp"
#include "../BNM-Android/include/BNM/Field.hpp"
#include "../BNM-Android/include/BNM/Method.hpp"
#include "../BNM-Android/include/BNM/Property.hpp"
#include "../BNM-Android/include/BNM/Defaults.hpp"
#include "../BNM-Android/include/BNM/Operators.hpp"
#include "../BNM-Android/include/BNM/BasicMonoStructures.hpp"

namespace Button{
    int Secondary = 1;
    int Primary = 2;
}
namespace Controller{
    int Left = 1;
    int Right = 2;
}

namespace OVRInput{
    bool Get(int Button, int Controller);
}
