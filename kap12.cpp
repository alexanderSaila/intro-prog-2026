#include <iostream>
#include <assert.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;


// *********************************************
// ************* KYLSKÅP *********************** [12.2]
// *********************************************
void kylskapMedWhileVillkor () {
    cout << "Kylskåp med while villkor " << endl ;
    double temperatur = 0;
    while ( temperatur > -273) {
        cout << "Measure a new temperature:";
        cin >> temperatur;
    }
    cout << "Lämnar kylskåpsloop " << endl ;
}

void kylskapMedWhileTrue(){
    cout << "Kylskåp med while true " << endl ;
    double temperatur = 0;

    while (temperatur <= -273) {
        cout << "Measure a new temperature:";
        cin >> temperatur;

        if(temperatur <= 2){
            cout << "Temperature is too cold" << endl;
        }else if(temperatur >= 8){
            cout << "Temperature is too hot" << endl;
        }else{
            cout << "Temperature is lagom" << endl;
        }
    }
    cout << "Lämnar kylskåpsloop " << endl ;
}

// *********************************************
// ************* BERÄKNA SUMMOR **************** [12.4]
// *********************************************
int aritmetiskSummaFranAnalys ( int n) {
    return n*(n+1)/2;
}

int aritmetiskSummaFranLoop ( int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }

    return sum;
}

void jamforSummaberakningar ( int n ){
    int resultat = aritmetiskSummaFranLoop (n );
    int diff = resultat - aritmetiskSummaFranAnalys (n);
    cout << " aritmetiskSummaFranLoop (" << n << ") = " << resultat
         << ", diff = " << diff << endl ;
    assert ( diff == 0 );
}

void jamforFleraSummaberakningar () {
    cout << " jamfor flera summaberakningar " << endl ;
    for (int n =0; n <100 ; n += 1)
        jamforSummaberakningar (n) ;
}


// ******************************************
// ************* SLUMPTAL ******************* [12.5]
// ******************************************
unsigned int PSEUDOSLUMPTAL = 42;
unsigned int ettSlumptal () {
    PSEUDOSLUMPTAL = 1664525* PSEUDOSLUMPTAL + 1013904223;
    return PSEUDOSLUMPTAL ;
}

void undersokSlumptalsgeneratorn () {
    cout << " undersokSlumptalsgeneratorn " << endl ;
    unsigned long long int antalAnrop = 0;
    unsigned long long int foregaendeAntal = 0;
    int antal42or = 0;
    while ( antal42or < 4) {
        unsigned int i = ettSlumptal () ;
        antalAnrop += 1;
        if (i == 42) {
            cout << "såg 42 efter " << antalAnrop << " anrop ." ;
            if ( antal42or ==0) cout << " ( den första 42: an)" << endl ;
            else cout << " dvs . " << antalAnrop - foregaendeAntal << "steg efter föregående 42: a" << endl ;
            foregaendeAntal = antalAnrop ;
            antal42or += 1;
        }
    }
}

void froaSlumptalsgeneratorn ( unsigned int fro ){
    PSEUDOSLUMPTAL = fro ;
}

// fröat slumptal
unsigned int froatSlumptal () { // BUGGIG
    froaSlumptalsgeneratorn ( time ( nullptr )) ;
    this_thread::sleep_for(milliseconds(1000)); // för att skapa ett nytt frö varje gång
    return ettSlumptal () ;
}
void provaFroatSlumptal () {
    cout << " provaFroatSlumptal " << endl ;
    cout << " skriver 5 frö ade slumptal " << endl ;
    for (int i =0; i <5; ++ i)
        cout << froatSlumptal () << " ";
    cout << endl ;
}

// ************************************************
// ************* GISSA DATORNS TAL **************** [12.6]
// ************************************************
int nyttTal(int n){
    return froatSlumptal()%n;
}

int anvandarensGissning(){
    int gissning;
    cout << "Din gissning: ";
    cin >> gissning;
    cout << endl;
    return gissning;
}

