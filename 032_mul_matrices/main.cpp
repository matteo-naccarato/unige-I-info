/* Obiettivo:
    Creare un programma che chieda all’utente di inserire gli elementi di due matrici quadrate di dimensione 3, e ne
    calcoli il prodotto
*/

#include <iostream>
#define MAX_DIM 100

using namespace std;

int input_dim_matrix(int max_dim);
void input_mat(int mat[MAX_DIM][MAX_DIM], int actual_dim);
void print_mat(int mat[MAX_DIM][MAX_DIM], int actual_dim);
void mul_mat(int res[MAX_DIM][MAX_DIM], int mat_a[MAX_DIM][MAX_DIM], int mat_b[MAX_DIM][MAX_DIM], int actual_dim);

int main() {

    cout << "This program calculates the multiplication of two matrices" << endl;
    cout << "==============================" << endl;

    int mat_a[MAX_DIM][MAX_DIM];
    int mat_b[MAX_DIM][MAX_DIM];
    int mat_res[MAX_DIM][MAX_DIM];

    int dim = input_dim_matrix(MAX_DIM);

    input_mat(mat_a, dim);
    input_mat(mat_b, dim);

    cout << "===============================" << endl;
    cout << "MATRIX A: " << endl;
    print_mat(mat_a, dim);
    cout << "\b * ";
    cout << "===============================" << endl;
    cout << "MATRIX B: " << endl;
    print_mat(mat_b, dim);

    mul_mat(mat_res, mat_a, mat_b, dim);
    cout << "===============================" << endl;
    cout << "MUL MATRIX: " << endl;
    print_mat(mat_res, dim);

    return 0;
}

void mul_mat(int res[MAX_DIM][MAX_DIM], int mat_a[MAX_DIM][MAX_DIM], int mat_b[MAX_DIM][MAX_DIM], int actual_dim) {
    int el_mat = 0;
    for (int i=0; i<actual_dim; i++) {
        for (int j=0; j<actual_dim; j++) {
            el_mat = 0;
            for (int k=0; k<actual_dim; k++) {
                el_mat += mat_a[i][k] * mat_b[k][j];
            }
            res[i][j] = el_mat;
        }
    }
}

int input_dim_matrix(int max_dim) {
    int dim = -1;
    do {
        cout << "Enter the dimension of the matrix: ";
        cin >> dim;
        if (dim <= 0 || dim > max_dim) {
            cout << "ERR | The dimension of the matrix is wrong. It must be positive and less/equals than/to " << max_dim << ". Try again." << endl;
        }
    } while (dim <= 0 || dim > max_dim);
    return dim;
}

void input_mat(int mat[MAX_DIM][MAX_DIM], int actual_dim) {
    cout << "Enter MATRIX: " << endl;
    for (int i=0; i<actual_dim; i++) {
        for (int j=0; j<actual_dim; j++) {
            cout << "Enter the element (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
}

void print_mat(int mat[MAX_DIM][MAX_DIM], int actual_dim) {
    for (int i=0; i<actual_dim; i++) {
        cout << "|";
        for (int j=0; j<actual_dim; j++) {
            cout << " " << mat[i][j] << " ";
        }
        cout << "|\n";
    }
}
