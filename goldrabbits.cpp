// Marisol Morales 
// CECS 325 - 02 
// Project 5 - Gold Rabbits part 1
// Due Date: 11/14/2024
//
//I certify that this program is my own original work. I did not copy any part of this program from
//any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <time.h>
#include <iomanip>
#include <map>
#include <stdexcept>
#include <limits.h>

using namespace std;


int totalCalls = 0; // int created to keep track of how many times we call goldRabbits
static map<int, int> fiboMap;

int goldRabbits(int n){

    totalCalls++;

    //print out the fiboMap if the incoming parameter is -1
    if(n == -1){
        cout << "Fibo Map" << endl;
        for (const auto& pair : fiboMap){
            cout << pair.first << " : " << pair.second << endl;
        }
        return -1;
    }

    if (fiboMap.find(n) != fiboMap.end()){
        return fiboMap[n];
    }

    if (n == 0 || n == 1){
        fiboMap[0] = 1;
        fiboMap[1] = 1;
        return 1;
    }
    //check if there is an overflow error and if there is then throw an error that will later be caught in main
    int x = goldRabbits(n - 1);
    int y = goldRabbits(n - 2);

    if (x  > INT_MAX - y){
        throw overflow_error("overflow on:" + to_string(n));
    }

    fiboMap[n] = x + y;
    return fiboMap[n];

}

int main(){

    
    int const months = 12 * 10; //this is 10 years or 120 months
    int start = time(0); //number of seconds since Jan 1, 1970

    for(int i = 0; i < months; i++){
        try{
            int current = time(0); // number of seconds since program has started
            cout << setw(5) << current - start << ":"; //print elapsed seconds
            cout << " GoldRabbits(" << setw(2) << i << ") = ";
            cout << setw(11) << goldRabbits(i) << " fiboCount: " << totalCalls << endl;  //the call to goldRabbits
        }
        catch(const overflow_error& e){
            cout << "overflow on:" << i << endl;
            goldRabbits(-1);
            break;
        }
    }
    //goldRabbits(-1);
    return 0;

}
