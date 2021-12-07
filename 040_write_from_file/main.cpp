/* Obiettivo:
    Scrivere un programma che memorizza nel file “output.txt” quanto viene passato dall’utente via tastiera (un
    carattere per volta), andando a capo quando viene passato uno ‘0’ (zero) e chiudendo il file e il programma
    quando vengono passati due zeri consecutivi.
*/

#include <iostream>
#include <fstream>

#define QUESTION "Enter a character that you want to write to the file: "
#define OUTPUT_FILE "output.txt"
#define CHR_END_INPUT '0'

using namespace std;

int main() {

    cout << "This program works like a stream from the keyboard to a file." << endl;
    cout << "===============================" << endl;

    fstream fout;
    fout.open(OUTPUT_FILE, ios::out);
    char chr_new = ' ', chr_old = ' ';
    bool end_input = false;
    do {
        chr_old = chr_new;
        cout << "Enter a character that you want to write to the file ('0'=\\n, '0''0'=eof): ";
        cin >> chr_new;
        if (chr_new == CHR_END_INPUT && chr_old == CHR_END_INPUT) end_input = true;
        else {
            if (chr_new == CHR_END_INPUT) fout << endl;
            else fout << chr_new;
        }
    } while (!end_input);
    fout.close();

    cout << "FILE SUCCESSFULLY WRITTEN!" << endl;
    return 0;
}
