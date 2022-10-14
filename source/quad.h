#pragma once

template<class T>
class Quad{
private:
    T x;
    T y;
    T w;
    T h;
public:
    Quad() = default;
    Quad(T x, T y, T w, T h) : x(x), y(y), w(w), h(h) {}

    T getX() const {
        return x;
    }

    void setX(T x) {
        Quad::x = x;
    }

    T getY() const {
        return y;
    }

    void setY(T y) {
        Quad::y = y;
    }

    T getW() const {
        return w;
    }

    void setW(T w) {
        Quad::w = w;
    }

    T getH() const {
        return h;
    }

    void setH(T h) {
        Quad::h = h;
    }

    void setDimens(T w, T h){
        this->setW(w);
        this->setH(h);
    }

    void setPos(T x, T y){
        this->setX(x);
        this->setY(y);
    }
};
