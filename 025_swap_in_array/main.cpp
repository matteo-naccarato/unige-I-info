/* Obiettivo:

*/

#include <iostream>

using namespace std;

void swapMinMax(float arr[], int n);
void getMinMaxIndexes(float arr[], int n, int& min_index, int& max_index);
void printArray(float arr[], int n);

int main() {

    cout << "This program ..." << endl;
    cout << "========================" << endl;

    int n;
    do {
        cout << "Enter N: ";
        cin >> n;
        if (n < 0) {
            cout << "ERR | The length of the array must be positive. Try again" << endl;
        }
    } while(n < 0);


    float arr[n];

    for (int i=0; i<n; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }

    cout << "Array before swap: ";
    printArray(arr, n);

    swapMinMax(arr, n);


    cout << "Array after swap: ";
    printArray(arr, n);

    return 0;
}

void swapMinMax(float arr[], int n) {
    int min_index = 0, max_index = 0;

    getMinMaxIndexes(arr, n, min_index, max_index);

    float temp = arr[min_index];
    arr[min_index] = arr[max_index];
    arr[max_index] = temp;
}

void getMinMaxIndexes(float arr[], int n, int& min_index, int& max_index) {
    float min_value = arr[0], max_value = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] < min_value) {
            min_index = i;
            min_value = arr[i];
        }
        if (arr[i] > max_value) {
            max_index = i;
            max_value = arr[i];
        }
    }
}

void printArray(float arr[], int n) {
    cout << "[ ";
    for (int i=0; i<n-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << " ]" << endl;
}
