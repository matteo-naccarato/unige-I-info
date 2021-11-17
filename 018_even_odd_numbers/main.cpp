/* Obiettivo:
    Scrivere un programma che permetta all'utente di inserire una serie di numeri positivi interi, finché non viene
    inserito il valore -1: a quel punto, il programma dice quanti numeri pari e dispari sono stati immessi.
    Hint: usare un ciclo do - while
*/

#include <iostream>
#define STOP_VALUE -1

using namespace std;

int main() {

    cout << "This program prints, after entering '-1' following a series of positive integers, how many even and odd numbers have been entered." << endl;
    cout << "=========================================" << endl;

    int num = STOP_VALUE;
    int cEven = 0, cOdd = 0;

    do {

        do {
            cout << "Enter a positive number (>0): ";
            cin >> num;
            if (num == STOP_VALUE) break;
            if (num <= 0) {
                cout << "ERR | The number must be positive. Try again." << endl;
            }
        } while (num <= 0);

        if (num == STOP_VALUE) break;
        if (num%2 == 0) cEven++;
        else cOdd++;
        cout << "Get it! Now enter '-1' to see the result or continua entering other numbers ..." << endl;
    } while (num != STOP_VALUE);


    cout << "You entered " << cEven << " even numbers and " << cOdd << " odd numbers." << endl;

    return 0;
}
