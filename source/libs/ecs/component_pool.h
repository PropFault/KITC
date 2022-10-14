#pragma once
#include "../tracker/Tracker.h"
#include <cinttypes>
#include <functional>
#include <string>
class Component{
public:
    [[nodiscard]]
    virtual Component* clone()const = 0;
    virtual void reset() = 0;
    [[nodiscard]]
    virtual uint64_t getTypeId()const = 0;
};
template<class T, class A>
class InitWrapper{
private:
    A args;
    std::function<void(T&, const A&)> func;
public:
    InitWrapper(const std::function<void(T&, const A&)> func, const A& args)
    :args(args), func(func){}
    void init(T& target){
        this->func(target, this->A);
    }
};

template <class T>
class ComponentPool{
public:
    virtual uint64_t reserve(T&& source) = 0;
    virtual uint64_t reserve(std::function<void(T&)> init) = 0;
    virtual void free(uint64_t ticket) = 0;
    virtual void clean() = 0;
    virtual Tracker<T, uint64_t> checkout(uint64_t ticket) = 0;
};