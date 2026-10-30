#include <iostream>

using namespace std;



// *********************************************
// ************* TESTA STRING & CHAR *********** [13.1]
// *********************************************
void skrivNagraAsciiTecken(){
    cout << "skrivNagraAsciiTecken" << endl;
    const char tabulator = 9;
    for (int asciital = 'a'-5; asciital<='z'+5; ++asciital){
        char tecken = asciital;
        cout << asciital << tabulator << tecken << endl;
    }
}



// ***************************************
// ************* TEST FUNKTION ***********
// ***************************************
void testKap13(){
    cout << "Kapitel 13" << endl;
}
