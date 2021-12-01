/* Obiettivo:

*/

#include <iostream>
#define DIM 3

using namespace std;

void input_mat(int mat[DIM][DIM]);
void print_mat(int mat[DIM][DIM]);
void mul_mat(int res[DIM][DIM], int mat_a[DIM][DIM], int mat_b[DIM][DIM]);



// fare DIM => DIM_MAX => chiedere la dim delle matrici in input (controllare che le dim siano accettabili e poi scorrere le matrici solo fino a riga e colonna data in input)





int main() {

    cout << "This program ...." << endl;
    cout << "==============================" << endl;

    int mat_a[DIM][DIM];
    int mat_b[DIM][DIM];
    int mat_res[DIM][DIM];


    // fare upgrade => vedi testa


    input_mat(mat_a);
    input_mat(mat_b);

    cout << "===============================" << endl;
    cout << "MATRIX A: " << endl;
    print_mat(mat_a);
    cout << "\b * ";
    cout << "===============================" << endl;
    cout << "MATRIX B: " << endl;
    print_mat(mat_b);

    mul_mat(mat_res, mat_a, mat_b);
    cout << "===============================" << endl;
    cout << "MUL MATRIX: " << endl;
    print_mat(mat_res);

    return 0;
}

void mul_mat(int res[DIM][DIM], int mat_a[DIM][DIM], int mat_b[DIM][DIM]) {
    int el_mat = 0;
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            el_mat = 0;
            for (int k=0; k<DIM; k++) {
                el_mat += mat_a[i][k] * mat_b[k][j];
            }
            res[i][j] = el_mat;
        }
    }
}

void input_mat(int mat[DIM][DIM]) {
    cout << "Enter MATRIX: " << endl;
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << "Enter the element (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
}

void print_mat(int mat[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        cout << "|";
        for (int j=0; j<DIM; j++) {
            cout << " " << mat[i][j] << " ";
        }
        cout << "|\n";
    }
}
