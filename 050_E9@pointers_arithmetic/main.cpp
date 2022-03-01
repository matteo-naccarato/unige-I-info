#include <iostream>

using namespace std;

const int DIM = 20;

int main() {

    int a[DIM];
    for (int* i=a; (i-a)<DIM; i++) {
        *i = 0;
    }

    // OPPURE
    /*
    for (int* p=a; p < (a + DIM); p++) { *p = ...; }
    */

    int n = 0;
    do {
        cout << "Enter a number between 3 and 5: ";
        cin >> n;
        if (n < 3 || n > 5) {
            cout << "WARN | the number must be between 3 and 5. Try again" << endl;
        }
    } while (n < 3 || n > 5);


    for (int* i=a+n; i < (a + DIM); i+=n) {
        *i = 1;
    }

    cout << "a = [ ";
    for (int* i=a; (i-a)<DIM; i++) {
        cout << *i << ",";
    }
    cout << "\b ]" << endl;



    // int => 32 bit;
    // char => 8 bit;
    for (char* pc=(char*)a; pc < (char*)(a + DIM); pc += 4) { // corretto: si sposta sempre di 4*8=32bit bit (come se fosse int*)
        *pc = 10;
    }
    cout << "[ ";
    for (int* i=a; (i-a)<DIM; i++) {
        cout << *i << ",";
    }
    cout << "\b ]" << endl;



    for (char* pc=(char*)a; pc < (char*)(a + DIM); pc +=2) { // differente: ci si sposta nei bit dello stesso numero (2*8=16bit)
        *pc = 5;
    }
    cout << "[ ";
    for (int* i=a; (i-a)<DIM; i++) {
        cout << *i << ",";
    }
    cout << "\b ]" << endl;



    return 0;
}
