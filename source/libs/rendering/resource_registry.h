#pragma once
#include "../loading/image_loader.h"
#include <cinttypes>
class ResourceRegistry{
public:
    virtual uint64_t registerTexture(const ImageRaw& image)=0;
};