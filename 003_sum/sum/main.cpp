// Obiettivo:
//  Creare un programma in c++ che chieda all’utente di immettere due interi, sommi
//      questi numeri tra di loro e stampi a terminale la somma

/*
#include <iostream>
    -> direttiva per il preprocessore (includere il contenuto del file iostream (copia/incolla)
    -> librerie standard di I/O (stream => canale di informazioni verso l'esterno)
*/
#include <iostream>

/*
namespace: serve per evitare conflitti
*/
using namespace std;

int main() {
    /*
    cout => stampare a schermo
    cin  => prendere in input dei valori
    cerr => stampare errori
    <<   => operatore per l'inserimento
    endl => "\n" + assicurarsi che il buffer in uscita venga scaricato
    */

    int num1 = 0, num2 = 0, sum = 0;

    // se non avessi messo "using namespace std" => std::cout <<
    cout << "This program will sum two integer numbers ..." << endl;
    cout << "=============================" << endl;
    cout << "Insert the first INTEGER number: " << endl;
    cin >> num1;
    cout << "Great! Now insert the second INTEGER number: " << endl;
    cin >> num2;
    cout << "=============================" << endl;

    sum = num1 + num2;
    cout << "The result of (" << num1 << " + " << num2 << ") is: (" << sum << ")" << endl;

    return 0;
}
