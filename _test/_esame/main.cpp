#include <iostream>

using namespace std;

const int n = 6;

void elabora(int a[], int b[], int n) {
    for (int i=0; i<n; i++) {
        int val = 1;
        for (int j=i; j>=0; j--) {
            val *= a[j];
        }
        b[i] = val;
    }
}


int main() {

    int a[n] = {5,1,2,-1,2,-2};
    int b[n];

    elabora(a, b, n);

    for (int i=0; i<n; i++) {
        cout << b[i] << endl;
    }
    return 0;
}
