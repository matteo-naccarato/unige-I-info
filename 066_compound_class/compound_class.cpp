#include <iostream>
#include "./includes/ReadSensor.hpp"

using namespace std;

/* READ SENSOR */
const int CNT_READ_SENSORS = 3;  


int main() {

    Read_Sensor d[CNT_READ_SENSORS];
    for (int i=0; i<CNT_READ_SENSORS; i++) {
        cout << "======================== " << i << " ========================" << endl;
        d[i].leggi();
    }
    cout << "READ completed" << endl;

    for (int i=0; i<CNT_READ_SENSORS; i++) {
        cout << "======================== " << i << " ========================" << endl;
        d[i].stampa();
    } 
    cout << "PRINT completed" << endl;

    return 0;
}