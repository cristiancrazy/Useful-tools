/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * Filament implementation structure
 *****************************************/
#pragma once
#include <iostream>
#include <string>

namespace filament_handler{
    std::string* _Type = new std::string[4]{
        "PLA", "PET", "PETG", "ABS"
    };

    struct filament{
        std::string Producer;
        std::string Type;
        std::string Color;
        double Weight;
        double Price;
        std::string StoreLink;
    };
}