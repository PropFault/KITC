//
// Created by biggest on 11/10/22.
//

#ifndef KITC_COMPONENT_POOL_HASH_MAP_H
#define KITC_COMPONENT_POOL_HASH_MAP_H
#include "component_pool.h"
#include "../math/random.h"
template<class T>
class ComponentPoolHashMap : ComponentPool<T>{
private:
    std::unordered_map<uint64_t, T> data;
    std::unordered_map<T*, uint64_t> addr;
    Random random;
private:
    uint64_t allocate(){
        auto ticket = random.u64();
        data.emplace(ticket, std::move(T()));
        addr.emplace(&data.at(ticket), ticket);
        return ticket;
    }
public:

    void freeByData(const T &t){
        this->free(this->addr.at(&t));
    }
    uint64_t reserve(T&& source) override{
        auto ticket = allocate();
        data.at(ticket) = source;
        return ticket;
    }

    uint64_t reserve(std::function<void(T &)> init) override {
        auto ticket = allocate();
        init(data.at(ticket));
        return ticket;
    }

    void free(uint64_t ticket) override {
        addr.erase(&data.at(ticket));
        data.erase(ticket);
    }

    void clean() override {

    }

    Tracker<T, uint64_t> checkout(uint64_t ticket) override {
        return Tracker<T, uint64_t>(std::bind(&ComponentPoolHashMap<T>::free, this, std::placeholders::_1), &this->data.at(ticket), ticket);
    }
};
#endif //KITC_COMPONENT_POOL_HASH_MAP_H
