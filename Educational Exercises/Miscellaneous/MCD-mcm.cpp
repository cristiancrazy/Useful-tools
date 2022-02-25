/**************************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Exercise 1:
 * Scrivere un programma per trovare mcm e MCD tra due numeri inseriti da tastiera
 *************************************************************************************/


//Lib
#include <iostream>

//Class
class xyMath{
    private:
    //Instance variables
    int x, y; 
    
    public:
    //Costructor
    xyMath(int x, int y){
        this->x = x;
        this->y = y;
    }

    //Class Functions
    int getMCD(){
        int tmpx = this->x, tmpy = this->y, tmp;
        while(tmpy != 0){
            tmp = tmpy;
            tmpy = tmpx % tmpy;
            tmpx = tmp;
        }
        return tmpx;
    }
    
    int getMcm(){
        return (x*y)/getMCD();
    }

};


//Main
int main(){
    //Variables for saving user inputs
    int mainx, mainy;
    
    //User input
    std::cout << "Insert number 1: " << std::endl;
    std::cin >> mainx;
    std::cout << "Inserire number 2: " << std::endl;
    std::cin >> mainy;
    
    //Instance object
    xyMath * calc = new xyMath(mainx, mainy);
    
    //Print results
    std::cout << "|RESULTS:|" << std::endl << "MCD: " << calc->getMCD() // -->
        << std::endl << "mcm: " << calc->getMcm() << std::endl;
}