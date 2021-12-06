/* Obiettivo:
    Creare un programma che chieda all’utente di inserire la dimensione di una matrice, la riempia con numeri
    random, la stampi e verifichi se la somma delle celle sopra la diagonale principale sia maggiore o minore della
    somma delle celle sotto la diagonale principale.
    Hint: Usando indici diversi di cicli for si possono calcolare le due somme
    N.B. Con le matrici, se la dimensione non è nota in fase di compilazione, non posso utilizzare funzioni. Vedremo
    poi alcune soluzioni con i puntatori che permettono di superare questo limite.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#define MIN_NUM 0
#define MAX_NUM 99

using namespace std;

int main()
{
    cout << "This program ..." << endl;
    cout << "===============================" << endl;

    int dim;
    do {
        cout << "Enter the dim of the square matrix: ";
        cin >> dim;
        if (dim <= 0) {
            cout << "ERR | The dim must be positive. Try again." << endl;
        }
    } while(dim<=0);

    int mat[dim][dim];
    srand(time(NULL));
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            mat[i][j] = rand()%(MAX_NUM - MIN_NUM + 1);
        }
    }

    cout << "\nMATRIX:" << endl;
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }


    int sum_sup = 0, sum_inf = 0;
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            if (i!=j) {
                if (j > i) {
                    sum_sup += mat[i][j];
                } else {
                    sum_inf += mat[i][j];
                }
            }
        }
    }

    cout << "\nSUP SUM: " << sum_sup << endl;
    cout << "INF SUM: " << sum_inf << endl;

    cout << "The sum of the elements above the diagonal is " << ((sum_sup < sum_inf)? "LOWER THAN" : (sum_sup == sum_inf)? "EQUALS TO" : "GREATER THAN") << " the sum of the lower part of the matrix" << endl;

    return 0;
}
