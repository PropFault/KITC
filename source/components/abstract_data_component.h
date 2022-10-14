//
// Created by biggest on 14/10/22.
//

#ifndef KITC_ABSTRACT_DATA_COMPONENT_H
#define KITC_ABSTRACT_DATA_COMPONENT_H

#include "../libs/ecs/component_pool.h"
template<class T>
class AbstractDataComponent: public Component{
private:
    T data;
    uint64_t typeId = 0;
public:

    void reset() override {
        this->data = std::move(T());
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }
};
#define DEFINE_DATA_COMPONENT(name, type, type_id) \
class name : public AbstractDataComponent< type >{  \
public:                                            \
    explicit name() = default;                     \
    name(const name& other) = default;    \
    name(name&& other) = default;                  \
    explicit name(const type& data){               \
        this->setData(data);                                               \
    }\
    static const uint64_t TYPE_ID = type_id;       \
    [[nodiscard]]                                   \
    Component *clone() const override {             \
        return new name(*this);        \
    }                                               \
    [[nodiscard]]                                   \
    uint64_t getTypeId() const override {           \
        return TYPE_ID;                             \
    }                                               \
};
#endif //KITC_ABSTRACT_DATA_COMPONENT_H
