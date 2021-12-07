/* Obiettivo:
    Creare un programma che, dopo aver chiesto all’utente di inserire la dimensione e gli elementi di due array, li
    moltiplichi tra di loro e stampi il risultato finale. Utilizzare una funzione per moltiplicare gli array.
*/

#include <iostream>

using namespace std;

int getDimArray();
void inputElsArray(int arr[], int n);
void printArray(int arr[], int n);
void mulArray(int arr1[], int arr2[], int arrMul[], int nMul);


int main() {

    cout << "This program calculates the multiplication of two arrays." << endl;
    cout <<  "==================" << endl;

    int n1 = getDimArray(), n2 = getDimArray();
    int arr1[n1], arr2[n2];
    cout << "===========================" << endl;
    cout << "Input ARR#1" << endl;
    inputElsArray(arr1, n1);
    cout << "\nInput ARR#2" << endl;
    inputElsArray(arr2, n2);

    cout << "===========================" << endl;
    cout << "ARR#1:\t\t";
    printArray(arr1, n1);
    cout << "ARR#2:\t\t";
    printArray(arr2, n2);

    int nMul = min(n1, n2);
    int arrMul[nMul];

    mulArray(arr1, arr2, arrMul, nMul);
    cout << "ARR#MUL:\t";
    printArray(arrMul, nMul);

    return 0;
}

void mulArray(int arr1[], int arr2[], int arrMul[], int nMul) {
    for (int i=0; i<nMul; i++) {
        arrMul[i] = arr1[i] * arr2[i];
    }
}

void inputElsArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
}

int getDimArray() {
    int n;
    do {
        cout << "Enter the dim of the array: ";
        cin >> n;
        if (n <= 0)
            cout << "ERR | The dim of the array must be positive. Try again." << endl;
    } while(n <= 0);
    return n;
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i=0; i<n-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << "]" << endl;
}
