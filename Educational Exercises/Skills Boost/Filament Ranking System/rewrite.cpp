/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * File re-writing with weight action
 *****************************************/

#include <iostream>
#include <fstream>
#include "print.cpp"
#include "filament.cpp"

void rewriteSortedByWeight(std::string pathIn, std::fstream& fileIn){
    std::vector<struct filament_handler::filament> sortedData = deserializeByWeight(fileIn);
    fileIn.close(); //Close file input

    //Output to file
    std::fstream fileOut(pathIn, std::ios_base::out);
    if(!fileOut.is_open()) throw std::runtime_error("IO File Error.");

    for(struct filament_handler::filament newFilament : sortedData){
            fileOut << newFilament.Producer << "," << newFilament.Type << "," << newFilament.Color << "," << newFilament.Weight << "," << newFilament.Price << "," << newFilament.StoreLink << "\n";
    }
    fileOut.close();
    std::cout << "Bye.";

    //Re-open fileIn for other purposes
    fileIn = std::fstream(pathIn, std::ios_base::in | std::ios_base::app);

}