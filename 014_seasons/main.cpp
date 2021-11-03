/*
Obiettivo:

*/

#include <iostream>

#define N_MONTHS

using namespace std;

// January, February, March, April, May, June, July, August, September, October, November, December
const int DAYS_IN_MONTHS[N_MONTHS] = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

int main() {

    cout << "Dati in input giorno e mese, restituisce la stagione corrispondente." << endl;

    int day = -1, month = -1;

    do {
        cout << "Inserire il mese desiderato come valore intero (January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12";
        cin >> month;
        if (month < 1 || month > 13) {
            err = true;
            cout << "ERR" << endl;
        }
    } while (err);

    err = false;

    do {
        cout << "Inserire il giorno desiderato: ";
        cin >> giorno;
        if (day < 1 || day > DAYS_IN_MONTHS[month - 1]) {
            err = true;
            cout << "Hai inserito un giorno che non esiste nel mese specificato." << endl;
        }
    } while (err);

    cout << "======= SWTICH version =======" << endl;
    switch (month) {

    }

    cout << "========= IF version =========" << endl;
    if ()


    return 0;
}
