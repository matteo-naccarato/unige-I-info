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
        double _temperature;
        double _pressure;
    
    public:
        Measure();
        Measure(double t, double p);
        Measure(double data[CNT_DATA]);
        Measure(const Measure& m);
        ~Measure();
        double getTemperature();
        double getPressure();
        void setTemperature(double temp);
        void setPressure(double press);
        void toString();
};

Measure::Measure() {
    _temperature = INIT_T;
    _pressure = INIT_P;
    cout << "DEFAULT constructor done." << endl;
}

Measure::Measure(double t, double p) {
    _temperature = (t >= MIN_T && t <= MAX_T)? t : INIT_T;
    _pressure = (p >= MIN_P && p <= MAX_P)? p : INIT_P;
    cout << "PARAMS constructor done." << endl;
}

Measure::Measure(double data[CNT_DATA]) : Measure(data[T_DATA_INDEX], data[P_DATA_INDEX]) {
    cout << "ARRAY as param constructor done." << endl;
}

Measure::Measure(const Measure& m) : Measure(m._temperature, m._pressure) {
    cout << "COPY constructor done." << endl;
}

Measure::~Measure() {
    cout << "distruttore :)" << endl;
}

double Measure::getTemperature() { return _temperature; }
double Measure::getPressure() { return _pressure; }
void Measure::setTemperature(double temp) { _temperature = temp; }
void Measure::setPressure(double press) { _pressure = press; } 
 
void Measure::toString() {
    cout << "\tMeasure = {\n\t\t\"_temperature\": " << _temperature << " [C],\n\t\t\"_pressure\": " << _pressure << " [hPa]\n\t}" << endl;
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

    double arr[2] = {-1,2};
    Measure m2(arr);
    m2.toString();

    Measure m3(m2);
    m3.toString();
 
    cout << "break" << endl;

    return 0;
}