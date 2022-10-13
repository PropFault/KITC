//
// Created by biggest on 12/10/22.
//

#ifndef KITC_DATA_COMPONENT_H
#define KITC_DATA_COMPONENT_H
#include "../libs/ecs/component_pool.h"

template<class T>
class DataComponent: public Component{
private:
    T data;
    uint64_t typeId = 0;
public:
    [[nodiscard]]
    Component *clone() const override {
        return new DataComponent(*this);
    }

    void reset() override {
        this->data = std::move(T());
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        DataComponent::data = data;
    }

    void setTypeId(uint64_t typeId) {
        DataComponent::typeId = typeId;
    }

    [[nodiscard]]
    uint64_t getTypeId() const override {
        return typeId;
    }
};
#endif //KITC_DATA_COMPONENT_H
