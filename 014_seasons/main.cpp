/* Obiettivo:
    Scivere un programma che chieda all'utente di immettere due interi, relativi al giorno e al mese, e restituisca la
    stagione corrispondente. Utilizzare sia l'operatore switch che if
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

#define N_MONTHS 12
#define WINTER "WINTER"
#define SPRING "SPRING"
#define SUMMER "SUMMER"
#define AUTUMN "AUTUMN"

#define MAX_STR 100

using namespace std;

// ENUM of months in the program => 0, 1, 2, ...
// January, February, March, April, May, June, July, August, September, October, November, December
const int DAYS_IN_MONTHS[N_MONTHS] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    cout << "Given as input a day and a month, this program returns the corresponding season." << endl;

    int day = -1, month = -1;
    char* season = (char*) malloc(sizeof(char) * MAX_STR);
    bool err = false;

    do {
        err = false;
        cout << "Enter the desired month as an integer (January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12):" << endl;
        cin >> month;
        month--;
        if (month < 0 || month > 11) {
            err = true;
            cout << "ERR | Invalid value. Try again." << endl;
        }
    } while (err);

    do {
        err = false;
        cout << "Enter the desidered day (in the month you selected there are " << DAYS_IN_MONTHS[month]  <<  " days): ";
        cin >> day;
        if (day < 1 || day > DAYS_IN_MONTHS[month]) {
            err = true;
            cout << "ERR | You entered a day that does not exist in the specified month." << endl;
        }
    } while (err);


    cout << "\n======= SWTICH version =======" << endl;
    switch (month) {
    case  0: season = strdup(WINTER); break;
    case  1: season = strdup(WINTER); break;
    case  2: season = strdup((day <= 20)? WINTER : SPRING); break;
    case  3: season = strdup(SPRING); break;
    case  4: season = strdup(SPRING); break;
    case  5: season = strdup((day <= 20)? SPRING : SUMMER); break;
    case  6: season = strdup(SUMMER); break;
    case  7: season = strdup(SUMMER); break;
    case  8: season = strdup((day <= 22)? SUMMER : AUTUMN); break;
    case  9: season = strdup(AUTUMN); break;
    case  10: season = strdup(AUTUMN); break;
    case  11: season = strdup((day <= 21)? AUTUMN : WINTER); break;
    }

    cout << "The season is " << season << endl;


    cout << "\n========= IF version =========" << endl;
    if (month == 0) {
        season = strdup(WINTER);
    } else if (month == 1) {
        season = strdup(WINTER);
    } else if (month == 2) {
        season = strdup((day <= 20)? WINTER : SPRING);
    } else if (month == 3) {
        season = strdup(WINTER);
    } else if (month == 4) {
        season = strdup(WINTER);
    } else if (month == 5) {
        season = strdup((day <= 20)? SPRING : SUMMER);
    } else if (month == 6) {
        season = strdup(WINTER);
    } else if (month == 7) {
        season = strdup(WINTER);
    } else if (month == 8) {
        season = strdup((day <= 22)? SUMMER : AUTUMN);
    } else if (month == 9) {
        season = strdup(WINTER);
    } else if (month == 10) {
        season = strdup(WINTER);
    } else if (month == 11) {
        season = strdup((day <= 21)? AUTUMN : WINTER);
    }

    cout << "The season is " << season << endl;

    free(season);

    return 0;
}
