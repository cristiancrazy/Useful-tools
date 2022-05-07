/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * Filter print action - implementation
 *****************************************/

#include <iostream>
#include <fstream>
#include "filament.cpp"
#include "print.cpp"

void printFiltereByMaxPrice(std::fstream& fileIn, double MaxPrice){
    bool atLeastOne = false;
    for(struct filament_handler::filament filament : deserialize(fileIn)){
        if(filament.Price < MaxPrice){
            atLeastOne = true;
            static bool turned = true;
            if(turned){ //Print header
                turned = false;
                printf("Produttore\t\tTipologia\t\tColore\t\tPeso[KG]\tCosto\t\tLink Amazon\n");
            }
            
            printf("%s\t\t%s\t\t\t%s\t\t%3.1lf\t\t%3.2lf\t\t%s\n", filament.Producer.c_str(), filament.Type.c_str(), filament.Color.c_str(), filament.Weight, filament.Price, filament.StoreLink.c_str());

        }
    }

    if(!atLeastOne) std::cout << "No matches found." << std::endl;
    std::cout << "Bye";
};

void printFilteredByColor(std::fstream& fileIn, std::string Color){
    bool atLeastOne = false;
    for(struct filament_handler::filament filament : deserialize(fileIn)){
        if(filament.Color == Color){
            atLeastOne = true;
            static bool turned = true;
            if(turned){ //Print header
                turned = false;
                printf("Produttore\t\tTipologia\t\tColore\t\tPeso[KG]\tCosto\t\tLink Amazon\n");
            }
            
            printf("%s\t\t%s\t\t\t%s\t\t%3.1lf\t\t%3.2lf\t\t%s\n", filament.Producer.c_str(), filament.Type.c_str(), filament.Color.c_str(), filament.Weight, filament.Price, filament.StoreLink.c_str());

        }
    }

    if(!atLeastOne) std::cout << "No matches found." << std::endl;
    std::cout << "Bye";
};

void printFilteredByType(std::fstream& fileIn, std::string Type){
    bool atLeastOne = false;
    for(struct filament_handler::filament filament : deserialize(fileIn)){
        if(filament.Type == Type){
            atLeastOne = true;
            static bool turned = true;
            if(turned){ //Print header
                turned = false;
                printf("Produttore\t\tTipologia\t\tColore\t\tPeso[KG]\tCosto\t\tLink Amazon\n");
            }
            
            printf("%s\t\t%s\t\t\t%s\t\t%3.1lf\t\t%3.2lf\t\t%s\n", filament.Producer.c_str(), filament.Type.c_str(), filament.Color.c_str(), filament.Weight, filament.Price, filament.StoreLink.c_str());

        }
    }

    if(!atLeastOne) std::cout << "No matches found." << std::endl;
    std::cout << "Bye";
};
