//
// Created by biggest on 14/10/22.
//

#ifndef KITC_QUAD_COMPONENT_H
#define KITC_QUAD_COMPONENT_H
#include "abstract_data_component.h"
#include "../quad.h"
#include <cinttypes>

class RenderQuad : public Quad<float>{
private:
    uint64_t material;
public:
    RenderQuad() : Quad(0,0,0,0){
        this->material = 0;
    }
    RenderQuad(float x, float y, float w, float h, uint64_t material) : Quad(x, y, w, h), material(material) {}

    uint64_t getMaterial() const {
        return material;
    }

    void setMaterial(uint64_t material) {
        RenderQuad::material = material;
    }
};

DEFINE_DATA_COMPONENT(QuadComponent, RenderQuad, 12309325616165)
#endif //KITC_QUAD_COMPONENT_H
