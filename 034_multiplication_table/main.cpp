/* Obiettivo:
    Memorizzare in un array bidimensionale 10 x 10 la tavola pitagorica, (quella delle tabelline!), e stampare il
    contenuto della matrice (nella prima riga si dovrà trovare la tabellina del 1: 1 2 3 4 5 6 7 8 9 10).
*/

#include <iostream>

#define DIM 10

using namespace std;

void print_mat(int mat[DIM][DIM]);

int main() {

    cout << "This program prints the multiplication (from 1 to 10)." << endl;
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
