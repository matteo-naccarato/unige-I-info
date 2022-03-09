#include <iostream>

using namespace std;

const int MIN_N = 0;
const int MAX_N = 256;


void my_swap(int arr[], int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int maggiore(int a, int b) {
    return (a>b)?1:0;
}

int minore(int a, int b) {
    return (a<b)?1:0;
}

void bubblesort(int arr[], int n, int (*fp)(int, int)) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i=1; i<n; i++) {
            if ((*fp)(arr[i-1], arr[i])) {
                my_swap(arr, i-1, i);
                swapped = 1;
            }
        }
    }
}




int main() {

    int n=-1, ord=-1;
    int err = -1;
    do {
        err = 0;
        cout << "Enter the number of elements of the array: ";
        cin >> n;
        if (n < MIN_N || n > MAX_N) {
            cout << "ERR | The entered value is not valide (it must be greater than " << MIN_N << " and lower than " << MAX_N << ". Try again." << endl;
            err = 1;
        }
    } while (err);


    int* arr = new int[n];
    if (arr == 0) return -1;

    cout << "Now u can enter the elements of the array:\n";
    for (int i=0; i<n; i++) {
        cout << "#" << i << " element: "; 
        cin >> arr[i]; 
    }

    do {
        err = 0;
        cout << "\nEnter 0:DESC or 1:ASC: ";
        cin >> ord;
        if (ord != 0 && ord != 1) {
            err = 1;
            cout << "Input not valid. Try again." << endl;
        }
    } while (err);
    cout << "=========== INPUT TERMINATED ===============" << endl;


    cout << "=========== BUBBLE SORT STARTED ===============" << endl;
    switch (ord) {
        case 0:
            bubblesort(arr, n, minore);
            break;
        case 1:
            bubblesort(arr, n, maggiore);
            break;
        default:
            cout << "ERR" << endl;
    }
    cout << "=========== BUBBLE SORT TERMINATED ===============" << endl;


    cout << "SORTED ARR [ ";
        for (int i=0; i<n; i++) {
            cout << arr[i] << ",";
        }
        cout << "\b ]" << endl;

    return 0;
}
