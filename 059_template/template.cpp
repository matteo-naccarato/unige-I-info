/*
Si scriva il template di funzione C++ contaDistinti che riceva come parametri un array a di elementi di tipo T
e la sua dimensione n (un numero intero), calcoli e restituisca come valore di ritorno il numero di elementi
distinti contenuti nell’array a (un numero intero).

Si scriva quindi un programma per verificare il corretto funzionamento del template di funzione.
Il programma chiederà all’utente di inserire da tastiera i valori per un array di 10 numeri interi, per un array
di 10 numeri reali e per una stringa contenente al massimo 9 caratteri, chiamerà contaDistinti per ciascuno
dei tre array e stamperà a video i tre valori di ritorno. Tali operazioni potranno essere ripetute finché
l’utente lo desidera.

Nota: per conoscere la dimensione effettiva della stringa inserita dall’utente, si può usare la funzione strlen
disponibile nella libreria cstring.

Esempio: dato l’array a = {1, 3, 5, 6, 5, 2, 1, 5, 3, 6} (n = 10), la funzione restituirà 5. L’array a contiene cioè 5
valori distinti (per la precisione si tratta dei valori: 1, 2, 3, 5, 6).

Estendere il template di funzione contaDistinti in modo che riceva come parametro un ulteriore
array f di numeri reali, della stessa dimensione dell’array a. La funzione assegnerà a ciascun elemento di f la
frequenza del corrispondente elemento di a. La frequenza di un elemento di un array è definita come il numero
di volte in cui l’elemento compare nell’array diviso per la dimensione dell’array. Nel caso dell’esempio di prima,
l’array f sarà dunque il seguente:

    f = {0.2, 0.2, 0.3, 0.2, 0.3, 0.1, 0.2, 0.3, 0.2, 0.2}.
L’elemento 1 compare cioè 2 volte su 10, l’elemento 3 compare 2 volte su 10, l’elemento 5 compare 3 volte su
10 e così via.
*/

#include <iostream>

using namespace std;

const int MIN_ARR = 1;
const int MAX_ARR = 1024;

const int UNIQ_TYPES = 3;
const int UNIQ_INT_INDEX = 0;
const int UNIQ_FLOAT_INDEX = 1;
const int UNIQ_CHAR_INDEX = 2;
const char* DESC_INT = "integers";
const char* DESC_FLOAT = "reals";
const char* DESC_CHAR = "characters";


struct Seen_element {
    int value;
    int occurences_indexes[MAX_ARR];
    int cnt;
};


template <typename T>
void input_arr(T* arr, int n, char* str) {
    cout << "\n======================\nINPUT for array of " << str << ":" << endl;
    for (int i=0; i<n; i++) {
        cout << "\t#" << i << ": ";
        cin >> arr[i];
    }
}


/* V2 */
template <typename T>
int contaDistinti2(T* arr, int n, float* freq_array) {
    Seen_element* seen_els = new Seen_element[n];
    if (seen_els == 0) {
        cout << "ERR | new Seen_element[]" << endl;
        return -1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<MAX_ARR; j++) {
            seen_els[i].occurences_indexes[j] = -1;
        }
        seen_els[i].cnt = 0;
    }

    int uniq_i = 0;
    for (int i=0; i<n; i++) {
        int unique_el = 1;
        for (int j=0; j<uniq_i; j++) {
            if (arr[i] == seen_els[j].value) {
                unique_el = 0;
                seen_els[j].occurences_indexes[seen_els[j].cnt] = i;
                seen_els[j].cnt++;
            }
        }
        if (unique_el) {
            seen_els[uniq_i].value = arr[i];
            seen_els[uniq_i].occurences_indexes[seen_els[uniq_i].cnt] = i;
            seen_els[uniq_i].cnt++;
            uniq_i++;
        }
    }

    for (int i=0; i<uniq_i; i++) {
        int j_occ = 0;
        while (seen_els[i].occurences_indexes[j_occ] >= 0) {
            freq_array[seen_els[i].occurences_indexes[j_occ]] = (float) seen_els[i].cnt/n;
            j_occ++;
        }
    }

    delete[] seen_els;

    return uniq_i;
}

