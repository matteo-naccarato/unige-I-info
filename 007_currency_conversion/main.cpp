/* Obiettivo:
     Realizzare un convertitore Euro -> Lire, utilizzando come fattore di conversione l’intero costante 1936.
*/

#include <iostream>

#define EURO2LIRE 1936
#define EU_SYMBOL "EUR"
#define LIRE_SYMBOL "ITL"

using namespace std;

int main()
{
    float origin = 0, converted = 0;

    cout << "This program converts the value of the currencies (at the momento only EURO-LIRE)." << endl;
    cout << "=========================" << endl;

    do {
        cout << "Insert the value of EURO that you want to convert in LIRE: ";
        cin >> origin;
        if (origin < 0) {
            cout << "ERR - the value must be positive or equal to zero (>= 0). Try with another value." << endl;
        }
    } while (origin < 0);

    converted = origin * EURO2LIRE;

    cout << "=========================" << endl;
    cout << EU_SYMBOL << " " << origin << " = " << LIRE_SYMBOL << " " << converted << endl;

    return 0;
}
