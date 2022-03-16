/*
Si scriva la funzione C++ append che concateni due array di numeri interi ordinati in senso crescente. La funzione
riceve come parametri i puntatori a due array di numeri interi pa e pb e le loro dimensioni na e nb (due numeri
interi) e restituisce come valore di ritorno il puntatore a un array di numeri interi. Si suppone che gli array puntati
da pa e pb siano già ordinati in senso crescente. La funzione allocherà dinamicamente un array di (na + nb)
elementi e vi copierà gli elementi degli array puntati da pa e pb in modo tale che l’array risultante sia a sua volta
ordinato in senso crescente. La funzione restituirà infine il puntatore all’array risultante. Sarà responsabilità del
programma chiamante deallocare la memoria allocata dalla funzione.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà
all’utente di immettere da tastiera le dimensioni nx e ny di due array di numeri interi, allocherà dinamicamente gli 
array e chiederà all’utente di inserire i valori per entrambi gli array. Il programma utilizzerà quindi l’algoritmo
BubbleSort per ordinare entrambi gli array, chiamerà la funzione append e stamperà a video l’array concatenato
risultante. Perché è più efficiente utilizzare la funzione append piuttosto che copiare semplicemente gli elementi
dei due array di partenza nell’array risultante e poi utilizzare nuovamente BubbleSort sull’array risultante?

Esempio: se l’array puntato da pa è {1, 3, 5, 6, 8} (na = 5) e l’array puntato da pb è {2, 4, 10} (nb = 3), l’array
concatenato risultante sarà {1, 2, 3, 4, 5, 6, 8, 10}.

Per fare di più: scrivere una funzione check che riceva come parametri il puntatore pa ad un array di numeri interi
e la dimensione n dell’array (un numero intero) e restituisca come valore di ritorno 1 se l’array è ordinato e 0
altrimenti. Per verificare il corretto funzionamento della funzione append, chiamare la funzione check passandole
l’array restituito dalla funzione append e stampare a video il suo risultato (che, se append funziona correttamente,
dovrebbe essere 1).
*/

#include <iostream>

using namespace std;


int* append(int* pa, int* pb, int na, int nb) {
    int* rt_arr = new int[na+nb];
    if (rt_arr != 0) {

        int ia=0, ib=0, irt=0;
        while (ia<na && ib<nb) {
            if (*(pa+ia) < *(pb+ib)) {
                *(rt_arr+irt) = *(pa+ia);
                ia++;
            } else {
                *(rt_arr+irt) = *(pb+ib);
                ib++;
            }
            irt++;
        }
        while (ia<na) {
            *(rt_arr+irt) = *(pa+ia);
            ia++;
            irt++;
        }
        while(ib<nb) {
            *(rt_arr+irt) = *(pb+ib);
            ib++;
            irt++;
        }
    }

    return rt_arr;
}

int input_length(char* str) {
    int n = -1;
    int err = -1;
    do {
        err = 0;
        cout << "Enter the length of array " << str << ": ";
        cin >> n;
        if (n<1) {
            cout << "ERR | value not valid" << endl;
            err = 1;
        }

    } while (err);
    return n;
}

void input_array(int* arr, int n, char* str) {
    cout << "input for array " << str << endl;
    for (int* pi=arr; pi-arr < n; pi++) {
        cout << "\t#" << (pi-arr) << ": ";
        cin >> *pi;
    }
}

void print_array(int* arr, int n, char* str) {
    cout << str << " = [ ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ",";
    }
    cout << "\b ]" << endl;
}

void bubblesort(int* arr, int n) {
    int temp;
    int swapped = 1;
    for (int i=n-1; i>0 && swapped; i--) {
        swapped = 0;
        for (int j=0; j<i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
    }
}



int main() {
    
    int na=-1, nb=-1;
    na = input_length((char*)"A");
    nb = input_length((char*)"B");

    cout << endl;

    int* ra = new int[na];
    if (ra == 0) return -2;
    int* rb = new int[nb];
    if (rb == 0) return -2;
    input_array(ra, na, (char*)"A");
    input_array(rb, nb, (char*)"B");

    print_array(ra, na, (char*)"A");
    print_array(rb, nb, (char*)"B");


    bubblesort(ra, na);
    bubblesort(rb, nb);

    cout << "=============Sorted arrays=================" << endl;
    print_array(ra, na, (char*)"A");
    print_array(rb, nb, (char*)"B");
    cout <<  "==========================================" << endl;

    int* rt_arr = append(ra, rb, na, nb);
    if (rt_arr == 0) {
        cout << "ERR | malloc" << endl;
        return -1;
    }

    cout <<  "==========================================" << endl;
    print_array(rt_arr, na+nb, (char*)"RT_ARR");


    delete[] ra;
    delete[] rb;
    delete[] rt_arr;

    return 0;
}