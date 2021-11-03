/* Obiettivo - Convertitore lire - euro / euro - lire:
    Creare un programma che chieda all'utente se vuole immettere un valore in euro o in lire, acquisisca il valore
    dall'utente e restituisca il valore convertito nell'altra valuta.
*/

#include <iostream>

#define ILTEUR 0.0005165
#define EURILT 1936.27

using namespace std;

int main() {

    cout << "This programs converts ILT to EUR and viceversa." << endl;
    cout << "=============================" << endl;

    int conv = -1;
    float origin = -1, converted = -1;
    bool err = false;

    do {
        cout << "Choose the conversion that you want to execute: 0 (ILTEUR), 1 (EURILT): ";
        cin >> conv;
        if (conv != 0 && conv != 1) {
            err = true;
            cout << "You enter a wrong value. Try again." << endl;
        } else err = false;
    } while (err);

    do {
        cout << "Enter the value that you want to convert: ";
        cin >> origin;

        if (origin < 0) {
            err = true;
            cout << "ERR | Negative amount. Enter another value." << endl;
        } else err = false;
    } while (err);


    switch (conv) {
    case 0: converted = origin * ILTEUR; break;
    case 1: converted = origin * EURILT; break;
    }

    cout << "=============================" << endl;
    cout << "The converted value is " << converted << endl;

    return 0;
}
