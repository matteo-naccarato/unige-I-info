#include <iostream>
#include <cmath>

using namespace std;
 
const int MIN_N = 1;
const int MAX_N = 100;

struct Return_values {
    double prodotto_scalare;
    double distanza;
};

Return_values prodotto_scalare_and_distanza(double* px, double* py, int n) {

    Return_values rt;
    rt.prodotto_scalare = 0;
    rt.distanza = 0;

    double sum = 0;
    double* ix, *iy;
    for (ix=px, iy=py; (ix-px)<n; ix++, iy++) {
        rt.prodotto_scalare += (*(ix)) * (*(iy)); 
        sum += (*(ix) - *(iy)) * (*(ix) - *(iy)); 
    }
    rt.distanza = sqrt(sum);

    return rt;
}

void input_array(double* px, int n) {
    for (double* i=px; i-px<n; i++) {
        cout << "\t#" << (i-px) << ": ";
        cin >> *i;
    }
}



int main() {
    
    int n = -1;
    int err = -1;
    do {
        err = 0;
        cout << "Inserire lunghezza vettori: ";
        cin >> n;
        if (n<MIN_N || n>MAX_N) {
            cout << "ERR | Not valid input" << endl;
            err = 1;
        }
    } while(err);


    double* arr_x = new double[n];
    if (arr_x == 0) {
        cout << "ERR | malloc x" << endl;
        return -1;
    } 
    double* arr_y = new double[n];
    if (arr_y == 0) {
        cout << "ERR | malloc y" << endl;
        return -1;
    } 


    cout << "INPUT ARRAY X:" << endl;
    input_array(arr_x, n);
    cout << "INPUT ARRAY Y:" << endl;
    input_array(arr_y, n);


    Return_values rt = prodotto_scalare_and_distanza(arr_x, arr_y, n);

    cout << "PRODOTTO SCALARE:\t" << rt.prodotto_scalare << endl;
    cout << "DISTANZA:\t\t" << rt.distanza << endl; 


    delete[] arr_x;
    delete[] arr_y;

    return 0;
}
