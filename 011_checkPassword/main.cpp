/* Obiettivo:
    Creare un programma che fa inserire all'utente 4 caratteri e verifica che ci sia almeno una lettera minuscola, una
    maiuscola e una cifra. Utilizzare l'operatore condizionale if.
    Il valore ASCII dei caratteri minuscoli va da 97 to 122
    Il valore ASCII dei caratteri maiuscoli va da 65 to 90
    Il valore ASCII delle cifre va da 48 a 57.
*/

#include <iostream>

using namespace std;

#define N_CHARS 4

int main() {
    cout << "This program checks if a password, given as input, satisfies the requirements of having at least one lowercase letter, at least uppercase letter and at least one digit ...\n" << endl;

    cout << "Enter " << N_CHARS << " characters ..." << endl;

    bool lowercase = false, uppercase = false, digit = false;

    const char* ORD[N_CHARS] = { "first", "second", "third", "fourth" };
    char chars[N_CHARS] = { '-' };
    for (int i=0; i<N_CHARS; i++) {
        cout << "Enter the " << ORD[i] << " character: ";
        cin >> chars[i];
    }

    // int daVerificare = (a>=K && a<=T) || (b>=K2 && b<=T2) || (c>=K3 && c<=T3)

    for (int i=0; i<N_CHARS && !(lowercase && uppercase && digit); i++) {
        if (chars[i] >= 97 && chars[i] <= 122) lowercase = true;
        else if (chars[i] >= 65 && chars[i] <= 90) uppercase = true;
        else if (chars[i] >= 48 && chars[i] <= 57) digit = true;
    }

    cout << "========================" << endl;

    if (lowercase && uppercase && digit) {
        cout << "The entered password meets the requirements." << endl;
    } else cout << "The entered password doesn't meet the requirements." << endl;

    return 0;
}
