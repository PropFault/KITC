#pragma once
#include "../pump/pump.h"
#include <functional>

template <class T>
class InputProvider : Pump{
    virtual void setOnButtonPressedCallback(std::function<T&(Input&)> callback) = 0;
    virtual void setOnButtonReleasedCallback(std::function<T&(Input&)> callback) = 0;
};