/* Obiettivo:
    Il programma chiede all’utente di inserire due frazioni, e le riduce ai minimi termini.
    In questo esercizio, voglio usare una funzione per effettuare la riduzione delle funzioni ai minimi termini. In questo
    caso può essere utile passare i parametri per riferimento, così da modificare anche i valori di numeratore e
    denominatore nella nostra funzione main
*/

#include <iostream>
#define N_FRACTIONS 2
#define OP_ACCEPTED '/'

using namespace std;

void reduceFraction(float& num, float&den);
int calc_mcd(int n1, int n2);

int main() {

    cout << "This program reduces two fractions to minimum." << endl;
    cout << "=====================================" << endl;

    float num = 0.f, den = 0.f;
    char op = '\0';

    for (int i=0; i<N_FRACTIONS; i++) {
        do {
            cout << "Enter the fraciton (ex. 9/3): ";
            cin >> num >> op >> den;
            if (op != OP_ACCEPTED)
                cout << "ERR | You entered a wrong operator. It is only accepted '/'" << endl;
        } while(op != OP_ACCEPTED);

        cout << "The reduced fraction of " << num << OP_ACCEPTED << den << " is: ";
        reduceFraction(num, den);
        cout << num << OP_ACCEPTED << den << endl;
    }

    return 0;
}


void reduceFraction(float& num, float&den) {
    int mcd = calc_mcd(num, den);
    num /= mcd;
    den /= mcd;
}

int calc_mcd(int n1, int n2) {
    int mcd = 1;
    for (int i=2; i<=min(n1, n2); i++) {
        if (n1%i==0 && n2%i==0)
            mcd = i;
    }
    return mcd;
}
