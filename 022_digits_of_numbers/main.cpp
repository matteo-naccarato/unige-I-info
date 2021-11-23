/* Obiettivo:
    Scrivere un programma che chieda all’utente di inserire dei numeri interi, finché l’utente non inserisce -1 (per
    uscire dal ciclo).
    A quel punto, il programma stampa il numero di cifre totale immesso dall’utente.
*/

#include <iostream>

using namespace std;

int digit_of_number(int num);

int main() {
    cout << "This program takes n numbers (until -1 is given) and calculates the total number of digits entered by the user." << endl;
    cout << "========================================" << endl;

    int num = -1, n_digits = 0;
    do {
        cout << "Enter a number: ";
        cin >> num;
        n_digits += digit_of_number(num);
    } while(num != -1);

    cout << "The total number of digits entered is: " << n_digits << endl;

    return 0;
}

int digit_of_number(int num) {
    int cnt = 0, divCheck = 1;
    if (num != 0) {
        while (num/divCheck >= 1 || num/divCheck <= -1) {
            cnt++;
            divCheck *= 10;
        }
    } else cnt = 1;
    return cnt;
}
