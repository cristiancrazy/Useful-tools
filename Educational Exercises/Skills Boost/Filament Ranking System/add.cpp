/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * Adding filament action file
 *****************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "filament.cpp"

void addFilament(std::fstream &fileIn){
    struct filament_handler::filament newFilament;
    //Input
    std::string line;
    std::cout << "[FRS - Aggiunta Filamento]" << std::endl;
    
    std::cout << "Produttore: ";
    std::getline(std::cin, newFilament.Producer);
    if(newFilament.Producer.empty()) throw std::runtime_error("Il campo \"Produttore\" non deve essere vuoto.");
   
    std::cout << "Selezionare la tipologia di filamento" << std::endl << "[1] -> PLA" << std::endl << "[2] -> PET" << std::endl << "[3] -> PETG" << std::endl << "[4] -> ABS" << std::endl << ": ";
    std::getline(std::cin, line);
    switch(atoi(line.c_str())){
        case 1:
            newFilament.Type = filament_handler::_Type[0];
            break;
        case 2:
            newFilament.Type = filament_handler::_Type[1];
            break;
        case 3:
            newFilament.Type = filament_handler::_Type[2];
            break;
        case 4:
            newFilament.Type = filament_handler::_Type[3];
            break;
        default:
            throw std::runtime_error("Tipologia filamento non valida.");
    };

    std::cout << "Inserire il colore: ";
    std::getline(std::cin, newFilament.Color);
    if(newFilament.Color.empty()) throw std::runtime_error("Il campo \"Colore\" non deve essere vuoto.");

    std::cout << "Inserire il peso (kg): ";
    std::getline(std::cin, line);
    newFilament.Weight = atof(line.c_str());
    if(newFilament.Weight <= 0.0) throw std::runtime_error("Il campo \"Peso\" non deve essere zero.");

    std::cout << "Inserire il costo (EUR): ";
    std::getline(std::cin, line);
    newFilament.Price = atof(line.c_str());
    if(newFilament.Price <= 0.0) throw std::runtime_error("Il campo \"Costo\" non deve essere zero.");

    std::cout << "Link al prodotto: ";
    std::getline(std::cin, newFilament.StoreLink);
    if(newFilament.StoreLink.empty()) newFilament.StoreLink = "Non definito";

    fileIn << newFilament.Producer << "," << newFilament.Type << "," << newFilament.Color << "," << newFilament.Weight << "," << newFilament.Price << "," << newFilament.StoreLink << "\n";

    std::cout << "Nuovo filamento aggiunto al sistema. Inserirne un altro? Y/N: ";
    std::getline(std::cin, line);
    if( (line.c_str()[0] == 'Y') || (line.c_str()[0] == 'y') ) addFilament(fileIn);
    else std::cout << "Bye";
}