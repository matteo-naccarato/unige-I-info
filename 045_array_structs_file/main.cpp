/* Obiettivo:
    Il programma definisce una struct data che memorizza giorno, mese e anno.
    Legge poi da un file input.txt 5 date di nascita (in ogni riga del file ci saranno giorno, mese e anno separati da
    spazi), fa inserire all’utente la data odierna e verifica quante date di nascita corrispondono a maggiorenni.
    Hint: La struttura può avere tre interi, e si può utilizzare lo stream in input per leggere direttamente i 3 interi. La
    dimensione del file è nota.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const char INPUT_FILE[] = "input.txt";
const int N_ROWS_FILE = 5;
const int MAX_STR = 11;
const int LEGAL_AGE = 18;

struct Date {
    int day;
    int month;
    int year;
};

int main() {

    cout << "This program countes how many there are people with the legal age." << endl;
    cout << "==========================" << endl;

    fstream fin;
    fin.open(INPUT_FILE, ios::in);
    if (!fin) {
        cout << "ERR | Error opening file." << endl;
        return -1;
    }
    Date dates_of_birth[N_ROWS_FILE];
    Date today;
    for (int i=0; !fin.eof() && i<N_ROWS_FILE; i++) {
        fin >> dates_of_birth[i].day >> dates_of_birth[i].month >> dates_of_birth[i].year;
    }
    cout << "File read successfully.\n" << endl;

    cout << "------------\nEnter today's date" << endl;
    cout << "\tDay: ";
    cin >> today.day;
    cout << "\tMonth (January = 1, ...): ";
    cin >> today.month;
    cout << "\tYear: ";
    cin >> today.year;


    int cnt_legal_age = 0;
    for (int i=0; i<N_ROWS_FILE; i++) {
        int delta_year = today.year - dates_of_birth[i].year;
        if (delta_year > LEGAL_AGE) cnt_legal_age++;
        else if (delta_year == LEGAL_AGE) {
            int delta_month = today.month - dates_of_birth[i].month;
            if (delta_month > 0) cnt_legal_age++;
            else if (delta_month == 0) {
                int delta_day = today.day - dates_of_birth[i].day;
                if (delta_day >= 0) cnt_legal_age++;
            }
        }
    }

    cout << "There are " << cnt_legal_age << " people with the legal age (" << LEGAL_AGE << ")." << endl;

    return 0;
}
