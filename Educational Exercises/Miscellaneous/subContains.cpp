/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°4:
 * Scrivere un programma che riceva in ingresso due parole inserite da tastiera
 * Si consideri che ciascuna parola può contenere al massimo N caratteri.
 * Il programma deve verificare se la seconda parola inserita è contenuta almeno
 * una volta  all'interno della prima parola
 *********************************************************************************/

//Lib
#include <iostream>
#include <cstring>

//Macro
#define N 100 //Max char array length
#define DEBUG //Used to debug code
//Functions
bool verifySub(char * str1, char * str2){
    int trycounter = 0;

    //Debug
    #ifdef DEBUG 
        std::cout << "Dim1: "<< strlen(str1) << " Dim2: " << strlen(str2) << std::endl; 
    #endif

    for(int i = 0; i < strlen(str2); i++){
        if(str2[i] == str1[trycounter]) trycounter++;
        else trycounter = 0;
        if(-1+strlen(str1) == trycounter) return true;
    }
    
    return false;
}

//Main
int main(){
    //Array declarations
    char * string1 = new char[N]; //Substring
    char * string2 = new char[N]; //full string
    //User input
    std::cout << "Insert string 1: (to find)" << std::endl;
    fgets(string1, N, stdin);
    std::cout << "Insert string 2: (Complete)" << std::endl;
    fgets(string2, N, stdin);
    
    //Debug
    #ifdef DEBUG
    std::cout << strlen(string1) << string1 << std::endl;
    std::cout << strlen(string2) << string2 << std::endl;
    #endif

    std::cout << (verifySub(string1, string2) ? "Substring OK" : "Substring KO") << std::endl;

}