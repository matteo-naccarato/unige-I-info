/* Obiettivo:
    Creare un programma in c++ che chieda all’utente di immettere la lunghezza (intera) di due cateti di
    un triangolo rettangolo e stampi a terminale il quadrato dell’ipotenusa.
 */

#include <iostream>
#include <cmath>

#define N 2

using namespace std;

int inputLeg(int);
bool isValid(int);

const char* ORD[N] = { "FIRST", "SECOND" };

int main() {
    int c1 = 0, c2 = 0, square_hypo = 0;

    cout << "This program calculates, using the length of two (integeres) legs, the square of the hypotenuse of a right triangle ..." << endl;
    cout << "==========================" << endl;

    c1 = inputLeg(0);
    c2 = inputLeg(1);

    square_hypo = pow(c1, 2) + pow(c2, 2);
    cout << "==========================" << endl;
    cout << "The square of the hypotenuse is (" << square_hypo << ")" << endl;

    return 0;
}

int inputLeg(int index) {
    int num;
    bool valid = true;
    do {
        cout << "Insert the length of the " << ORD[index] << " LEG (must be an integer): ";
        cin >> num;
        if (!isValid(num)) {
            valid = false;
            cout << "ERR - input value not valid. Must be a positive integer (> 0)" << endl;
        } else valid = true;
    } while (!valid);
    return num;
}

bool isValid(int num) {
    return num > 0;
}