void utforEnSpelomgang(){
    cout << "utför en spelomgång." << endl;
    const int n  = 100;
    const int datornsTal = nyttTal(n);
    int antalGissningar = 0;
    cout << "Datorn tänker på ett tal mellan noll och " << n << ". Gissa vilket!" << endl;

    while(true){
        antalGissningar++;
        int gissning = anvandarensGissning();
        if(gissning < datornsTal)
            cout << "För litet" << endl;
        else if(gissning > datornsTal)
            cout << "För stort" << endl;
        else break;
    }
    cout << "Grattis du gissade rätt! [" << datornsTal << "]" << " Antal försök: " << antalGissningar << endl;
}


// ***************************************************
// ************* INTEGRAL BERÄKNINGAR **************** [*12.7]
// ***************************************************
double integralX2FranAnalys(double a, double b){
    return (b*b*b - a*a*a)/3;
}

double integralX2FranLoop(double a, double b){
    double dx = 0.01;
    double area = 0;
    for(double x=a; x<(b-dx); x+=dx){
        double y1 = x*x;
        double y2 = (x+dx)*(x+dx);
        area += dx*(y1+y2)/2;
        //area += x*x*dx;
    }
    return area;
}

void jamnforIntegralBerakningar(double a, double b){
    double resultatLoop = integralX2FranLoop(a,b);
    double resultatAnalys = integralX2FranAnalys(a,b);
    double diff = resultatLoop - resultatAnalys;
    cout << "Diff = " << diff << ". Från analys: " << resultatAnalys << " och loop: " << resultatLoop << endl;
}


// **************************************************
// ************* KVADRAT BERÄKNINGAR **************** [12.8]
// **************************************************
double kvadratFranLoop(double x){
    double a = x/2;
    double k = x/a;
    for(int i=0; i<10; i++){
        a = (a+k)/2;
        k = x/a;
    }
    return k;
}

void jamnforKvadratBerakningar(double x){
    double resultat = kvadratFranLoop(x);
    double diff = resultat - sqrt(x);
    cout << "Kvadratroten (" << x << ") beräknades till: " << resultat << ". diff: " << diff << endl;
}


// **************************************************
// ************* FIBONACCI ************************** [12.9]
// **************************************************
void skrivUtFibonacci(int n){
    int preNum = 0;
    int curNum = 1;
    for(int i=1; i<=n; i++){
        cout << i << ":" << curNum << endl;
        int nextNum = curNum+preNum;
        preNum = curNum;
        curNum = nextNum;
    }
}



// **************************************************
// ************* RITA MED TEXT ********************** [12.10]
// **************************************************
void skrivMultiplikationsmatris(){
    cout << "MultiplikationsMatris" << endl;
}

void ritaFylldRektangel(int hojd, int bredd){
    cout << "Fylld Rektangel" << endl;
    for(int h=0; h<hojd; h++){
        for(int b=0; b<bredd; b++){
            cout << "#";
        }
        cout << endl;
    }
}

void ritaRektangel(int hojd, int bredd){
    cout << "Rektangel" << endl;
    for(int h=0; h<hojd; h++){
        cout << "#";
        for(int b=1; b<bredd-1; b++){
            if(h == 0 || h == hojd-1){
                cout << "#";
            }else{
                cout << " ";
            }
        }
        cout << "#" << endl;
    }
}

void ritaFylldTriangel(int hojd){
    cout << "Fylld Triangel" << endl;
    for(int h=1; h<=hojd; h++){
        for(int b=0; b<h; b++){
            cout << "#";
        }
        cout << endl;
    }
}

void ritaFyllCirkel(int radie){
    cout << "Fylld Cirkel" << endl;
    for(int x = -radie; x<=radie; x++){
        for(int y = -radie; y<=radie; y++){
            double hypo = sqrt(x*x + y*y);
            if(hypo < radie)
                cout << "##";
            else cout << "  ";
        }
        cout << endl;
    }
}

void ritaMedText(){
    skrivMultiplikationsmatris();
    cout << endl;
    ritaFylldRektangel(4,20);
    cout << endl;
    ritaRektangel(4,20);
    cout << endl;
    ritaFylldTriangel(4);
    cout << endl;
    ritaFyllCirkel(5);
}



