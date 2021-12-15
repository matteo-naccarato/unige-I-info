/* Obiettivo:
Un segnale audio (ad esempio un brano musicale) può essere rappresentato all’interno di un calcolatore come un array di n numeri reali compresi tra -1.0 e 1.0. Per valutarne l’intensità si può utilizzare la radice quadrata della media dei quadrati (Root Mean Square, RMS) degli elementi dell’array, definita come segue:

VEDI IMG x FORMULA

dove x1,x2,...,xn sono gli elementi dell’array. Si scriva in linguaggio C++ la funzione rms che riceva in ingresso (ovvero come parametri) un array x e la sua dimensione n, imposti a 1.0 gli elementi di x il cui valore è maggiore di 1.0 e a -1.0 gli elementi il cui valore è minore di -1.0, calcoli e restituisca come valore di ritorno RMS(x), un numero reale. Per il calcolo della radice quadrata si può usare la funzione di libreria sqrt.
*/

#include <iostream>
#include <cmath>

using namespace std;

float calc_rms(float x[], int n);

const int LEN_TEST_ARRAY = 4;

int main() {

    float arr[LEN_TEST_ARRAY] = {3, 0.5, -0.2, -1.1};
    float rms = calc_rms(arr, LEN_TEST_ARRAY);
    cout << "Il valore RMS e' " << rms << endl;

    return 0;
}

float calc_rms(float x[], int n) {
    float sommatoria = 0.0f;
    for (int i=0; i<n; i++) {
        x[i] = (x[i] > 1.0)? 1.0:x[i];
        x[i] = (x[i] < -1.0)? -1.0:x[i];
        sommatoria += pow(x[i], 2);
    }
    return sqrt(((float)1/n) * sommatoria);
}
