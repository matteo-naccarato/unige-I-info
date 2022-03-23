#include <iostream>

using namespace std;

const int CNT_DATA = 2;
const int T_DATA_INDEX = 0;
const int P_DATA_INDEX = 1;
const double INIT_T = 0;
const double INIT_P = 0;

class Measure {
    private:
        double _temperature;
        double _pressure;
    
    public:
        Measure();
        Measure(double t, double p);
        Measure(double data[CNT_DATA]);
        Measure(const Measure& m);
        void toString();
};

Measure::Measure() {
    _temperature = INIT_T;
    _pressure = INIT_P;
    cout << "DEFAULT constructor done." << endl;
}

Measure::Measure(double t, double p) {
    _temperature = t;
    _pressure = p;
    cout << "PARAMS constructor done." << endl;
}

Measure::Measure(double data[CNT_DATA]) {
    _temperature = data[T_DATA_INDEX];
    _pressure = data[P_DATA_INDEX];
    cout << "ARRAY as param constructor done." << endl;
}

Measure::Measure(const Measure& m) {
    _temperature = m._temperature;
    _pressure = m._pressure;
    cout << "COPY constructor done." << endl;
}

void Measure::toString() {
    cout << "\tMeasure = {\n\t\t\"_temperature\": " << _temperature << " [C],\n\t\t\"_pressure\": " << _pressure << " [hPa]\n\t}" << endl;
}


int main() {

    double test_temp = -1;
    double test_press = -1;

    // DEFAULT constructor
    cout << endl;
    Measure m1;
    m1.toString();

    // PARAMS constructor
    cout << endl;
    test_temp = 20.3;
    test_press = 1000.2;
    Measure m2(test_temp, test_press);
    m2.toString();

    // ARRAY as param constructor
    cout << endl;
    double data[CNT_DATA]; 
    test_temp = 15.6;
    test_press = 1010.7;
    data[T_DATA_INDEX] = test_temp;
    data[P_DATA_INDEX] = test_press;
    Measure m3(data);
    m3.toString();

    // COPY constructor
    cout << endl;
    Measure m4(m1);
    m4.toString();


    return 0;
}