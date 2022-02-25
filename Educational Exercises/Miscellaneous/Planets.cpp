/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Exercise N°12:
 * Scrivere un codice che permetta di gestire i dati sul sistema solare.
 * Scrivere una struct "Pianeta" con i seguenti attributi:
 * - nome_pianeta
 * - massa
 * - distanza_sole
 * - periodo_orbita
 * - temperatura_media
 * Stampare a video un menu che dia la possibilità di:
 * - stampare una tabella contenente tutti i pianeti con le loro informazioni
 * - visualizzare solo i pianeti che hanno una certa massa maggiore, passata in->
 * ...input
 * - Dati due pianeti in input stampare solo quello a massa maggiore
 * - Ordinare i pianeti per temperatura media
***********************************************************************************/

//Lib
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

//Macro
#define N_PLANETS 8 //Total planets


//Functions

//Classes and struct
class Planets{
    public:
    //Public class variables
    std::string Planet_name;
    double mass;
    double sun_distance;
    double orbital_period;
    double average_temp;
    //Constructor
    Planets(){}; //Standard constructor
    Planets(std::string Planet_name, double mass, double sun_distance, double orbital_period, double average_temp){ //Custom constructor
        this->Planet_name = Planet_name;
        this->mass = mass;
        this->sun_distance = sun_distance;
        this->orbital_period = orbital_period;
        this->average_temp = average_temp;
    }

    static void printTable(Planets * planet, int N_Planet){
        std::cout << "|**********  [PLANETS TABLE]  **********|" << std::endl;
        std::cout << "|Planet Name|\t\t\t|Planet mass|\t\t\t|Sun Distance|\t\t\t|Orbital Period|\t|Temperature °C:|" << std::endl;
        for(int i = 0; i < N_Planet; i++){
            std::cout << planet[i].Planet_name << "\t\t\t\t";
            std::cout << planet[i].mass << "\t\t\t";
            std::cout << planet[i].sun_distance << "\t\t\t";
            std::cout << planet[i].orbital_period << "\t\t\t";
            std::cout << planet[i].average_temp << std::endl;
        }
        
    }

    static Planets returnMaxMass(Planets * planets, int N_Planet){
        //User input
        std::string name1, name2; //Local variables
        std::cout << "Insert first planet name:" << std::endl;
        std::cin >> name1;
        std::cout << "Insert second planet name:" << std::endl;
        std::cin >> name2;

        //Cycle check
        bool found1 = false, found2 = false;
        int pos1, pos2;
        for(int i = 0; i < N_Planet; i++){
            if(std::strcmp(planets[i].Planet_name.c_str(), name1.c_str()) == 0){ found1 = true; pos1 = i;};
            if(std::strcmp(planets[i].Planet_name.c_str(), name2.c_str()) == 0){ found2 = true; pos2 = i;};
        }
        //If found planets
        if(found1 == true && found2 == true){
            if(planets[pos1].mass > planets[pos2].mass) return planets[pos1];
            else return planets[pos2];
        }else{
            std::cout << "Planets not found!" << std::endl;
        }
        return Planets("Error", 0, 0, 0, 0);
    }
    
    static Planets * SortbyTemp(Planets * planet, int N_Planet){
        Planets * SortPlanets = new Planets[N_Planet];
        Planets tmp;
        //Clone
        for(int i = 0; i < N_Planet; i++)
            SortPlanets[i] = planet[i];
        //Sorting
        for(int i = 0; i < N_Planet; i++){
            for(int j = 0; j < N_Planet-1; j++)
                if(SortPlanets[i].average_temp < SortPlanets[j].average_temp){ //Swap
                    tmp = SortPlanets[i];
                    SortPlanets[i] = SortPlanets[j];
                    SortPlanets[j] = tmp; 
                }
        }
        return SortPlanets;
    }

    static Planets * printTableMinMass(Planets * planet, int N_Planet, double minMass){
        int newPlanet = 0;
        
        //Clone planets
        for(int i = 0; i < N_Planet; i++)
            if(planet[i].mass > minMass) newPlanet++;
        if(newPlanet > 0){
            Planets * result_planet = new Planets[newPlanet];
            for(int i = 0, j = 0; i < N_Planet; i++)
                if(planet[i].mass > minMass){ result_planet[j] = planet[i]; j++;} //Verify
            printTable(result_planet, newPlanet);
            return result_planet;
        }else std::cout << "Planets unavailable!" << std::endl;
        return new Planets("Error", 0, 0, 0, 0);
    }
};

//Main
int main(){
    //Array Decl.
    Planets * p_Array = new Planets[N_PLANETS]{
        {"Mercurio", 3.33*pow(10, 23), 57909175, 0.2408467, 166.85}, //1
        {"Venere", 4.8690*pow(10, 24), 108208930, 0.2408467, 463.85}, //2
        {"Terra", 5.97219*pow(10, 24), 149598262, 1.0000174, ((14.85+19.85)/2)}, //3
        {"Marte", 6.4191*pow(10, 23), 227936640, 1.8808476, ((-87.15+(-5.15))/2)}, //4
        {"Giove", 1.8987*pow(10, 27), 778412010, 11.862615, -121.15}, //5
        {"Saturno", 5.6851*pow(10, 26), 1426725400, 29.447498, -130.15}, //6
        {"Urano", 8.6849*pow(10, 25), 2870972200, 84.016846, -205.15}, //7
        {"Nettuno", 1.0244*pow(10, 26), 4498252900, 164.79132, -220.15}  //8
        };
    //Program introduction
    std::cout << "|*******[PLANET DATA SIMULATOR]*******|" << std::endl;
    //Menu
    char choice;
    //Mem variable
    double usr_in; int power;
    Planets usr_tmp;

    do{
        //menu choice
        std::cout << "*****[SELECTION MENU]*****" << std::endl;
        std::cout << "\'t\' to print all planets info" << std::endl;
        std::cout << "\'m\' to print only planets with min Mass (user in) " << std::endl;
        std::cout << "\'c\' to compare Mass between two planets" << std::endl;
        std::cout << "\'s\' to sort planets by temperature" << std::endl;
        std::cout << "\'e\' to exit" << std::endl;
        choice = getchar(); //User input
        
        switch(choice){
            case 't': Planets::printTable(p_Array, N_PLANETS);
            break;
            case 'm':
                std::cout << "Insert limit: (number)" << std::endl;
                std::cin >> usr_in;
                std::cout << "Insert limit: (power)" << std::endl;
                std::cin >> power;

                Planets::printTableMinMass(p_Array, N_PLANETS, (usr_in*pow(10, power)));
            break;
            case 'c':
                usr_tmp = Planets::returnMaxMass(p_Array, N_PLANETS);
                Planets::printTable(&usr_tmp, 1);
                
            break;
            case 's':
                Planets::printTable(Planets::SortbyTemp(p_Array, N_PLANETS), N_PLANETS);
            break;
            case 'e': break; //do nothing --> exit
            default: std::cout << "Input error!"; system("pause");
        }
        system("pause"); //Wait
        getchar(); //Get enter
        system("cls"); //Clear screen

    }while(choice != 'e'); //Exit condition
}