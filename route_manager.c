/** @file route_manager.c
 *  @brief A pipes & filters program that uses conditionals, loops, and string processing tools in C to process airline routes.
 *  @author Felipe R.
 *  @author Hausi M.
 *  @author Jose O.
 *  @author Saasha J.
 *  @author Victoria L.
 *  @author Oliver Goodrum
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The list of arguments passed to the program.
 * @return int 0: No errors; 1: Errors produced.
 *
 */
void typeOfArgument(char* argument, char* type){ //Returns the type of an argument
    
    int i = 0;
    while(argument[i] != '=' && argument[i] != '\0'){
        type[i] = argument[i];
        i ++;
    }
    type[i] = '\0';
    
}
 
void contentsOfArgument(char* argument, char* temp){ //Returns the contents of an argument
    int i = 0;
    while(argument[i] != '='){
        i ++;
    }
    i ++;

    int j = 0;
    while(argument[i + j] != '\0'){
        temp[j] = argument[i + j];
        j ++;
    }

    temp[j] ='\0';
    
}

bool airlineMatch(char* current, char* airline){ //returns true is the flight matches the airline specified in the argument otherwise false
    char temp[50];
    int i = 0;
    for(int k = 0; k < 1; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        temp[j] = current[i];
        i ++;
        j ++;
    }

    temp[j] = '\0';

    return (strcmp(temp, airline) == 0);
}

bool srcCityMatch(char* current, char* srcCity){ //Returns true if the flight and the source city match otherwise returns false
    char temp[50];
    int i = 0;
    for(int k = 0; k < 4; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        temp[j] = current[i];
        i ++;
        j ++;
    }

    temp[j] = '\0';

    return (strcmp(temp, srcCity) == 0);
}

bool srcCountryMatch(char* current, char* srcCountry){// returns true if the source country of the flight matches the source country of the input
    char temp[50];
    int i = 0;
    for(int k = 0; k < 5; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        temp[j] = current[i];
        i ++;
        j ++;
    }

    temp[j] = '\0';

    return (strcmp(temp, srcCountry) == 0);
}

bool destCityMatch(char* current, char* destCity){
    char temp[50];
    int i = 0;
    for(int k = 0; k < 9; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        temp[j] = current[i];
        i ++;
        j ++;
    }

    temp[j] = '\0';

    return (strcmp(temp, destCity) == 0);
}

bool destCountryMatch(char* current, char* destCountry){
    char temp[50];
    int i = 0;
    for(int k = 0; k < 10; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        temp[j] = current[i];
        i ++;
        j ++;
    }

    temp[j] = '\0';

    return (strcmp(temp, destCountry) == 0);
}

//This function returns true if all the inputed arguments match this flight otherwise it returns false
bool dataMatch(char* current, char* airline, bool airlineBool, char* srcCity, bool srcCityBool, char* srcCountry, bool srcCountryBool, char* destCity, bool destCityBool, char* destCountry, bool destCountryBool){
    
    if(airlineBool && !airlineMatch(current, airline)){
        return false;
    }
    if(srcCityBool && !srcCityMatch(current, srcCity)){
        return false;
    }
    if(srcCountryBool && !srcCountryMatch(current, srcCountry)){
        return false;
    }
    if(destCityBool && !destCityMatch(current, destCity)){
        return false;
    }
    if(destCountryBool && !destCountryMatch(current, destCountry)){
        return false;
    }

    return true;
}
//Given a flight and an empty aiport name string this function puts the name of the destination airport name in the aiport name string
void getDestAirportName(char* current, char* destAirportName){
    
    int i = 0;
    for(int k = 0; k < 8; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        destAirportName[j] = current[i];
        i ++;
        j ++;
    }

    destAirportName[j] = '\0';
}

void getSrcAirportIcao(char* current, char* srcAirportIcao){
    
    int i = 0;
    for(int k = 0; k < 6; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        srcAirportIcao[j] = current[i];
        i ++;
        j ++;
    }

    srcAirportIcao[j] = '\0';
}

void getDestAirportIcao(char* current, char* destAirportIcao){
    
    int i = 0;
    for(int k = 0; k < 11; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        destAirportIcao[j] = current[i];
        i ++;
        j ++;
    }

    destAirportIcao[j] = '\0';
}

void getAirlineName(char* current, char* airlineName){

    int j = 0;
    while(current[j] != ','){
        airlineName[j] = current[j];
        
        j ++;
    }

    airlineName[j] = '\0';
}

void getSrcAirportName(char* current, char* srcAirportName){
    
    int i = 0;
    for(int k = 0; k < 3; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        srcAirportName[j] = current[i];
        i ++;
        j ++;
    }

    srcAirportName[j] = '\0';
}

void getFromCity(char* current, char* fromCity){
    
    int i = 0;
    for(int k = 0; k < 4; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        fromCity[j] = current[i];
        i ++;
        j ++;
    }

    fromCity[j] = '\0';
}

void getFromCountry(char* current, char* fromCountry){
    
    int i = 0;
    for(int k = 0; k < 5; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        fromCountry[j] = current[i];
        i ++;
        j ++;
    }

    fromCountry[j] = '\0';
}

