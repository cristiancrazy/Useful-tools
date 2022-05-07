/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * Print filament action file
 *****************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <sstream> //(String Stream)
#include <string>
#include <vector>
#include "filament.cpp"

std::vector<struct filament_handler::filament> deserialize(std::fstream& fileIn){
    fileIn.seekg(std::ios_base::beg); //Set at the begin of the file
    std::vector<struct filament_handler::filament> readedFilaments; //Store data
    struct filament_handler::filament filament;

    std::string line;
    std::stringstream lineStream;
    while(!fileIn.eof()){
        std::getline(fileIn, line);
        lineStream << line;
        for(int count = 0; std::getline(lineStream, line, ','); ++count){
            switch(count){
                case 0: //Producer
                    filament.Producer = line;
                    break;
                case 1:
                    filament.Type = line;
                    break;
                case 2:
                    filament.Color = line;
                    break;
                case 3:
                    filament.Weight = atof(line.c_str());
                    break;
                case 4:
                    filament.Price = atof(line.c_str());
                    break;
                case 5:
                    filament.StoreLink = line;
                    break;
            }
        }
        lineStream.clear();
        lineStream.flush();
        readedFilaments.push_back(filament);
    }

    readedFilaments.pop_back();

    return readedFilaments;
}

void printAllFilament(std::fstream& fileIn){
    printf("Produttore\t\tTipologia\t\tColore\t\tPeso[KG]\tCosto\t\tLink Amazon\n");
    for(struct filament_handler::filament filament : deserialize(fileIn)){
        printf("%s\t\t%s\t\t\t%s\t\t%3.1lf\t\t%3.2lf\t\t%s\n", filament.Producer.c_str(), filament.Type.c_str(), filament.Color.c_str(), filament.Weight, filament.Price, filament.StoreLink.c_str());
    }
    std::cout << "Bye." << std::endl; 
}

std::vector<struct filament_handler::filament> deserializeByWeight(std::fstream& fileIn){
    //Sort data
    std::vector<struct filament_handler::filament> allFilaments = deserialize(fileIn);
    
    //Bubble sort data
    struct filament_handler::filament swapTmp;
    for(int i = 0; i < allFilaments.size()-1; ++i){
        for(int j = 0; j < allFilaments.size()-1; ++j){
            if(allFilaments[j].Weight > allFilaments[j+1].Weight){ //Swap
                swapTmp = allFilaments[j];
                allFilaments[j] = allFilaments[j+1];
                allFilaments[j+1] = swapTmp;
            }
        };
    };
    
    return allFilaments; 
}

void printSortedByWeight(std::fstream& fileIn){

    printf("Produttore\t\tTipologia\t\tColore\t\tPeso[KG]\tCosto\t\tLink Amazon\n");
    for(struct filament_handler::filament filament : deserializeByWeight(fileIn)){
        printf("%s\t\t%s\t\t\t%s\t\t%3.1lf\t\t%3.2lf\t\t%s\n", filament.Producer.c_str(), filament.Type.c_str(), filament.Color.c_str(), filament.Weight, filament.Price, filament.StoreLink.c_str());
    }
    std::cout << "Bye." << std::endl; 
}