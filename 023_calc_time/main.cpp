/* Obiettivo:
    Creare un programma che, dopo aver chiesto all’utente di inserire due tempi dati in millisecondi, restituisca per
    entrambi l'equivalente in termini di minuti, secondi, millisecondi, e controlli se corrispondono agli stessi minuti.
*/

#include <iostream>
#define N_TIMES 2

using namespace std;

float convert_time_ms2sec(int ms);
int convert_time_ms2min(int ms_input, float& sec_calc, int& ms_calc);

int main() {
    cout << "??????????????????????" << endl;
    cout << "==============================" << endl;

    int time_ms = -1, time_min_calc = -1, time_ms_calc = -1;
    float time_sec_calc = -1;
    for (int i=0; i<N_TIMES; i++) {
        do {
            cout << "Enter a time in milliseconds (ms): ";
            cin >> time_ms;
            if (time_ms < 0)
                cout << "ERR | You entered a wrong time. It must be positive, try again." << endl;
        } while(time_ms < 0);
        time_sec_calc = convert_time_ms2sec(time_ms);
        time_min_calc = convert_time_ms2min(time_ms, time_sec_calc, time_ms_calc);

        cout << "(" << time_ms << " ms) = (" << time_sec_calc << " s) = (" << time_min_calc << " minutes " << (((int) time_sec_calc)%60) << " seconds and " << time_ms_calc << " milliseconds).\n" << endl;
    }

    return 0;
}

float convert_time_ms2sec(int ms) {
    return (float) ms/1000;
}

int convert_time_ms2min(int ms_input, float& sec_calc, int& ms_calc) {
    sec_calc = convert_time_ms2sec(ms_input);
    int minutes_calc = sec_calc/60;
    ms_calc = ms_input%1000;
    return minutes_calc;
}