void getToCity(char* current, char* toCity){
    
    int i = 0;
    for(int k = 0; k < 9; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        toCity[j] = current[i];
        i ++;
        j ++;
    }

    toCity[j] = '\0';
}

void getToCountry(char* current, char* toCountry){
    
    int i = 0;
    for(int k = 0; k < 10; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        toCountry[j] = current[i];
        i ++;
        j ++;
    }

    toCountry[j] = '\0';
}

void getAirlineIcao(char* current, char* airlineIcao){
    
    int i = 0;
    for(int k = 0; k < 1; k ++){
        while(current[i] != ','){
            i ++;
        }
        i ++;
    }

    int j = 0;
    while(current[i] != ','){
        airlineIcao[j] = current[i];
        i ++;
        j ++;
    }

    airlineIcao[j] = '\0';
}

//This function prints all the information about a certain flight
void printFlight(char* current, bool airlineBool, bool srcCityBool, char* airline, char* srcCity, char* srcCountry, char* destCity, char* destCountry, bool* printed, FILE* ofp){
    
    char destAirportName[50];
    getDestAirportName(current, destAirportName);
    char srcAirportIcao[10];
    getSrcAirportIcao(current, srcAirportIcao);
    char destAiportIcao[10];
    getDestAirportIcao(current, destAiportIcao);
    char airlineName[50];
    getAirlineName(current, airlineName);
    char srcAirportName[50];
    getSrcAirportName(current, srcAirportName);
    char fromCity[50];
    getFromCity(current, fromCity);
    char fromCountry[50];
    getFromCountry(current, fromCountry);
    char toCity[50];
    getToCity(current, toCity);
    char toCountry[50];
    getToCountry(current, toCountry);
    char airlineIcao[10];
    getAirlineIcao(current, airlineIcao);
    
    if(airlineBool){
        if(!(*printed)){
            fprintf(ofp, "FLIGHTS TO %s BY %s (%s):\n", toCountry, airlineName, airlineIcao);
            *printed = true;
        }
        fprintf(ofp, "FROM: %s, %s, %s TO: %s (%s), %s\n", srcAirportIcao, fromCity, fromCountry, destAirportName, destAiportIcao, toCity);
    } else if(srcCityBool){
        if(!(*printed)){
            fprintf(ofp, "FLIGHTS FROM %s, %s TO %s, %s:\n", fromCity, fromCountry, toCity, toCountry);
            *printed = true;
        }
        fprintf(ofp, "AIRLINE: %s (%s) ROUTE: %s-%s\n", airlineName, airlineIcao, srcAirportIcao, destAiportIcao);
    } else {
        if(!(*printed)){
            fprintf(ofp, "FLIGHTS FROM %s TO %s, %s:\n", fromCountry, toCity, toCountry);
            *printed = true;
        }
        fprintf(ofp, "AIRLINE: %s (%s) ORIGIN: %s (%s), %s\n", airlineName, airlineIcao, srcAirportName, srcAirportIcao, fromCity);
    }
}

int main(int argc, char *argv[]){
    char data[50];
    bool dataBool = false;
    char airline[50];
    bool airlineBool = false;
    char srcCity[50];
    bool srcCityBool = false;
    char srcCountry[50];
    bool srcCountryBool = false;
    char destCity[50];
    bool destCityBool = false;
    char destCountry[50];
    bool destCountryBool = false;
    char type[50];
    char argument[150];
    char current[300];
    bool printed = false;
    
    

    for(int i = 1; i < argc; i++){
        strcpy(argument, argv[i]);
        typeOfArgument(argument, type);
        
        


        if(strcmp(type, "--DATA") == 0){
            contentsOfArgument(argument, data);
            dataBool = true;
        } else if(strcmp(type, "--AIRLINE") == 0){
            contentsOfArgument(argument, airline);
            airlineBool = true;
        } else if(strcmp(type, "--SRC_CITY") == 0){
            contentsOfArgument(argument, srcCity);
            srcCityBool = true;
        } else if (strcmp(type, "--SRC_COUNTRY") == 0){
            contentsOfArgument(argument, srcCountry);
            srcCountryBool = true;
        } else if(strcmp(type, "--DEST_CITY") == 0){
            contentsOfArgument(argument, destCity);
            destCityBool = true;
        } else if(strcmp(type, "--DEST_COUNTRY") == 0){
            contentsOfArgument(argument, destCountry);
            destCountryBool = true;
        }

    }
    

    FILE* ifp = fopen(data, "r"); // open the file
    FILE* ofp = fopen("output.txt", "w");
    if(ifp == NULL || ofp == NULL){
        printf("Error opening file : %s or opening file output.txt\n", data);
        exit(EXIT_FAILURE);
    }

    fgets(current, 300, ifp); //gets the first line with all the titles
    


    while(fgets(current, 300, ifp) != NULL){
        if(dataMatch(current, airline, airlineBool, srcCity, srcCityBool, srcCountry, srcCountryBool, destCity, destCityBool, destCountry, destCountryBool)){
            printFlight(current, airlineBool, srcCityBool, airline, srcCity, srcCountry, destCity, destCountry, &printed, ofp);
        }
    }

    if(!printed){
        fprintf(ofp, "NO RESULTS FOUND.\n");
    }

    fclose(ifp);
    fclose(ofp);
    
    exit(0);
}
