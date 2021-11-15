/* Obiettivo:
    Sviluppare un programma che chieda all'utente un numero e stampi a terminale un pattern predefinito a seconda
    del numero inserito. Ad esempio, se l'utente inserisce il numero 8, il programma stamperà a terminale:
    - V1:
        ********
        ********
        ********
        ********
        ********
        ********
        ********
        ********

    - V2: Potete poi complicare l’esercizio, stampando un triangolo piuttosto che un quadrato:
        *
        **
        ***
        ****
        *****
        ******
        *******
        ********

    - V3: O anche pattern più complessi:
        *2345678
        **345678
        ***45678
        ****5678
        *****678
        ******78
        *******8
        ********
*/

#include <iostream>

using namespace std;

int main() {

    cout << "This program prints a specific pattern that dipends on the number (> 0) given as input." << endl;
    cout << "==========================================" << endl;

    int num = -1;
    bool err = false;


    do {
        err = false;
        cout << "Please enter a positive number (> 0): ";
        cin >> num;
        if (num <= 0) {
            err = true;
            cout << "ERR | The number must be greater that 0 (> 0). Try again." << endl;
        }
    } while (err);


    /** V1 */
    cout << "\n=========V1=========" << endl;
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    /** V2 */
    cout << "\n=========V2=========" << endl;
    for (int i=0; i<num; i++) {
        for (int j=-1; j<i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    /** V3 */
    cout << "\n=========V3=========" << endl;
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            /* if (j < (i+1)) cout << "*";
            else cout << (j+1); */
           (j < (i+1))? cout << "*" : cout << (j+1);
        }
        cout << "\n";
    }

    return 0;
}
