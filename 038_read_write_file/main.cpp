/* Obiettivo:
    Scrivere un programma che prende in input un file "ciao.txt" e crea due file chiamati "consonanti.txt" e "vocali.txt"
    in cui ci sono rispettivamente solo le consonanti o le vocali presenti nel file "ciao.txt".
    Se il file "ciao.txt" contiene il testo "prova a fare l'esercizio", il file consonanti conterrà "prvfrlsrcz" mentre quello
    vocali conterrà "oaaaeeeiio".

    Una volta creati i due file "consonanti.txt" e "vocali.txt", riapriamo il file vocali.txt, e aggiungiamo al testo già scritto,
    lo stesso testo invertendo lettere maiuscole con minuscole.
*/

#include <iostream>
#include <fstream>

#define INPUT_FILE "ciao.txt"
#define OUTPUT_FILE_VOWELS "vocali.txt"
#define OUTPUT_FILE_CONSONANTS "consonanti.txt"

using namespace std;

bool isVowel(char chr);

int main() {

    cout << "Given a file as input, this program divides the vowels and the consonants in two different output files." << endl;
    cout << "================================" << endl;

    fstream fin, fout_vowels, fout_cons;
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | File \"" << INPUT_FILE <<  "\" not found." << endl;
        return -1;
    }
    fout_vowels.open(OUTPUT_FILE_VOWELS, ios::out);
    fout_cons.open(OUTPUT_FILE_CONSONANTS, ios::out);
    char chr;
    while (!fin.eof()) {
        fin >> chr;
        if (isalpha(chr)) {
            if (isVowel(chr)) {
                fout_vowels << chr;
            } else {
                fout_cons << chr;
            }
        }
    }
    fin.close();
    fout_cons.close();
    fout_vowels.close();
    cout << "FILES WRITTEN AND CLOSED pt.1" << endl;


    fin.open(OUTPUT_FILE_VOWELS, ios::in);
    fout_vowels.open(OUTPUT_FILE_VOWELS, ios::app);
    fout_vowels << endl;
    while(!fin.eof()) {
        chr = ' '; // PER EVITARE CHE chr VENISSE SOVRASCRITTO
        fin >> chr;
        if (isalpha(chr)) {
            if (islower(chr)) {
                chr -= 32; // -= 'a' + 'A'
            } else {
                chr += 32; // += 'a' - 'A'
            }
        }
        cout << chr;
        fout_vowels << chr;
    }
    fin.close();
    fout_vowels.close();
    cout << "FILE WRITTEN AND CLOSED pt.2" << endl;

    return 0;
}

bool isVowel(char chr) {
    return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u'
            || chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U');
}
