#pragma once
#include "pump.h"
#include <vector>
class Pumper : Pump{ // Pumps pumps
private:
    std::vector<Pump> pumps; // Pumps to pump
public:
    void pump() override{
        for(auto& pump : pumps){
            pump.pump();
        }
    }
};
