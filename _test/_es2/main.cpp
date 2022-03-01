#include <iostream>

using namespace std;

const int ROWS = 5;
const int COLS = 3;

int maggiori(int A[ROWS][COLS], int s, int v[], int n) {
    for (int i=0; i<n; i++) {
        v[i] = s;
    }

    int i_v = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            if (A[i][j] > s) {
                v[i_v] = A[i][j];
                i_v++;
            }
        }
    }

    return i_v;
}




int main()
{
    int A[ROWS][COLS] = {{2,4,2},{-3,5,-2},{-4,4,0},{8,2,5},{9,-1,6}};
    int n = ROWS*COLS;
    int v[n];
    int n_maggiori = maggiori(A, 3, v, n);

    cout << n_maggiori << endl;

    return 0;
}
