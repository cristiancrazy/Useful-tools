/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°3:
 *  Scrivere un programma in C++ che acquisisca una serie di numeri da tastiera
 *  e poi stampi il maggiore
 *********************************************************************************/

//Lib
#include <iostream>

//Macro
#define MAX(num1, num2) num1 < num2 ? num2 : num1; //return the max number

//Main
int main(){
    //Variables
    int last, now;
    bool firstTime = true;
    while(true){
        std::cout << "Insert number: ";
        std::cin >> now;
        if(firstTime){ last = now; firstTime = !firstTime; }
        if(now == 0) break; //until 0
        last = MAX(last, now); //Calc
    }

    //Print results
    std::cout << "Max = " << last;
}