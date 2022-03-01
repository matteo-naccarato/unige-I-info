#include <iostream>

using namespace std;

const int N = 3;

int righe_negative(int a[N][N], int* neg_arr[]) {
    for (int i=0; i<N; neg_arr[i]=NULL, i++) {}

    int i_arr = 0;
    int sum_row = 0;
    for (int r=0; r<N; r++) {
        sum_row = 0;
        for (int c=0; c<N; sum_row += a[r][c], c++) {}
        if (sum_row < 0) {
            neg_arr[i_arr] = &a[r][0];
            i_arr++;
        }
    }
    return i_arr;
}

int main() {

    int a[N][N] = {0};
    int* neg_arr[N] = {0};

    cout << "Enter a matrix 3x3:\n" << endl;
    for (int r=0; r<N; r++) {
        cout << "ROW#" << r <<  endl;
        for (int c=0; c<N; c++) {
            cout << "\tCOL#" << c << ": ";
            cin >> a[r][c];
        }
    }

    int neg_arr_i = righe_negative(a, neg_arr);

    cout << "NEG_ARR = [ ";
    for (int i=0; i<neg_arr_i; i++) {
        cout << neg_arr[i] << ",";
    }
    cout << "\b ]" << endl;

    cout << "\n\n==== PUNTATORI RIGHE MATRICE ====" << endl;
    for (int r=0; r<N; r++) {
        cout << &a[r][0] << "\n";
    }
    return 0;
}
