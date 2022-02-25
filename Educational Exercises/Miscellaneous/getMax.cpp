/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°2:
 *  Scrivere un programma in C++ che acquisisca N = 10 numeri da tastiera e stampi
 *  il maggiore
 *********************************************************************************/

//Lib
#include <iostream>

//Macro
#define N 10 //Max numbers
#define MAX(num1, num2) num1 < num2 ? num2 : num1; //return the max number

//Functions

//Main
int main(){
    //Variables
    int last, now;

    for(int i = 1; i <= N; i++){
        std::cout << "Insert number: ";
        std::cin >> now;
        if(i == 1) last = now;
        last = MAX(last, now); //Calc
    }

    //Print results
    std::cout << "Max = " << last;
}