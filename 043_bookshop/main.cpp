/* Obiettivo:
    Scrivere un programma che prenda in ingresso un file di testo che descrive l’inventario di una libreria, con quattro
    campi: titolo del libro, autore, pagine, costo. Es:
    Il codice da Vinci, Dan Brown, 500, 20
    Lo Hobbit, JRR Tolkien, 700, 35
    L'alchimista, Paulo Coelho, 350, 25
    Il giovane Holden, J.D. Salinger, 225, 15
    Dieci piccoli indiani, Agatha Christie, 275, 18
    Il programma chiede quindi all’utente di inserire il titolo di un libro, restituendo le altre informazioni (autore, pagine,
    costo).
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char INPUT_FILE[] = "books.txt";
const int MAX_STR = 256;

struct Book {
    char title[MAX_STR];
    char author[MAX_STR];
    char price[MAX_STR];
    char n_pages[MAX_STR];
};

int main() {
    cout << "This program looks for some detail on a specific book." << endl;
    cout << "==============================" << endl;

    fstream fin;
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | Error opening file." << endl;
        return -1;
    }


    /** conto QUANTI ELEMENTI ci sono nel FILE */
    int cnt_books = -1;
    char temp[MAX_STR];
    while (!fin.eof()) {
        fin.getline(temp, MAX_STR, '\n');
        cnt_books++;
    }
    fin.close();

    /** CARICO ARRAY libri */
    Book inventory[cnt_books];
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | Error opening file." << endl;
        return -1;
    }
    for (int i=0; i<cnt_books; i++) {
        /** COMODITA' getline => posso mettere ',' come CARATTERE TERMINANTE */
        fin.getline(inventory[i].title, MAX_STR, ',');
        fin.getline(inventory[i].author, MAX_STR, ',');
        fin.getline(inventory[i].n_pages, MAX_STR, ',');
        fin.getline(inventory[i].price, MAX_STR, '\n');
    }
    /** !!!!!!!!!!!!!! CHIUSURA FILE!!!!!!!!!!!!!! */
    fin.close();

    cout << "Enter the title of the book you want some infos: ";
    cin.getline(temp, MAX_STR, '\n');
    /** LOOKING FOR the title */
    bool found = false;
    for (int i=0; i<cnt_books && !found; i++) {
        cout << "Looking for the book [" << i << "/" << cnt_books << "]" << " ..." << endl;
        cout << inventory[i].title << endl;
        if (strcmp(inventory[i].title, temp) == 0) {
            found = true;
            cout << "FOUND! \"" << temp << "\" was written by \"" << inventory[i].author << "\", has \"" << inventory[i].n_pages << "\" pages and its cost is \"" << inventory[i].price << " EUR\". See u soon buddy :))" << endl;
        }
    }
    if (!found) {
        cout << "I'm sorry, but that book isn't in the collection :(. U can try with a different title." << endl;
    }
    return 0;
}
