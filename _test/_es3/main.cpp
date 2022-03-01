#include <iostream>
#include <fstream>

using namespace std;

const char INPUT_FILE[] = "consumi.txt";

struct Stabilimento {
    int id;
    double consumi_inizio;
    double consumi_fine;
    double costo;
};

int main() {

    fstream fin;
    fin.open(INPUT_FILE);
    if (!fin) {
        cout << "ERR | Il file non esiste!" << endl;
        return -1;
    }

    double consumo_tot = 0.0d, costo_tot = 0.0d, costo_med_unitario = 0.0d;
    Stabilimento stb0;
    stb0.id = -1;

    fin >> stb0.id >> stb0.consumi_inizio >> stb0.consumi_fine >> stb0.costo;
    if (stb0.id != -1) {
        consumo_tot += (stb0.consumi_fine - stb0.consumi_inizio);
        costo_tot += stb0.costo;
        while (!fin.eof()) {
            fin >> stb0.id >> stb0.consumi_inizio >> stb0.consumi_fine >> stb0.costo;
            consumo_tot += (stb0.consumi_fine - stb0.consumi_inizio);
            costo_tot += stb0.costo;
        }
    }
    fin.close();


    cout << "Consumo totale: " << consumo_tot << "kWh" << endl;
    cout << "Costo totale: " << costo_tot << " Euro" << endl;
    if (stb0.id == -1) {
        cout << "ERR | il file e' vuoto." << endl;
    } else {
        costo_med_unitario = costo_tot/consumo_tot;
        cout << "Costo unitario medio: " << costo_med_unitario << " Euro/kWh" << endl;
    }

    return 0;
}
