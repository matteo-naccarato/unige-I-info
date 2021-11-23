/* Obiettivo:
    Il programma consente all'utente di inserire una frase, e stampa a terminale il numero totale di caratteri, di vocali e
    di consonanti.
    Ci viene in mente che abbiamo già realizzato in un’esercitazione (la seconda) un programma per verificare se una
    lettera è una consonante o una vocale, e che potremmo riutilizzare parte del codice già sviluppato usando il concetto
    di funzione.
*/

#include <iostream>

using namespace std;

int checkVowel(char);
int checkConsonant(char);

int main()
{
    cout << "This program ...." << endl;
    cout << "=================================" << endl;

    int cntConsonants = 0, cntVowels = 0, cntAll = 0;
    char ch = '\0';

    cout << "Enter a phrase and end it with '.'" << endl;
    while (ch != '.') {
        cin >> ch;
        cntAll++;
        if (checkVowel(ch)) {
            cntVowels++;
        } else cntConsonants += checkConsonant(ch);
    }

    cout << "=================================" << endl;
    cout << "All: " << cntAll << "\nVowels: " << cntVowels << "\nConsonants: " << cntConsonants << endl;

    return 0;
}


int checkVowel(char ch) {
    int ret = 0;
    switch (ch) {
       case 'a': ret = 1; break;
       case 'e': ret = 1; break;
       case 'i': ret = 1; break;
       case 'o': ret = 1; break;
       case 'u': ret = 1; break;
       case 'A': ret = 1; break;
       case 'E': ret = 1; break;
       case 'I': ret = 1; break;
       case 'O': ret = 1; break;
       case 'U': ret = 1; break;
   }
   return ret;
}

int checkConsonant(char ch) {
    return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}
