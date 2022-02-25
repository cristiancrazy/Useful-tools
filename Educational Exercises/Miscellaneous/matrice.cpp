/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°6:
 * Scrivere un programma che dichiari una matrice N*N, ne inizializzi gli elementi
 * con numeri casuali interi compresi tra 1 e 100 e ne esegua la visualizzazione.
 * Calcolare la media sualla diagonale
 *********************************************************************************/

//Lib
#include <iostream>
#include <ctime>

//Macro
#define N 5 //Dimension max

//Class
class matObj{
    private:
    unsigned int mat[N][N];

    public:
    //constructor
    matObj(){
        std::srand(std::time(NULL));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                mat[i][j] = (1+std::rand() % 99);
        }
    }
    //Print all matrix
    void printAll(){
        std::cout << "| VISUAL |" << std::endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                std::cout << "[" << mat[i][j] << "] ";
            std::cout << std::endl;
        }
    }
    //Diagonal mean
    int diagMean(){
        int mean = 0; 
        for(int i = 0; i < N; i++)
            mean += mat[i][i];
        return (mean/N);
    }

};

//Main
int main(){
    matObj * x = new matObj;
    x->printAll();
    std::cout << "Diagonal Mean: " << x->diagMean() << std::endl;
}