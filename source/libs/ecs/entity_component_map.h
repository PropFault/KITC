#pragma once
#include <cinttypes>
#include <unordered_set>
#include <vector>

class EntityComponentMap{
public:
    virtual void addComponent(uint64_t entity, uint64_t component_type_id, uint64_t component) = 0;
    virtual uint64_t getComponent(uint64_t entity, uint64_t componentTypeId)const = 0;
    virtual std::unordered_set<uint64_t> getComponents(uint64_t entity, uint64_t componentTypeId)const = 0;
    virtual std::vector<std::pair<uint64_t, uint64_t>> getAllComponents(uint64_t componentTypeId)const = 0;
    virtual void removeComponent(uint64_t type, uint64_t entity, uint64_t components) = 0;
};