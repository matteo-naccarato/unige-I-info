/* Obiettivo:
    Creare un programma che, dopo aver chiesto all’utente di inserire la dimensione e gli elementi di un array, lo
    inverta e stampi il risultato finale. Utilizzare una funzione per l’inversione dell’array
*/

#include <iostream>

using namespace std;

int getDimArray();
void inputElsArray(int arr[], int n);
void printArray(int arr[], int n);
void reverseArray(int arr[], int n);

int main() {

    cout << "This program reverses an array." << endl;
    cout << "=============================" << endl;

    int n = getDimArray();
    cout << "INPUT array ..." << endl;
    int arr[n];
    inputElsArray(arr, n);
    cout << "Entered array:\t";
    printArray(arr, n);

    reverseArray(arr, n);

    cout << "Reversed array:\t";
    printArray(arr, n);
    return 0;
}

void reverseArray(int arr[], int n) {
    int temp;
    for (int i=0; i<n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
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

void inputElsArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i=0; i<n-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << "]" << endl;
}

