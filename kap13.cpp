#include <iostream>
#include <string>
#include <assert.h>

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



// *********************************************
// ************* DATATYPEN STD::STRING ********* [13.2]
// *********************************************
string versalstrang(const string& str){
    string nyString = "";
    for(unsigned int i=0; i<str.size(); i++){
        nyString += toupper(str[i]);
    }
    return nyString;
}

void automattestaVersalstrang(){
    cout << "testar versalStrang" << endl;
    assert( versalstrang("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ" );
    cout << "test av versalStrang lyckades!" << endl;
}

string rubrikstrang(const string& str){
    string nyString = "";
    bool nästaUpp = true;
    for(unsigned int i=0; i<str.size(); i++){
        char c = tolower(str[i]);

        if(nästaUpp){
            c = toupper(c);
            nästaUpp = false;
        }

        if(c == ' ') nästaUpp = true;

        nyString += c;
    }
    return nyString;
}

void automattestaRubrikstrang(){
    cout << "testar rubrikstrang" << endl;

    cout << rubrikstrang("ha en BRA DAG!") << endl;

    assert( rubrikstrang("ha en BRA DAG!") == "Ha En Bra Dag!" );
    assert( rubrikstrang("HA EN BRA DAG!") == "Ha En Bra Dag!" );
    assert( rubrikstrang("") == "" );
    cout << "test av rubrikstrang lyckades!" << endl;
}

string reducerad(const string& str){
    string reduceradString = "";
    bool skippaNästa = false;
    for(size_t i=0; i<str.size(); i++){
        char c = str[i];
        if(c == ' '){
            if(skippaNästa) continue;
            skippaNästa = true;
        }else{
            skippaNästa = false;
        }
        reduceradString += c;
    }
    return reduceradString;
}

void automattestaReducerad(){
    cout << "testar reducerad" << endl;

    assert( reducerad(" Ha en    bra  dag!    ") == " Ha en bra dag! " );
    assert( reducerad( " A        B C ") == " A B C " );
    assert( reducerad("ABC") == "ABC" );
    cout << "testen av reducerad lyckades!" << endl;
}

bool arVokal(char ch){
    string vokaler = "aeiouyAEIOUY";
    for(unsigned int i=0; i<vokaler.size(); i++){
        if(ch == vokaler[i]){
            return true;
        }
    }
    return false;
}

bool arKonsonant(char ch){
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    for(unsigned int i=0; i<konsonanter.size(); i++){
        if(ch == konsonanter[i]){
            return true;
        }
    }
    return false;
}

void automattestaArVokalOchArKonsonant(){
    cout << "automattestar arVokal och arKonsonant" << endl;
    string vokaler = "aeiouyAEIOUY";
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string andraTecken = ".,?!; ";
    for (size_t i=0; i<vokaler.size(); ++i)
        assert( arVokal(vokaler[i]) );
    for (size_t i=0; i<konsonanter.size(); ++i)
        assert( arKonsonant(konsonanter[i]) );
    for (size_t i=0; i<andraTecken.size(); ++i)
        assert(!arVokal(andraTecken[i]) && !arKonsonant(andraTecken[i]));
    cout << "testerna av arVokal/arKonsonant lyckades!" << endl;
}


// *********************************************
// *************  *********** [13.2]
// *********************************************



// *********************************************
// *************  *********** [13.2]
// *********************************************



// *********************************************
// *************  *********** [13.2]
// *********************************************



// *********************************************
// *************  *********** [13.2]
// *********************************************



// *********************************************
// *************  *********** [13.2]
// *********************************************



// *********************************************
// *************  *********** [13.2]
// *********************************************
// ***************************************
// ************* TEST FUNKTION ***********
// ***************************************
void testKap13(){
    cout << "Kapitel 13" << endl;
    automattestaArVokalOchArKonsonant();
}
