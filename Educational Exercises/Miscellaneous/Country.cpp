/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Esercizio N°9:
 * Creare un nuovo tipo di dato strutturato "Paese" che abbia come attributi:
 * - Nome: stringa di 20 caratteri che contiene il nome del paese
 * - Capitale: una stringa di 20 caratteri ceh contiene la capitale del paese
 * - Superficie: un intero che contiene la superficie del paese
 * - Popolazione: un intero che contiene il numero di abitanti
 * 
 * Scrivere un main in cui si istanzia un array di Paesi con le informazioni date.
 * Stampare a video la tabella
 * Stampare a video il paese con maggiore densità abitativa
 *********************************************************************************/

//Lib
#include <iostream>

//Macro

//Structured data
struct Country{
    const char * name = new char[20+1];
    const char * capital_City = new char[20+1];
    unsigned long surface, population;
};

//Functions
void printList(Country * countries, int entryNumber){
    //Header
    std::cout << "Name\t\t\t\tCapital City\t\t\t\tSurface\t\t\t\tPopulation" << std::endl;
    for(int i = 0; i < entryNumber; i++){
        std::cout << countries[i].name << "\t\t\t\t" << countries[i].capital_City << "\t\t\t" << countries[i].surface << "\t\t\t\t" << countries[i].population << std::endl;
    }
}

Country getMaximumDensityCountry(Country * countries, int entryNumber){
    long maximum_density; int indicator;
    for(int i = 0; i < entryNumber; i++){
        if(i == 0 || maximum_density <= countries[i].population/countries[i].surface){ 
            indicator = i; maximum_density = countries[i].population/countries[i].surface; //people / km^2
        }
    }
    return countries[indicator];
}
//Main functions
int main(){
    Country * countries = new Country[4];
    //Country Names
        countries[0].name = "Vietnam";
        countries[1].name = "Cile";
        countries[2].name = "Islanda";
        countries[3].name = "Mauritania";
    //Country Capital city
        countries[0].capital_City = "Hanoi";
        countries[1].capital_City = "Santiago del Cile";
        countries[2].capital_City = "Reykjavik";
        countries[3].capital_City = "Nouakchott";
    //Country Surface (km^2)
        countries[0].surface = 331689L;
        countries[1].surface = 755838L;
        countries[2].surface = 102819L;
        countries[3].surface = 1030700L;
    //Country Population
        countries[0].population = 97338582L;
        countries[1].population = 17910000L;
        countries[2].population = 366700L;
        countries[3].population = 3359185L;
    
    printList(countries, 4);
    Country maxdensity = getMaximumDensityCountry(countries, 4);
    std::cout << "Max Density Country (people/km2): " << maxdensity.name << std::endl << "Results: " << (maxdensity.population/maxdensity.surface);
}