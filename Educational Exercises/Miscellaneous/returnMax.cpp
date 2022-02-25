/**************************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Exercise 7:
 * Date due stringhe in input (utente) stampa la più lunga
 *************************************************************************************/

//Lib
#include <iostream>
#include <string>

//Main
int main(){
    //Object decl.
    std::string x, y;
    //User input
    std::cout << "Insert first string: " << std::endl;
    std::getline(std::cin, x);
    
    std::cout << "Insert second string: " << std::endl;
    std::getline(std::cin, y);
    
    //Results
    if(x.length() == y.length() ) std::cout << "MAX LENGTH: " << std::endl << x << std::endl << y << std::endl; 
    else std::cout << "MAX LENGTH: " << (x.length() < y.length() ? y : x);
}