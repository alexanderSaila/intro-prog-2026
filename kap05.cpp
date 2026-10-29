#include <iostream>

using namespace std;

// Returnerar true omm användaren har ett pass.
    bool harPass(){
    cout << "Har du pass (ja/nej)?:";
    string svar;
    cin >> svar;
    return (svar == "ja");
}
// Returnerar true omm användaren har ett körkort.
bool harKorkort(){
    cout << "Har du korkort (ja/nej)?:";
    string svar;
    cin >> svar;
    return (svar == "ja");
}
// Returnerar användarens ålder
int alder(){
    cout << "Din alder:";
    int alder;
    cin >> alder;
    return alder;
}
// Returnerar true omm användaren får köpa öl
bool farKopaOlVersion1(){
    return alder()>=20 && (harKorkort() || harPass());
}
// alternativ implementering av farKopaOl
bool farKopaOlVersion0(){
    if(alder() >= 20){
        if(harKorkort()){
            return true;
        }
        if(harPass()){
            return true;
        }
    }
    return false;
}
// Provkör ovanstående funktioner
void provaFarKopaOl(){
    cout << "provar farKopaOl" << endl;
    if (farKopaOlVersion1())
        cout << "Grattis!" << endl;
    else cout << "Kaffe ar ocksa gott!" << endl;
}

void skrivMedelvarde(double summa, int antalTermer){
    if (antalTermer == 0)
        cout << "medelvärdet kan ej beräknas" << endl;
    else {
        double medelvarde = summa/antalTermer;
        cout << "medelvärdet är " << medelvarde << endl;
    }
}

void provaSkrivMedelvarde(){
    skrivMedelvarde(3+5+4+3, 4);
    skrivMedelvarde(0, 0);
}

void testKap5(){
    provaSkrivMedelvarde();
}
