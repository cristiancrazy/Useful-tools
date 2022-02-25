/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°5:
 * Visualizzare frase inserita. Costruire una nuova frase con le regole
 * prestabilite --> memorizzata in una variabile. Visualizzare la nuova frase
 *********************************************************************************/

//Lib
#include <iostream>
#include <cstring>

//Macro
#define N 100 //Max count / Array Dim

//Main
int main(){
    char * phrase = new char[N];
    std::cout << "Insert phrase: " << std::endl;
    fgets(phrase, N, stdin); //Get input from stdin (terminal)

    //Task 1: print
    std::cout << "Phrase: " << phrase << std::endl;
    
    //Task 2: clone and operations
    char * phrase_clone = new char[N];
    for(int i = 0; i < strlen(phrase); i++){
        /*Verify first letter and white space character*/
        if(i == 0 || isblank(phrase[i-1])){ phrase_clone[i] = toupper(phrase[i]);} 
        else phrase_clone[i] = tolower(phrase[i]);
    }
    std::cout << "Phrase 2: " << phrase_clone << std::endl;
}