/* Obiettivo:
    Scrivere un programma che chieda all’utente di inserire i valori di una matrice 4x4 e trovi la riga e la colonna con
    somma più alta.
*/

#include <iostream>

#define DIM 4

using namespace std;

void input_matrix(int mat[DIM][DIM]);
void print_matrix(int mat[DIM][DIM]);
void print_array(int arr[], int n);
int get_index_of_max(int arr[], int n);

int main() {

    cout << "This program ... " << endl;
    cout << "=========================" << endl;

    int mat[DIM][DIM];
    input_matrix(mat);
    cout << "\nMATRIX" << endl;
    print_matrix(mat);

    int sum_rows[DIM]={0}, sum_cols[DIM]={0};
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            sum_rows[i] += mat[i][j];
            sum_cols[j] += mat[i][j];
        }
    }

    cout << "\nARRAY SOMMA NELLE RIGHE: ";
    print_array(sum_rows, DIM);
    cout << "ARRAY SOMMA NELLE COLONNE: ";
    print_array(sum_cols, DIM);

    int r_max = get_index_of_max(sum_rows, DIM);
    int c_max = get_index_of_max(sum_cols, DIM);

    cout << "=============================" << endl;
    cout << "The row with the maximum sum has index " << r_max << " (starting from 0)." << endl;
    cout << "The column with the maximum sum has index " << c_max << " (starting from 0)." << endl;

    return 0;
}

int get_index_of_max(int arr[], int n) {
    int index_max = 0, max_value = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] > max_value) {
            index_max = i;
            max_value = arr[i];
        }
    }
    return index_max;
}

void input_matrix(int mat[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << "Enter the element (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
}

void print_matrix(int mat[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_array(int arr[], int n) {
    cout << "[ ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\b\b ];" << endl;
}
