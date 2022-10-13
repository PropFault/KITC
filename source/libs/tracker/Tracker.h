#pragma once
#include <functional>

template <class T, class A>
class Tracker{
private:
    std::function<void(A)> callback;
    T* data; // UNSAFE?
    A identifier;
public:
    Tracker(std::function<void(A)> callback, T* data, A identifier)
            :callback(callback), data(data), identifier(std::move(identifier)){}
    ~Tracker(){
        callback(this->identifier);
    }

    T *getData() const {
        return data;
    }

    A getIdentifier() const {
        return identifier;
    }
};
