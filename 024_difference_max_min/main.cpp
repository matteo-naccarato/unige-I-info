/* Obiettivo:

*/

#include <iostream>
#define N 3

using namespace std;


void get_min_max(float[], float& min_n, float& max_n);

int main() {

    cout << "This program ...." << endl;
    cout << "=====================" << endl;

    float arr[N];
    float min_n, max_n, differenceMaxMin = 0.f;
    for (int i=0; i<N; i++) {
        cout << "Enter. ..: ";
        cin >> arr[i];
    }

    get_min_max(arr, min_n, max_n);

    differenceMaxMin = max_n - min_n;

    cout << "The ...(" << max_n << " - " << min_n << ") is: " << differenceMaxMin << endl;


    return 0;
}

void get_min_max(float arr[], float& min_n, float& max_n) {

    min_n = arr[0];
    max_n = arr[0];
    for (int i=1; i<N; i++) {
        if (arr[i] < min_n) min_n = arr[i];
        if (arr[i] > max_n) max_n = arr[i];
    }
}
