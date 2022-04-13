#include <iostream>

using namespace std;

const int CNT_DATA = 2;
const int T_DATA_INDEX = 0;
const int P_DATA_INDEX = 1;
const double INIT_T = 15;
const double INIT_P = 750;
const double MIN_T = -40;
const double MAX_T = 70;
const double MIN_P = 500;
const double MAX_P = 1000;

class Measure {
    private:
        double data[CNT_DATA];
    
    public:
        Measure();
        Measure(double t, double p);
        Measure(double data[CNT_DATA]);
        Measure(const Measure& m);
        ~Measure();
        double getTemperature();
        double getPressure();
        void getTempPress(double ret_data[CNT_DATA]);
        void setTemperature(double temp);
        void setPressure(double press);
        void setTempPress(double d[CNT_DATA]);
        void toString();
};

Measure::Measure() {
    data[T_DATA_INDEX] = INIT_T;
    data[P_DATA_INDEX] = INIT_P;
    cout << "DEFAULT constructor done." << endl;
}

Measure::Measure(double t, double p) {
    data[T_DATA_INDEX] = (t >= MIN_T && t <= MAX_T)? t : INIT_T;
    data[P_DATA_INDEX] = (p >= MIN_P && p <= MAX_P)? p : INIT_P;
    cout << "PARAMS constructor done." << endl;
}

Measure::Measure(double data[CNT_DATA]) : Measure(data[T_DATA_INDEX], data[P_DATA_INDEX]) {
    cout << "ARRAY as param constructor done." << endl;
}

Measure::Measure(const Measure& m) : Measure(m.data[T_DATA_INDEX], m.data[P_DATA_INDEX]) {
    cout << "COPY constructor done." << endl;
}

Measure::~Measure() {
    cout << "distruttore :)" << endl;
}

double Measure::getTemperature() { return data[T_DATA_INDEX]; }
double Measure::getPressure() { return data[P_DATA_INDEX]; }
void Measure::getTempPress(double ret_data[CNT_DATA]) {
    ret_data[T_DATA_INDEX] = data[T_DATA_INDEX];
    ret_data[P_DATA_INDEX] = data[P_DATA_INDEX];
}
void Measure::setTemperature(double temp) { data[T_DATA_INDEX] = temp; }
void Measure::setPressure(double press) { data[P_DATA_INDEX] = press; } 
void Measure::setTempPress(double d[CNT_DATA]) {
    data[T_DATA_INDEX] = d[T_DATA_INDEX];
    data[P_DATA_INDEX] = d[P_DATA_INDEX];
}
 
void Measure::toString() {
    cout << "\tMeasure = {\n\t\t\"_temperature\": " << this->getTemperature() << " [C],\n\t\t\"_pressure\": " << this->getPressure() << " [hPa]\n\t}" << endl;
}



void leggi_rilevamento(Measure& m) {
    double temp_temperature, temp_pressure;
    cout << "Enter the temperature: ";
    cin >> temp_temperature;
    cout << "Enter the pressure: ";
    cin >> temp_pressure;

    m.setTemperature(temp_temperature);
    m.setPressure(temp_pressure);
}

void stampa_rilevamento(Measure m) {
    cout << "ext | ";
    m.toString();
}


int main() {

    Measure m;
    leggi_rilevamento(m);
    stampa_rilevamento(m);

    return 0;
}