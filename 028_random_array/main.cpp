/* Obiettivo:
    Creare un programma che, dopo aver chiesto all’utente di inserire la dimensione di un array, li riempia con interi
    random compresi tra 0 e 99
*/

#include <iostream>
#include <cstdlib> // rand()
#include <ctime> // srand(time(NULL)) ;; numero secondi trascorsi dal 1° gennaio 1970

#define MIN_NUM 0
#define MAX_NUM 99

using namespace std;

int main() {
    cout << "This program fills an array with random numbers." << endl;
    cout << "==========================" << endl;

    int n;
    do {
        cout << "Enter n: ";
        cin >> n;
        if (n < 0) {
            cout << "ERR | The length of the array must be positive. Try again." << endl;
        }
    } while(n < 0);


    int arr[n];

    srand(time(NULL));
    for (int i=0; i<n; i++) {
        arr[i] = rand()%(MAX_NUM - MIN_NUM + 1);
    }

    cout << "arr [";
    for (int i=0; i<n-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << "]" << endl;








    return 0;
}
