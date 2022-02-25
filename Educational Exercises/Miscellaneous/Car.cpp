/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°8:
 * Creare un nuovo tipo di dato strutturato che abbia come attributi:
 * - Targa
 * - Modello
 * - Anno immatricolazione
 * Inzializzare gli attributi
 * Stampare a video tutti gli attributi della variabile istanziata
 *********************************************************************************/

//Lib
#include <iostream>

//Structured data
struct Autovehicle{
    std::string Licence_Plate;
    std::string Model;
    unsigned int Registration_year;
};


//Functions
void printAutovehicle(Autovehicle vehicle){
    std::cout << "Licence Plate: " << vehicle.Licence_Plate << std::endl;
    std::cout << "Model: " << vehicle.Model << std::endl;
    std::cout << "Registration Year: " << vehicle.Registration_year<< std::endl;
}
//Main
int main(){
    Autovehicle vehicle;
    vehicle.Licence_Plate = "AY 768 RT";
    vehicle.Model = "Panda";
    vehicle.Registration_year = 2001;
    printAutovehicle(vehicle);
}