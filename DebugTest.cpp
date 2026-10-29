#include <iostream>

using namespace std;
void provaUtskriftAvFlyttal();


int increase(int myNumber, int amount){
    int newAmount = myNumber + amount;

    provaUtskriftAvFlyttal();

    return newAmount;
}

void debugTest1(){
    int x = 2;
    for(int i=0; i<5; i++){
        int increaseAmount = 5;
        x = increase(x, increaseAmount);
    }
}

