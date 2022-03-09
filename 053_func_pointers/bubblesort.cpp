#include <iostream>

using namespace std;

const int N = 10;


void my_swap(int arr[], int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int maggiore(int a, int b) {
    return (a>b)? 1:0;
}

int minore(int a, int b) {
    return (a<b)? 1:0;
}

void bubblesort(int arr[], int n, int (*pf)(int, int)) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i=1; i<n; i++) {
            if ((*pf)(arr[i-1], arr[i])) {
                my_swap(arr, i-1, i);
                swapped = 1;
            }
        }
    }
}


int main() {
    int arr[N] = {1,6,7,4,8,3,1,9,10,-6};
    int ord = -1;

    do {
        cout << "Enter 0 for ASC or 1 for DESC: ";
        cin >> ord;
        if (ord != 0 && ord != 1) cout << "ERR | The value must be 0 or 1. Try again" << endl;
    } while (ord != 0 && ord != 1);

    switch(ord) {
        case 0:
            bubblesort(arr, N, maggiore);
            break;
        case 1:
            bubblesort(arr, N, minore);
            break;
        default:
            cout << "NP" << endl;
    }

    cout << "ARR [ ";
    for (int i=0; i<N; i++) {
        cout << arr[i] << ",";
    }
    cout << "\b ]" << endl;
}
