#include <iostream>
#include <ctime>

using namespace std;

const int MIN_DIM = 1;
const int MAX_DIM = 10;
const int MIN_NUM_RAND = 0;
const int MAX_NUM_RAND = 3;

// class Matrix {}


bool isSymmetrical(int** mat, int n, int m) {
    bool symm = true;
    for (int i=0; symm && i<n; i++) {
        for (int j=0; symm && j<i; j++) {
            if (mat[i][j] != mat[j][i])
                symm = false;
        }
    }
    return symm;
}

void genMatrix(int** mat, int n, int m) {
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            mat[i][j] = MIN_NUM_RAND + rand() % (MAX_NUM_RAND - MIN_NUM_RAND + 1);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            *(*(mat+i)+j) = MIN_NUM_RAND + rand() % (MAX_NUM_RAND - MIN_NUM_RAND + 1);
        }
        cout << endl;
    }

}

void printMatrix(int** mat, int n, int m) {
    cout << "\nMATRIX" << endl;
    // for (int i=0; i<n; i++) 
    for (int** i=mat; (i-mat)<n; i++) {
        for (int j=0; j<m; j++) {
            //cout << *( *(mat + i) + j) << " ";
            cout << *(*(mat + (i-mat)) + j) << " ";
        }
        cout << endl;
    }
}

int input_dim(char* str) {
    int n = -1;
    int err = -1;
    do {
        err = 0;
        cout << "Enter the dim of " << str << ": ";
        cin >> n;
        if (n < MIN_DIM || n > MAX_DIM) {
            err = 1;
            cout << "ERR | Value not valid." << endl;
        }
    } while (err);
    return n;
}

int main() {

    int n = input_dim((char*) "ROWS");
    int m = input_dim((char*) "COLUMNS");

    int** mat = new int*[n];
    if (mat == NULL) {
        cout << "ERR | new int[n]" << endl;
        return -1;
    }
    for (int i=0; i<n; i++) {
        mat[i] = new int[m];
        if (mat[i] == NULL) {
            cout << "ERR | new int[m]" << endl;
            return -1;
        }
    }

    genMatrix(mat, n, m);
    printMatrix(mat, n, m);

    cout << "The generated matrix " << ((isSymmetrical(mat, n, m))?"is":"isn't") << " symmetrical." << endl;
    

    for (int i=0; i<n; i++) {
        delete[] mat[i];
    }
    delete[] mat;



    return 0;
}