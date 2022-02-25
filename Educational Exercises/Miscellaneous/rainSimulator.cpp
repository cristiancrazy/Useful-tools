/*********************************************************************************
 * Author: Cristian Capraro
 * Lang: C++ - CPP
 * School: I.T.I.S. G. Fauser - Novara      Class: 4CIN
 * Exercise N°11:
 * Scrivere un codice che permetta di registrare su di un array di struct i giorni
 * di pioggia del mese di Febbraio. Il dato strutturato dovrà avere i seguenti
 * attributi:
 * 1. data giorno_rile
 * 2. bool pioggia_rile (probabilità del 30%)
 * 3. double mm_pioggia
 * Stampare i dati sottoforma di tabella. Scrivere una funzione per stampare solo 
 * i giorni di pioggia.
 * Scrivere una funzione che ordini i giorni per mm di pioggia.
***********************************************************************************/

//Lib
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

//Macro
//#define DEBUG //Only for debug
#define RAIN_PROBABILITY 30 // Range 0 ~ 100
#define RANDOMQ(minLimit, maxLimit) minLimit+std::rand() % (1+maxLimit-minLimit) //Random "rule"
#define RANDOMQFL(maxLimit) (double)(maxLimit)*(1.*std::rand()/RAND_MAX);

//Class
class date{
    private:
    int day = 0, month = 0, year = 0; //Default values
    int returnThisMaxDayNumber(){
        return returnMaxDayNumber(month, year);
    }

    bool verifyDate(){ //Verify date
        if(day > 0 && day <= returnThisMaxDayNumber()) return true;
        else return false;
    }
    public:
    date(){}; //base constructor
    date(int day, int month, int year){ //Custom constructor
        this->day = day;
        this->month = month;
        this->year = year;
        if(!verifyDate()){
            this->day = 0;
            this->month = 0;
            this->year = 0;
            std::cout << "Invalid Date!";
        }
    }
    static int returnMaxDayNumber(int month, int year){
        bool isLeapYear = (year % 4 == 0)? true : false; //Check leap year (se bisestile)
        bool setOk = false;
        switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: //31d Months
            return 31;
        break;
        case 4: case 6: case 9: case 11: //30d Months
            return 30;
        break;
        case 2: //February 
            if(isLeapYear) //Leap yr check
                return 29;
            else return 28;
        break;
        default: return -1; //Error - invalid
        }
    }

    std::string toString(){
        std::string tmp;
        if(this->day < 10) tmp.append("0");
        tmp.append(std::to_string(this->day));
        tmp.append("/");
        if(this->month < 10) tmp.append("0");
        tmp.append(std::to_string(this->month));
        tmp.append("/");
        tmp.append(std::to_string(this->year));
        return tmp;
    }
};


//Structured data
typedef struct rain_data{
    date day_detected;
    bool rain_detected;
    double rain_mm;
}rain_t;

//Functions
void printMonthTable(rain_t * table, int month, int year){ //Print all days
    std::cout << "|**** [MONTH TABLE] ****|" << std::endl;
    std::cout << "[DATE]\t\t\t[WAS RAINING]\t\t\t[RAIN MM]" << std::endl;
    for(int i = 0; i < date::returnMaxDayNumber(month, year); i++){
        std::cout << table[i].day_detected.toString() << "\t\t" << (table[i].rain_detected ? "yes" : "no") << "\t\t\t\t" << table[i].rain_mm << std::endl;  
    }
}

void printMonthTableRainOnly(rain_t * table, int month, int year){ //Print all raining days
    std::cout << "|**** [ONLY RAIN MONTH TABLE] ****|" << std::endl;
    std::cout << "[DATE]\t\t\t[RAIN MM]" << std::endl;
    for(int i = 0; i < date::returnMaxDayNumber(month, year); i++){
        if(table[i].rain_detected) std::cout << table[i].day_detected.toString() << "\t\t" << table[i].rain_mm << std::endl;
    }
}

rain_t * sortbyMM(rain_t * table, int month, int year){ //Sort by mm
    rain_t * table_copy = new rain_t[date::returnMaxDayNumber(month, year)];
    for(int i = 0; i < date::returnMaxDayNumber(month, year); i++) table_copy[i] = table[i]; //Create copy of table
    rain_t tmp;
    for(int i = 0; i < date::returnMaxDayNumber(month, year); i++){
        for(int j = 0; j < date::returnMaxDayNumber(month, year)-1; j++){
            if(table_copy[i].rain_mm < table_copy[j].rain_mm){
                tmp = table_copy[i];
                table_copy[i] = table_copy[j];
                table_copy[j] = tmp;
            }
        }
    }
    printMonthTableRainOnly(table_copy, month, year);
    return table_copy;
}

//Main
int main(){
    //Init Seed
    std::srand(time(NULL));
    
    //user input
    int month, year;
    USER_INPUT: //Label
    std::cout << "|RAIN DATA SIMULATION PROGRAM: |" << std::endl;
    std::cout << "Insert month: " << std::endl;
    std::cin >> month;
    std::cout << "Insert year: " << std::endl;
    std::cin >> year;
    getchar(); //get Enter

    if(date::returnMaxDayNumber(month, year) == -1){ //Invalid input check
        std::cout << "Invalid input!" << std::endl << std::endl;
        goto USER_INPUT;
    };

    //Array Decl.
    rain_t * DataArray = new rain_t[date::returnMaxDayNumber(month, year)];
    
    //Setting Data
    for(int i = 0; i < date::returnMaxDayNumber(month, year); i++){
        DataArray[i].day_detected = date(1+i, month, year);
        
        DataArray[i].rain_detected = (RANDOMQ(0, 100) <= RAIN_PROBABILITY)? true : false;
        if(DataArray[i].rain_detected)
            {DataArray[i].rain_mm = RANDOMQFL(600);} 
        else DataArray[i].rain_mm = 0.0f;
        
        #ifdef DEBUG
        std::cout << DataArray[i].day_detected.toString() << std::endl << DataArray[i].rain_detected << std::endl << DataArray[i].rain_mm << std::endl;
        #endif
    }

    char choice;
    //Menu function
    do{
        std::cout << "** |SELECTION MENU| **" << std::endl;
        std::cout << "\'p\' to print all days detected" << std::endl;
        std::cout << "\'r\' to print only rainy days  " << std::endl;
        std::cout << "\'s\' to print sorted rainy days" << std::endl;
        std::cout << "\'e\' to exit                   " << std::endl;
        choice = getchar();
        switch(choice){
            case 'p': //Print all
                printMonthTable(DataArray, month, year);
                system("pause");
            break;
            case 'r': //Print rainy days only
                printMonthTableRainOnly(DataArray, month, year);
                system("pause");
            break;
            case 's': //Print sorted rainy days
                sortbyMM(DataArray, month, year);
                system("pause");
            case 'e': //Do nothing --> exit
            break;
            default:
                std::cout << "Invalid Command!" << std::endl << std::endl;
            break;
        }
        getchar(); //get Enter
        system("cls"); //Clear screen
    }while(choice != 'e'); //Exit condition
}