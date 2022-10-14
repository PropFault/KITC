#pragma once
#include "../libs/ecs/component_pool.h"
#include <cinttypes>
#include <vector>
#include "../libs/math/floating_point.h"
class SpriteMaterial : Component{
private:
    std::vector<uint64_t> frames;
    float fps = 0;
    double timer = 0;
public:
    [[nodiscard]]
    uint64_t getActiveTexture()const{
        auto totalFrames = (uint32_t) round((this->timer * this->fps));
        auto index = totalFrames % this->frames.size();
        return this->frames[index];
    }

    void update(double delta){
        this->timer += delta;
    }

    [[nodiscard]] Component *clone() const override {
        return new SpriteMaterial(*this);
    }

    void reset() override {
        this->frames.clear();
        this->timer = this->fps = 0;
    }

    [[nodiscard]] uint64_t getTypeId() const override {
        return 545156168432131861;
    }

    const std::vector<uint64_t> &getFrames() const {
        return frames;
    }

    void setFrames(const std::vector<uint64_t> &frames) {
        SpriteMaterial::frames = frames;
    }

    float getFps() const {
        return fps;
    }

    void setFps(float fps) {
        SpriteMaterial::fps = fps;
    }

    double getTimer() const {
        return timer;
    }

    void setTimer(double timer) {
        SpriteMaterial::timer = timer;
    }
};
