#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;


void countTo(const int count){

    for( int i = 0; i <= count; i++ ){
        cout << i << " ";
        sleep_for(milliseconds(50));
    }
}

void printSlow(const string message){

    for(char c : message){
        cout << c;
        sleep_for(milliseconds(25));
    }

    cout << endl;
}

void räknaTillTre(){
    int speed = 300;

    sleep_for(milliseconds(speed));
    cout << "Ett" << endl;
    sleep_for(milliseconds(speed));
    cout << "Två" << endl;
    sleep_for(milliseconds(speed));
    cout << "Tre" << endl;
}

void räknaTillFyra(){
    int speed = 300;

    sleep_for(milliseconds(speed));
    cout << "Ett" << endl;
    sleep_for(milliseconds(speed));
    cout << "Två" << endl;
    sleep_for(milliseconds(speed));
    cout << "Tre" << endl;
    sleep_for(milliseconds(speed));
    cout << "Fyra" << endl;
}

void testKap2(){
    räknaTillTre();
    räknaTillFyra();
}
