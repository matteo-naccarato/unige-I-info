/* Obiettivo:
    Scrivere un programma che ricevuto in ingresso un file chiamato “input.txt” e un carattere digitato da tastiera
    dall’utente restituisca tramite la console quante volte quel carattere compare nel file
    “input.txt”.
*/

#include <iostream>
#include <fstream>

#define INPUT_FILE "input.txt"

using namespace std;

int main() {

    cout << "This program ..." << endl;
    cout << "============================" << endl;

    fstream fin;
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | \"" << INPUT_FILE << "\" file not found." << endl;
        return -1;
    }

    char chr, temp_in;
    int cnt_char = 0;
    cout << "Enter the character that you are looking for: ";
    cin >> chr;
    while(!fin.eof()) {
        fin >> temp_in;
        if (temp_in == chr) {
            cnt_char++;
        }
    }
    fin.close();

    cout << cnt_char << " occurences of character '" << chr << "' found." << endl;

    return 0;
}
