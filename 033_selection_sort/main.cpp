/* Obiettivo:

*/

#include <iostream>
#include <cstdlib> // rand()%(MAX_NUM - MIN_NUM + 1)
#include <ctime> // srand(time(NULL))

#define MIN_NUM -99
#define MAX_NUM 99

using namespace std;

int input_dim_array();
void input_array(int arr[], int n);
void input_rand_array(int arr[], int n);
void print_array(int arr[], int n);
void selection_sort(int arr[], int n);
void swap_in_array(int arr[], int i1, int i2);
int get_index_of_min(int arr[], int start, int stop);


int main() {

    cout << "This program ..." << endl;
    cout << "=============================" << endl;

    int n = input_dim_array();
    int arr[n];
    // input_array(arr, n);
    input_rand_array(arr, n);
    cout << "ARRAY: ";
    print_array(arr, n);


    selection_sort(arr, n);
    cout << "SORTED ARRAY: ";
    print_array(arr, n);


    return 0;
}

void selection_sort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int min_to_swap = get_index_of_min(arr, i, n);
        swap_in_array(arr, i, min_to_swap);
    }
}

void swap_in_array(int arr[], int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int get_index_of_min(int arr[], int start, int stop) {
    int min_index = start;
    for (int i=start+1; i<stop; i++) {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    return min_index;
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

void input_array(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << "Enter number at index " << i << ": ";
        cin >> arr[i];
    }
}

void input_rand_array(int arr[], int n) {
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        arr[i] = rand()%(MAX_NUM - MIN_NUM + 1);
    }
}

void print_array(int arr[], int n) {
    cout << "[ ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\b\b" << " ]" << endl;
}
