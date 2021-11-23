/* Obiettivo:
    Creare un programma che, dopo aver chiesto all’utente di inserire due tempi dati in millisecondi, restituisca per
    entrambi l'equivalente in termini di minuti, secondi, millisecondi, e controlli se corrispondono agli stessi minuti.
*/

#include <iostream>
#define N_TIMES 2

using namespace std;

float convert_time_ms2sec(int ms);
int convert_time_ms2min(int ms, int& sec_rest);

int main() {
    cout << "??????????????????????" << endl;
    cout << "==============================" << endl;

    int time_ms = -1, time_min = -1, time_rest_seconds = 0;
    float time_sec = -1;
    for (int i=0; i<N_TIMES; i++) {
        do {
            cout << "Enter a time in milliseconds (ms): ";
            cin >> time_ms;
            if (time_ms < 0)
                cout << "ERR | You entered a wrong time. It must be positive, try again." << endl;
        } while(time_ms < 0);
        time_sec = convert_time_ms2sec(time_ms);
        time_min = convert_time_ms2min(time_ms, time_rest_seconds);

        cout << "(" << time_ms << " ms) = (" << time_sec << " s) = (" << time_min << " minutes " << time_rest_seconds << " seconds and " << (time_ms%1000) << " milliseconds).\n" << endl;
    }

    return 0;
}

float convert_time_ms2sec(int ms) {
    return (float) ms/1000;
}

int convert_time_ms2min(int ms, int& sec_rest) {
    float sec = convert_time_ms2sec(ms);
    int minutes = sec/60;
    if (minutes==0 || minutes%60 != 0) {
        sec_rest = sec - minutes*60;
    }
    return minutes;
}
