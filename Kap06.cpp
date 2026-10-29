#include <iostream>
#include <iomanip>

using namespace std;

void provaUtskriftAvFlyttal(){
    cout << "provaUtskriftAvFlyttal" << endl;
    double tal = 9.999999999999;
    cout << "Talet är: " << tal << endl;
    cout << "Med 3 värdesiffror: " << setprecision(3) << tal << endl;
    cout << "Med 3 decimaler: " << fixed << setprecision(3) << tal <<
        endl;
    cout << "Talet är: " << tal << endl;
}

double askForInput(string message){
    double value;

    cout << message;
    cin >> value;

    return value;
}

void beräknaBokKostnad(){
    double bokPris = askForInput("Vad kostar boken?: ");
    double antalSidor = askForInput("Hur många sidor har boken?: ");
    double procentAttLäsa = askForInput("Hur många procent av boken ska du läsa?: ");
    double minuterPerSida = askForInput("Hur många minuter per sida lägger du?: ");

    cout << "bokPris: " << bokPris << "kr , antalSidor: " << antalSidor
         << "st , procentAttLäsa: " << procentAttLäsa << "%, minuterPerSida: " << minuterPerSida
         << "min" << endl;

    double totaltAntalTimmar = antalSidor*procentAttLäsa*minuterPerSida/6000;
    double kostnadPerTimme = bokPris/totaltAntalTimmar;

    cout << "Total kostnad per timme blir: " << fixed << setprecision(2) << kostnadPerTimme << "kr/h" << endl;
}

void undersokFlyttalstyper(){
    cout << "En float upptar " << 8*sizeof( float ) << " bit." << endl;

    cout << "En double upptar " << 8*sizeof( double ) << " bit." <<endl;

    cout << "En long double upptar " << 8*sizeof( long double ) << "bit." << endl;
}

bool ungefarLika(double a, double b){
    return ((a-b) <= 0.001 && (a-b) >= -0.001);
}

void testaUngefarLika(){
    cout << "testar ungefarLika" << endl;
    const double epsilon = 0.0005;
    const double delta = 0.002;
    const double x = 123.5;
    bool ok1 = ungefarLika( x, x + epsilon);
    bool ok2 = ungefarLika( x, x- epsilon);
    bool ok3 = !ungefarLika( x, x + delta);
    bool ok4 = !ungefarLika( x, x- delta);

    if (ok1 && ok2 && ok3 && ok4)
        cout << "ungefarLika klarade testen" << endl;
    else cout << "ungefarLika har minst en BUGG!!!!!" << endl;
    cout << endl;
}

void provaUngefarLika(){
    cout << "Provar ungefarLika." << endl;
    double a = 0.3;
    double b = 0.1 + 0.1 + 0.1;
    if ( ungefarLika(a,b) ){
        cout << "a och b har ungefär samma värden." << endl;
        if (a == b){
            cout << "De har faktiskt exakt samma värden!" << endl;
        }
        else{
            cout << "Men bara ungefär." << endl;
        }
    }
}

void testKap6(){
    cout << "kör test kap6" << endl;
    provaUngefarLika();
}
