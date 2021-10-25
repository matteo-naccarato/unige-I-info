// Obiettivo: implementare una calcolatrice

#include <iostream>

using namespace std;

int main()
{
    double op1 = 0.0;
    double op2 = 0.0;
    double risultato = 0.0;
    bool isValid = true;
    char op = ' ';

    cout << "Inserire una operazione: ";
    cin >> op1 >> op >> op2;

    switch (op) {
    case '+': risultato = op1 + op2; break;
    case '-': risultato = op1 - op2; break;
    case '*': risultato = op1 * op2; break;
    case '/':
        if (op2 != 0) {
            risultato = op1 / op2;
        } else {
            isValid = false;
            cout << "ERRORE | Divisione per zero!" << endl;
        }
        break;
    default:
        isValid = false;
        cout << "ERRORE | Operatore non supportato!" << endl;
    }

    if (isValid)
        cout << risultato;

    /* if (op == '+') {
        risultato = op1 + op2;
        cout << risultato << endl;
    } else if (op == '-') {
        risultato = op1 - op2;
        cout << risultato << endl;
        } else if (op == '*') {
            risultato = op1 * op2;
            cout << risultato << endl;
            } else if (op == '/') {
                if (op2 != 0) {
                    risultato = op1 / op2;
                    cout << risultato << endl;
                } else cout << "ERRORE | Divisione per zero!" << endl;
            } else cout << "ERRORE | Operazione non supportata!" << endl; */

    return 0;
}
