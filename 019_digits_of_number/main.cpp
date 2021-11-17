/* Obiettivo:
    Scrivere un programma che chieda all'utente di inserire un numero intero e calcoli di quante cifre è composto
    Hint: usare un ciclo while
*/

#include <iostream>

using namespace std;

int main() {

    cout << "Given an integer as input, this program calculates the number of digits that make up the number." << endl;
    cout << "===================================" << endl;

    int num = 0;
    int divCheck = 1;
    int cntDigits = 0;

    cout << "Please enter an integer: ";
    cin >> num;

    if (num != 0) {
        while (num/divCheck >= 1 || num/divCheck <= -1) {
            cntDigits++;
            divCheck *= 10;
        }
    } else cntDigits = 1;

    cout << "The number '" << num << "' consists of " << cntDigits << " digit(s)." << endl;

    return 0;
}
