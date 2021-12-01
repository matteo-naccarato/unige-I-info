/* Obiettivo:

*/

#include <iostream>

#define DIM 10

using namespace std;

void print_mat(int mat[DIM][DIM]);

int main() {

    cout << "This program ..." << endl;
    cout << "=======================" << endl;

    int mul_table[DIM][DIM];
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            mul_table[i][j] = (i+1)*(j+1);
        }
    }

    cout << "MATRIX:" << endl;
    print_mat(mul_table);

    return 0;
}

void print_mat(int mat[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        cout << "|";
        for (int j=0; j<DIM; j++) {
            cout << " " << mat[i][j] << "\t";
        }
        cout << "|\n";
    }
}