/* V1 */
template <typename T>
int contaDistinti1(T* arr, int n) {
    T* seen_els = new T[n];
    if (seen_els == 0) {
        cout << "ERR | new T[]" << endl;
        return -1;
    }

    int uniq_i = 0;
    for (int i=0; i<n; i++) {
        int unique_el = 1;
        for (int j=0; j<uniq_i; j++) {
            if (arr[i] == seen_els[j])
                unique_el = 0;
        }
        if (unique_el) {
            seen_els[uniq_i] = arr[i];
            uniq_i++;
        }
    }

    delete[] seen_els;

    return uniq_i;
}


template <typename T>
void print_array(T* arr, int n, const char* str) {
    cout << str << " = [ ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ";";
    }
    cout << "\b ]" << endl;
}



int main() {

    int n = -1;
    do {
        cout << "Enter the dim of the arrays: ";
        cin >> n;
        if (n<MIN_ARR || n>MAX_ARR) {
            cout << "ERR | value not valid." << endl;
        }
    } while (n < 1);

    int* arr_int = new int[n];
    if (arr_int == 0) {
        cout << "ERR | new int[]" << endl;
        return -1;
    }
    float* arr_float = new float[n];
    if (arr_float == 0) {
        cout << "ERR | new float[]" << endl;
        return -1;
    }
    char* arr_char = new char[n];
    if (arr_char == 0) {
        cout << "ERR | new char[]" << endl;
        return -1;
    }


    /* INPUT */
    input_arr(arr_int, n, (char*) DESC_INT);
    input_arr(arr_float, n, (char*) DESC_FLOAT);
    input_arr(arr_char, n, (char*) DESC_CHAR);

    /* ELEB#1 */
    // CNT_UNIQ = [ cnt_int, cnt_float, cnt_char ]
    const char* CNT_ARRAY_DESC[UNIQ_TYPES] = {DESC_INT, DESC_FLOAT, DESC_CHAR};
    int cnt_uniq[UNIQ_TYPES];
    cnt_uniq[UNIQ_INT_INDEX] = contaDistinti1(arr_int, n);
    cnt_uniq[UNIQ_FLOAT_INDEX] = contaDistinti1(arr_float, n);
    cnt_uniq[UNIQ_CHAR_INDEX] = contaDistinti1(arr_char, n);

    /* OUTPUT#1 */
    cout << "==============OUTPUT1===========" << endl;
    for (int i=0; i<UNIQ_TYPES; i++) {
        cout << "Unique elements cnt for " << CNT_ARRAY_DESC[i] << ": " << cnt_uniq[i] << endl;
    }



    /* ELAB#2 */
    float** freq_array = new float*[UNIQ_TYPES];
    if (freq_array == 0) {
        cout << "ERR | new T[][]";
    }
    for (int i=0; i<UNIQ_TYPES; i++) {
        freq_array[i] = new float[n];
    }

    int cnts[UNIQ_TYPES];
    cnts[UNIQ_INT_INDEX] = contaDistinti2(arr_int, n, freq_array[UNIQ_INT_INDEX]);
    cnts[UNIQ_FLOAT_INDEX] = contaDistinti2(arr_float, n, freq_array[UNIQ_FLOAT_INDEX]);
    cnts[UNIQ_CHAR_INDEX] = contaDistinti2(arr_char, n, freq_array[UNIQ_CHAR_INDEX]);


    /* OUTPUT#2 */
    cout << "==============OUTPUT2===========" << endl;
    for (int i=0; i<3; i++) {
        cout << "\tUnique elements cnt for " << CNT_ARRAY_DESC[i] << ": " << cnt_uniq[i] << endl;
        cout << "\t";
        print_array(freq_array[i], n, (char*) "FREQUENCES");
        cout << "\n\n";
    }


    for (int i=0; i<UNIQ_TYPES; i++) {
        delete[] freq_array[i];
    }
    delete[] freq_array;


    delete[] arr_int;
    delete[] arr_float;
    delete[] arr_char;

    return 0;
}
