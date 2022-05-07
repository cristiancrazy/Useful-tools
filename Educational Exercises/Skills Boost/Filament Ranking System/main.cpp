/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 *****************************************/

//Header & Macros
#include <iostream>
#include <fstream>
#include <string>
#include "filament.h"
#include "filament.cpp" //Filament type and utilities

//Functions

void parseParams(int argc, char* argv[]){
    std::fstream fcheck;
    try{
        if(argc < 3) throw std::runtime_error("Invalid params.");

        //Checking second param - path
        std::string path;
        fcheck = std::fstream(path = std::string(argv[1]), std::ios::in | std::ios::app);
        if(!fcheck) throw std::runtime_error("IO File Error.");

        //Check third and fourth params - actions
        int actions = 7;
        std::string* definedActions = new std::string[actions] {
            "add", "show-all", "show-weight", "sort-weight", "show-type", "show-color", "show-max"
        };

        int action = -1;
        for(int i = 0; i < actions; ++i){
            if(std::string(argv[2]) == definedActions[i]){
                action = i;
                break;
            }
        }

        if(action == -1) throw std::runtime_error("Invalid action.");

        bool match = false; //Used later to verify filament validity
        switch(action){
            case 0: //Add
                addFilament(fcheck);
                break;
            case 1: //Print
                printAllFilament(fcheck);
                break;
            case 2: //Sort by Kgs
                printSortedByWeight(fcheck);
                break;
            case 3: //Sort by Kgs and rewrite file
                rewriteSortedByWeight(path, fcheck);
                break;
            case 4: //Filter by type
                if(argc != 4) throw std::runtime_error("Missing param.");

                //Check filament type validity
                for(int i = 0; i < 4; ++i){
                    if(std::string(argv[3]) == filament_handler::_Type[i]){
                        match = true;
                    }
                }

                if(!match) throw std::runtime_error("Invalid filament type. Available: ABS/PET/PETG/PLA");
                printFilteredByType(fcheck, std::string(argv[3]));
                break;

            case 5: //Filter by color
                if(argc != 4) throw std::runtime_error("Missing param.");
                printFilteredByColor(fcheck, std::string(argv[3]));
                break;

            case 6: //Filter with a cost limits
                if(argc != 4) throw std::runtime_error("Missing param.");
                if(atof(argv[3]) <= 0.0) throw std::runtime_error("Price param must be a value over 0.0");
                printFiltereByMaxPrice(fcheck, atof(argv[3]));
                break;
        }

    }catch(std::exception &exc){ //Errors handling
        std::cout << exc.what();
    }

    if(fcheck.is_open()) fcheck.close(); //Close file
};

int main(int argc, char* argv[]){
    parseParams(argc, argv);
    exit(EXIT_SUCCESS); //End routine
}