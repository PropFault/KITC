//
// Created by biggest on 11/10/22.
//

#ifndef KITC_RANDOM_H
#define KITC_RANDOM_H

#include <cinttypes>
#include <random>

class Random{
private:
    std::random_device rd;
public:
    uint64_t u64(){
        return std::mt19937_64(rd())();
    }
};

#endif //KITC_RANDOM_H
