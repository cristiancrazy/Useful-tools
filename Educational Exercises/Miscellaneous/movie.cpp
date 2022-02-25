/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Exercise N°10:
 * Creare attraverso typedef un nuovo tipo di dato strutturato "film" con i
 * seguenti attributi:
 * - Titolo -> una stringa di 30 caratteri
 * - Regista -> una stringa di 30 caratteri (Cognome)
 * - Durata -> intero
 * - Quantita -> intero (copie disponibili)
 * 
 * Istanziare array, il programma dovrà stampare un menù da cui sarà possibile
 * scegliere se:
 * - Cercare il film per regista (dato il regista stampare tutti i suoi film)
 * - Verificare la disponibilità di un titolo (dato un tiolo verificare se disp.)
 * - Visualizzare tutti i film con durata inferiore a 120 min
 *********************************************************************************/

//Lib
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

//Macro
#define N_ENTRY 5 //Numbers of entries
#define S_LIMIT 30 //String size limit
#define RANDOMQ(minLimit, maxLimit) minLimit+std::rand() % (1+maxLimit-minLimit); //Random "rule"

#define MINS 120 //minutes check limit 
//#define DEBUG //Only for DEBUG

//Structured Data
typedef struct movie{
    const char * title = new char[S_LIMIT];
    const char * director = new char[S_LIMIT];
    unsigned int duration;
    unsigned int quantity;
}movie_t;

//Functions

    //Search Film with director surname
    void searchDir(movie_t * mov, int num_entry){
        std::string tmp; bool found = false;
        std::cout << "Please, insert director surname: " << std::endl;
        std::getline(std::cin, tmp); //User input
        for(int i = 0; i < num_entry; i++) //Searching
            if(strcmp(tmp.c_str(), mov[i].director) == 0){ std::cout << "Title: " << mov[i].title << std::endl; found = true;};
        if(!found) std::cout << "Not Found!" << std::endl; //Surname not found
        }
    //Verify availability
    void isAvailable(movie_t * mov, int num_entry){
        std::string tmp; bool found = false; bool available = NULL;
        std::cout << "Please, insert movie title: " << std::endl;
        std::getline(std::cin, tmp); //User input
        for(int i = 0; i < num_entry; i++) //Search
        {
            if(strcmp(tmp.c_str(), mov[i].title)){
                mov[i].quantity > 0 ? available = true : available = false; //Verify if available
                found = true;
            };
        }
        
        if(!found) std::cout << "Not Found!" << std::endl; //Title not found
        else{ //If title found
            if(available) std::cout << tmp << " is available! " << std::endl;
            else std::cout << tmp << " isn't available! " << std::endl;
        }
    }
    //"Minutes check film" 
    void mincheck(movie_t * mov, int num_entry, int min_limit){
        for(int i = 0; i < num_entry; i++)
            if(mov[i].duration < min_limit) std::cout << mov[i].title << ", duration: " << mov[i].duration << std::endl;
    }
//Main
int main(){
    //Init seed
        std::srand(std::time(NULL));
    //Array Inst.
        movie_t * movieArray = new movie_t[N_ENTRY];
    /* Setting data */
    //Titles
        movieArray[0].title = "Inland Empire";
        movieArray[1].title = "Un sogno chiamato Florida";
        movieArray[2].title = "La Favorita";
        movieArray[3].title = "Midnight in Paris";
        movieArray[4].title = "The Lobster";
    //Directors
        movieArray[0].director = "Lynch";
        movieArray[1].director = "Baker";
        movieArray[2].director = "Lanthimos";
        movieArray[3].director = "Allen";
        movieArray[4].director = "Lanthimos";
    //Duration
        movieArray[0].duration = 180;
        movieArray[1].duration = 115;
        movieArray[2].duration = 122;
        movieArray[3].duration = 94;
        movieArray[4].duration = 118;
    //Quantity
        for(int i = 0; i < N_ENTRY; i++){
            movieArray[i].quantity = RANDOMQ(0, 100);
            
            #ifdef DEBUG
                std::cout << "Q: " << movieArray[i].quantity << std::endl;
            #endif
        }
    //Selection
    char choice;
    do{
        std::cout << "|*****************SELECTION MENU**********************|" << std::endl;
        std::cout << "Press \"s\" Search Film with director surname" << std::endl;
        std::cout << "Press \"v\" to Verify availability" << std::endl;
        std::cout << "Press \"p\" to Print all movie under  " << MINS << " minutes" << std::endl;
        std::cout << "Press \"e\" to exit " << std::endl;
        std::cout << "Waiting user input..." << std::endl;
        choice = std::getchar();
        std::getchar(); // (Return)
        switch(choice){
            case 's': //Search Film with director surname
                searchDir(movieArray, N_ENTRY);
                system("pause");
            break;
            case 'v': //Verify availability
                isAvailable(movieArray, N_ENTRY);
                system("pause");
            break;
            case 'p': //"Minutes check film" 
                mincheck(movieArray, N_ENTRY, MINS);
                system("pause");
            break;
            case 'e': //do nothing - exit
            break;
            default:
                std::cout << "[Command not valid!]" << std::endl; 
        }
        system("cls");
    }while(choice != 'e'); //Exit condition
}