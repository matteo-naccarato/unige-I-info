/* Obiettivo:
Una matrice M è formata da n x m numeri interi, ognuno dei quali può valere soltanto 0, 1 o 3. La riga i-esima della matrice rappresenta i punti acquisiti dalla i-esima squadra di calcio nelle partite disputate nelle diverse giornate di un campionato. Il campionato comprende, quindi, n squadre e m giornate. In particolare, l'elemento M[i][k] denota il numero di punti conquistati dalla squadra i nella k-esima giornata. Scrivere in linguaggio C++ la funzione capolista che riceva in ingresso, ovvero come parametro, la matrice M (che si suppone avere 20 righe e 38 colonne) e un numero intero k tale che 0 <= k < m e restituisca come valore di ritorno l’indice della squadra prima classificata alla k-esima giornata (un numero intero). Nel caso in cui sia k >= n, la funzione restituisce -1.
*/
#include <iostream>

using namespace std;

const int n = 20, cols = 38;

int main() {


    return 0;
}

int capolista(int m[n][cols], int k) {
    if (k >= n) return -1;

    int punti_squadre[n] = {0};
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            punti_squadre[i] += m[i][j];
        }
    }

    int max_value = punti_squadre[0];
    int max_index = 0;
    for (int i=0; i<n; i++) {
        if (punti_squadre[i] > max_value) {
            max_value = punti_squadre[i];
            max_index = i;
        }
    }

    return index_cap;
}
