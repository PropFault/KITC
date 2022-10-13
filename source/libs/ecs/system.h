#pragma once
#include <inttypes.h>
#include "../pump/pump.h"
#include <utility>
#include <vector>
#include <memory>
class System{
public:
    virtual void think(uint64_t entity, uint64_t component, double delta) = 0;
    virtual uint64_t getHandeledType()const = 0;
};

class SystemPump : Pump{
private:
    std::vector<std::shared_ptr<System>> systems;
    EntityComponentMap &entityComponentMap;
    clock_t lastClock;
public:
    SystemPump(std::vector<std::shared_ptr<System>> systems, EntityComponentMap &entityComponentMap) : systems(std::move(
            systems)), entityComponentMap(entityComponentMap),
            lastClock(clock()){}

    void pump() override {
        clock_t newLastClock = clock();
        for(auto& system : this->systems){
            auto comps = this->entityComponentMap.getAllComponents(system->getHandeledType());
            for(auto& comp : comps){
                system->think(comp.first, comp.second, ((clock() - lastClock) / CLOCKS_PER_SEC));
            }
        }
        lastClock = newLastClock;
    }

    void push(const std::shared_ptr<System>& ptr){
        this->systems.push_back(ptr);
    }
};