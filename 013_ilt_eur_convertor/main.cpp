/*
Obiettivo:


*/

#include <iostream>

#define ILTEUR 0.0005165
#define EURILT 1936.27

using namespace std;

int main() {

    int conv = -1;
    float origin = -1, converted = -1;
    bool err = false;
    cout << "Scegliere che conversione eseguire: 0 (ILTEUR), 1 (EURILT): ";
    cin >> conv;

    do {
        cout << "Inserire il valore che si vuole convertire: ";
        cin >> origin;

        if (origin < 0) {
            cout << "ERR | importo negativo. Inserire un altro valore." << endl;
        }
    } while (origin < 0);


    switch (conv) {
    case 0: converted = origin * ILTEUR; break;
    case 1: converted = origin * EURILT; break;
    default:
        err = true;
        cout << "ERR | E' stata inserita una conversione non valida." << endl;
    }


    if (!err) {
        cout << "Il valore converitito e' " << converted << endl;
    }





    return 0;
}
