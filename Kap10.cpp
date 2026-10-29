#include <iostream>
#include <math.h>

using namespace std;


double hypotenusa(double a,double b){
    return sqrt(a*a + b*b);
}

void skrivHypotenusaBeräkning(double a, double b){
    cout << "Hypotenusan för " << a << " och " << b << " är: " << hypotenusa(a,b) << endl;
}

void testKap10(){

    skrivHypotenusaBeräkning(4,3);
}
