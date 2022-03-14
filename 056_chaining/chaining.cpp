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
    int* arr = new int[na+nb];
}



int main() {




    int* rt_arr = append();

    delete[] rt_arr;

    return 0;
}