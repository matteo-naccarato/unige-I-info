/* Obiettivo:
    Una struttura è una collezione di elementi denominati campi, ognuno dei quali può contenere un dato di tipo
    diverso.
    Si crei la struttura libro, in cui ogni libro ha un codice numerico (numero intero) che lo caratterizza, un numero di
    pagine e un costo.
    Si memorizzino i dati di tre libri e si calcoli il costo medio per pagina dei libri e si stampino i dati dei tre libri in ordine
    crescente di costo per pagina.
    Facciamo l’esercizio utilizzando tre funzioni, inserisciLibro, confrontaScambia, stampaLibro.
*/

#include <iostream>

using namespace std;

struct Book {
    int id_code;
    int n_pages;
    float price;
};

void input_book(Book &b); /** STRUTTURA x RIFERIMENTO */
void cmp_and_swap(Book& b1, Book& b2);
void print_book(Book b);

int main() {
    cout << "This program sorts a collection of three books by price per page." << endl;
    cout << "===============================" << endl;

    Book b1, b2, b3;
    cout << "============== INPUT BOOKS DETAILS ==================" << endl;
    input_book(b1);
    input_book(b2);
    input_book(b3);

    cmp_and_swap(b1, b2);
    cmp_and_swap(b1, b3);
    cmp_and_swap(b2, b3);
    cout << "\n============= COMPARED and SWAPPED =============" << endl;

    cout << "\n============= SORTED BOOKS" << "=============" << endl;
    print_book(b1);
    print_book(b2);
    print_book(b3);

    return 0;
}

void input_book(Book &b) { // OPPURE faccio restituire il Book b inserito
    cout << "-----\nBOOK:" << endl;
    cout << "\tID: ";
    cin >> b.id_code;
    cout << "\t# pages: ";
    cin >> b.n_pages;
    cout << "\tPrice: ";
    cin >> b.price;
}

void cmp_and_swap(Book& b1, Book& b2) {
    float price_x_page1 = b1.price/b1.n_pages, price_x_page2 = b2.price/b2.n_pages;
    if (price_x_page2 < price_x_page1) {
        Book temp = b1;
        b1 = b2;
        b2 = temp;
    }
}

void print_book(Book b) {
    cout << "Book:{\"id\":" << b.id_code << ", \"n_pages\":" << b.n_pages << ", \"price\":" << b.price << "}" << endl;
}
