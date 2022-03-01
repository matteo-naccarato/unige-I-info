#include <iostream>

using namespace std;

int main() {

    int a=0, b=0;
    int c1=0, c2=0, c3=0, c4=0;

    int& r = a; // riferimento (NON è un puntatore, è proprio la stessa cosa) a intero
    int* pa = &a, *pb = &b; // puntatori a intero
    int** ppa = &pa;

    const int* pca = &a;

    cout << "Inserire numero a: ";
    cin >> a;
    cout << "Inserire numero b: ";
    cin >> b;

    cout << "[*pa]: " << *pa << "\n" << "[*pb]: " << *pb << endl;
    cout << "==========================" << endl;

    cout << "[pa]: " << pa << "\n" << "[pb]: " << pb << endl;
    cout << "==========================" << endl;

    cout << "[*pa]: " << *pa << endl;
    cout << "==========================" << endl;

    cout << "[**pa]: " << **ppa << endl;
    cout << "==========================" << endl;

    cout << "[*pca]: " << *pca << endl;
    cout << "==========================" << endl;

    c1 = *pa;
    c2 = **ppa;
    c3 = *pca;
    c4 = r;

    cout << "[c1]: " << c1 << "\n"
            << "[c2]: " << c2 << "\n"
            << "[c3]: " << c3 << "\n"
            << "[c4]: " << c4 << endl;
    cout << "==========================" << endl;


    a += 3;
    cout << "[a]: " << a << endl;

    *pa += 3;
    cout << "[a]: " << a << endl;

    **ppa += 3;
    cout << "[a]: " << a << endl;

    r += 3;
    cout << "[a]: " << a << endl;
    cout << "==========================" << endl;



    a = c1; // valore iniziale immesso dall'utente
    pa = pb;
    a += 3;
    cout << "[a]: " << a << endl;
    *pa += 3;
    cout << "[a]: " << a << endl;
    **ppa += 3;
    cout << "[a]: " << a << endl;
    r += 3;
    cout << "[a]: " << a << endl;
    cout << "[b]: " << b << endl;
    cout << "==========================" << endl;


    // *pca += 5;

    return 0;
}
