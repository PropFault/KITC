#pragma once
#include "entity_component_map.h"
#include <unordered_map>
#include <unordered_set>
#include <cinttypes>
#include <vector>

class EntityComponentHashMap : EntityComponentMap{
private:
    // um        um             set
    // type -> (entities -> [components])
    std::unordered_map<uint64_t, std::unordered_map<uint64_t, std::unordered_set<uint64_t>>> map;
public:
    EntityComponentHashMap() = default;

    void addComponent(uint64_t entity, uint64_t component_type_id, uint64_t component) override {
        // assure inner map exists
        try{
            this->map.at(component_type_id);
        }catch(const std::exception &e){
            this->map.emplace(component_type_id, std::unordered_map<uint64_t, std::unordered_set<uint64_t>>());
        }
        // assure set exists
        try{
            this->map.at(component_type_id).at(entity);
        }catch(const std::exception &e){
            this->map.at(component_type_id).emplace(entity, std::unordered_set<uint64_t>());
        }

        //perform insert
        this->map.at(component_type_id).at(entity).insert(component);
    }

    uint64_t getComponent(uint64_t entity, uint64_t componentTypeId) const override {
        return *this->getComponents(entity,componentTypeId).begin();
    }

    std::unordered_set<uint64_t> getComponents(uint64_t entity, uint64_t componentTypeId) const override {
        return this->map.at(componentTypeId).at(entity);
    }

    std::vector<std::pair<uint64_t, uint64_t>> getAllComponents(uint64_t componentTypeId) const override {
        std::vector<std::pair<uint64_t, uint64_t>> collected;
        for(auto& entry : this->map.at(componentTypeId))
            for(auto& comp : entry.second)
                collected.emplace_back(entry.first, comp);
        return collected;
    }

    void removeComponent(uint64_t type, uint64_t entity, uint64_t component) override {
        this->map.at(type).at(entity).erase(component);
    }
};