/*
Si scriva la funzione C++ swap che riceva come parametri i puntatori a tre numeri interi a, b e c e ne ruoti i valori,
ovvero: a b viene assegnato il valore di a, a c viene assegnato il valore di b e ad a viene assegnato il valore di c. Si
scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà
all’utente di immettere da tastiera tre numeri interi, chiamerà la funzione swap per ruotarne i valori e stamperà a
video il risultato.

Se non si volessero utilizzare i puntatori come si potrebbe re-implementare la funzione? Per verificarlo, scrivete
una funzione swap_2 che scambi i valori senza usare i puntatori e utilizzatela nel programma sviluppato.
*/
#include <iostream>

using namespace std;

void my_swap(int* pa, int* pb, int* pc) {
    int temp = *pb;
    *pb = *pa;
    *pa = *pc;
    *pc = temp;
}

void my_swap2(int& ra, int& rb, int& rc) {
    int temp_r = rb;
    rb = ra;
    ra = rc;
    rc = temp_r;
}

int main() {

    int a = 3;
    int b = 5;
    int c = 10;

    cout << "BEFORE\t{A,B,C} = {" << a << "," << b << "," << c << "}" << endl;
    my_swap(&a, &b, &c);
    cout << "AFTER 1\t{A,B,C} = {" << a << "," << b << "," << c << "}" << endl;

    my_swap2(a, b, c);
    cout << "AFTER 2\t{A,B,C} = {" << a << "," << b << "," << c << "}" << endl;

    return 0;
}
