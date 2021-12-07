/* Obiettivo:
    Creare un programma che ricevuto in ingresso un file chiamato “input.txt” crei in uscita un file chiamato
    “output.txt” formato da tante righe quante sono le lettere dell’alfabeto e per ogni riga viene riportata una lettera
    e quante volte quella lettera compare nel file “input.txt”.

    Hint: potete creare un array di 26 interi. Quando andate a leggere un carattere, potete incrementare l’elemento
    dell’array in posizione n utilizzando la codifica ascii.

    Es.
    ingr >> c;
    int posizione=c-'a’;
    conto[posizione]++;
*/

#include <iostream>
#include <fstream>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define N_ALPHABET 26

using namespace std;

int main() {

    cout << "This program countes how many each letter of the alphabet appears in a file given as input." << endl;
    cout << "===========================" << endl;

    fstream fin, fout;
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | \"" << INPUT_FILE << "\" not found." << endl;
        return -1;
    }
    int cnts_array[N_ALPHABET] = {0};
    char chr;
    while (!fin.eof()) {
        chr = ' ';
        fin >> chr;
        if (isalpha(chr)) {
            chr += (isupper(chr)? 32:0);
            cnts_array[chr - 'a']++;
        }
    }
    fin.close();
    cout << "File READ successfully." << endl;

    fout.open(OUTPUT_FILE, ios::out);
    for (int i=0; i<N_ALPHABET; i++) {
        fout << ((char)(i+'A')) << "/" << ((char) (i+'a')) << ": " << cnts_array[i] << "\n";
    }
    fout.close();
    cout << "File written successfully." << endl;

    return 0;
}