// **************************************************
// ************* ESTIMERA PI ************************ [12.11]
// **************************************************
double estimatAvCirkelareaFranRadie ( int radie ) {
    int antalKvadrater = 0;
    for(int x = -radie; x<=radie; x++){
        for(int y = -radie; y<=radie; y++){
            if( sqrt(x*x + y*y) <= radie){
                antalKvadrater++;
            }
        }
    }
    return antalKvadrater;
}
double estimatAvPiFranRadie ( int radie ) {
    return estimatAvCirkelareaFranRadie(radie)/(radie*radie);
}
void gorFleraEstimatAvPi () {
    for (int radie = 5 ; radie < 10000; radie = radie *2) {
        double pi = estimatAvPiFranRadie ( radie );
        cout << " radie = " << radie << ", pi estimeras till " << pi <<
            endl ;
    }
}



// **************************************************
// ************* RATIONELL APPROX ******************* [12.12]
// **************************************************
void skrivRationellApproximationAvPi(){
    double const pi = M_PI;
    double bästaApprox = pi;
    int bästaT = pi;
    int bästaN = pi;
    for(int t=1; t<100; t++){
        for(int n=1; n<100; n++){
            double tal = (double)t/n;
            double diff = abs(pi - tal);
            if(diff < bästaApprox){
                bästaT = t;
                bästaN = n;
                bästaApprox = diff;
            }
        }
    }
    cout << "Bästa approximation : " << bästaT << "/" << bästaN << endl;
}

void skrivUtRationellAproximation(double x, int antalSiffror){
    double bästaApprox = x;
    int bästaT = x;
    int bästaN = x;

    int gräns = pow(10,antalSiffror);
    for(int t=1; t<gräns; t++){
        for(int n=1; n<gräns; n++){
            double tal = (double)t/n;
            double diff = abs(x - tal);

            if(diff < bästaApprox){
                bästaT = t;
                bästaN = n;
                bästaApprox = diff;
            }
        }
    }
    cout << "Bästa approximation : " << bästaT << "/" << bästaN << endl;
}

// **************************************************
// ************* ÄR PRIMTAL ************************* [12.13]
// **************************************************
bool arPrimtal(int n){
    for(int i=n-1; i>1; i--){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
void provaPrimtal(){
    cout << endl
         << "provaPrimtal" << endl
         << "Knappa in tal, avsluta med 0." << endl;
    while (true){
        cout << "ge tal:";
        int tal = 1;
        cin >> tal;
        if (tal<=0)
            break;
        if (arPrimtal(tal))
            cout << tal << " är primtal" << endl;
        else cout << tal << " kan faktoriseras" << endl;
    }
    cout << "(avslutar provaPrimtal)" << endl;
}
void testaPrimtal() {
    cout << "testaPrimtal" << endl;
    assert( arPrimtal(7) );
    assert( arPrimtal(7919) );
    assert( !arPrimtal(7913) );
    assert( !arPrimtal(10201) );
    cout << "testaPrimtal lyckades" << endl;
}



// **************************************************
// ************* PRIMTALSFORSKNING ****************** [*12.14]
// **************************************************



// **************************************************
// ************* MATTE 3X+1 ************************* [12.15]
// **************************************************
void skrivCollatzSekvens(long int startvarde){
    for(int i=0; i<25; i++){
        startvarde = (startvarde%2 == 0 ? startvarde/2 : startvarde*3+1);
        cout << startvarde << ", ";
    }
}
long int collatzMax(long int startvarde){
    int högstaCollatz = startvarde;
    for(int i=0; i<25; i++){
        startvarde = (startvarde%2 == 0 ? startvarde/2 : startvarde*3+1);
        if(startvarde > högstaCollatz)
            högstaCollatz = startvarde;
    }
    return högstaCollatz;
}



// **************************************************
// ************* MACLAURIN SERIE ******************** [*12.16]
// **************************************************



// ***************************************
// ************* TEST FUNKTION ***********
// ***************************************
void testKap12(){
    jamforFleraSummaberakningar();
}
