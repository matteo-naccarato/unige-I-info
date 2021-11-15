/* Obiettivo:
    Il programma chiede all’utente di inserire un numero, e calcola tutti I numeri primi compresi tra zero e il numero
    immesso.
    Intanto, possiamo utilizzare un ciclo do-while per far immettere un numero maggiore di 1 all’utente.
    A quel punto, abbiamo bisogno di:
        - un ciclo for che consideri tutti i numeri da 2 fino al numero immesso dall’utente
        - un ulteriore ciclo for che controlli tutti i numeri tra 2 e il numero considerato -1, e veda se uno
        di questi numeri è un divisore.
    I cicli possono essere anche annidati, ossia possiamo avere un ciclo for (o while) all'interno di un altro ciclo for (o
    while)
*/

#include <iostream>

using namespace std;

int main() {

    int num = -1;
    int isPrime = 1;

    cout << "This program determines if number given as input is a prime number or not" << endl;
    cout << "=====================================" << endl;

    do {
        cout << "Enter a number (> 1): ";
        cin >> num;

        if (num <= 1) {
            cout << "ERR | The number must be greater than 1 (> 1). Try again!" << endl;
        }
    } while (num <= 1);


    for (int i = 2; (isPrime=(num%i == 0)? 0: 1)==1 && i < num/2 && isPrime == 1; i++) {}
    cout << "The number (" << num << ") IS" << ((isPrime == 1)? " ": " NOT ") << "a prime number." << endl;

    return 0;
}
