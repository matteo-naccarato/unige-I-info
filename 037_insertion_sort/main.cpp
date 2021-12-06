/* Obiettivo:
    Provare a scrivere un programma che implementi l’ordinamento di un array con algoritmo Insertion Sort.
    L’Insertion Sort è un algoritmo di ordinamento che utilizza lo stesso metodo che un essere umano usa per
    ordinare le sue carte in mano.
    L’algoritmo ha bisogno di due cicli for, uno più esterno su tutti gli elementi dell’array, quello più interno per
    calcolare il nuovo indice in cui inserire l’elemento.
    Il passo successivo consiste nel far scorrere in avanti gli elementi dell’array, e inserire finalmente l’elemento nella
    posizione «corretta»
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#define MIN_NUM 0
#define MAX_NUM 99

using namespace std;

int input_dim_array();
void input_rand_array(int arr[], int n);
void print_array(int arr[], int n);
void insertion_sort(int arr[], int n);

int main() {

    cout << "This program implements the insertion sort." << endl;
    cout << "====================================" << endl;

    int n = input_dim_array();
    int arr[n];
    input_rand_array(arr, n);
    cout << "RANDOM ARRAY: " << endl;
    print_array(arr, n);

    insertion_sort(arr, n);

    cout << "\nSORTED ARRAY: " << endl;
    print_array(arr, n);

    return 0;
}

void insertion_sort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int insertion_point = i;
        int temp = arr[i];
        for (int j=i-1; j>=0; j--) {
            if (arr[j] > arr[i]) {
                insertion_point = j;
            }
        }
        for (int j=i-1; j>=insertion_point; j--) {
            arr[j+1] = arr[j];
        }
        arr[insertion_point] = temp;
    }
}

void input_rand_array(int arr[], int n) {
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        arr[i] = rand()%(MAX_NUM - MIN_NUM + 1);
    }
}

int input_dim_array() {
    int n;
    do {
        cout << "Enter the dim of the array: ";
        cin >> n;
        if (n < 1) {
            cout << "ERR | The dim of the array must be positive. Try again." << endl;
        }
    } while(n < 1);
    return n;
}

void print_array(int arr[], int n) {
    cout << "[ ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\b\b" << " ]" << endl;
}
