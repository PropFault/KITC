#pragma once
#include "resource.h"
template <class T>
class Loader{
public:
    virtual T load(Resource&& resource) = 0;
};