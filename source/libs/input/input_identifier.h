#pragma once
#include <string>
enum JoyButtonsCommon{
    JB_A = 0,
    JB_B = 1,
    JB_X = 2,
    JB_Y = 3,
    JB_DpUp = 4,
    JB_DpDown = 5,
    JB_DpLeft = 6,
    JB_DpRight = 7,
    JB_LS = 8,
    JB_RS = 9,
    JB_LT = 10,
    JB_RT = 11,
    JB_Start = 12,
    JB_Select = 13,
    JB_GripL = 14,
    JB_GripR = 15,
    JB_Share = 16,
    JB_Options = 17,
    JB_StickL = 18,
    JB_StickR = 19,
    JB_Special1 = 20,
    JB_Special2 = 21,
    JB_Special3 = 22
};

enum JoyAxisCommon{
    JA_L = 0,
    JA_R = 1,
    JA_LT = 2,
    JA_RT = 3
};

class InputIdentifier{
private:
    std::string data;
public:
    explicit InputIdentifier(const std::string &data) : data(data) {}

    static InputIdentifier Axis(const std::string& id){
        return InputIdentifier(id);
    }
    static InputIdentifier Joy(char axis, char joy){
        return InputIdentifier(std::string({axis, joy}));
    }
    static InputIdentifier Key(char key){
        return InputIdentifier(std::string({key}));
    }
    static InputIdentifier Button(char buttonNum){
        return InputIdentifier(std::string({buttonNum}));
    }
};