#include <iostream>

#include "./Measure.hpp"
#include "./MyTime.hpp"

using namespace std;

class Read_Sensor {
    private: 
        MyTime _t;
        Measure _m;
    
    public:
        Read_Sensor();
        Read_Sensor(MyTime t, Measure m);
        Read_Sensor(const Read_Sensor& rs);
        ~Read_Sensor();
        MyTime getT();
        void setT(MyTime t);
        Measure getM();
        void setM(Measure m);
        void stampa();
        void leggi();
};

Read_Sensor::Read_Sensor() {
    // cout << "Costruttore di default della classe Read_Sensor" << endl;
}

Read_Sensor::Read_Sensor(MyTime t, Measure m) : Read_Sensor() {
    _t = t;
    _m = m;    
}

Read_Sensor::Read_Sensor(const Read_Sensor& rs) : Read_Sensor(rs._t, rs._m) {}

Read_Sensor::~Read_Sensor() {
    // cout << "Distruttore della classe Read_Sensor" << endl;
}

MyTime Read_Sensor::getT() { return _t; }
void Read_Sensor::setT(MyTime t) { _t = t; }
Measure Read_Sensor::getM() { return _m; }
void Read_Sensor::setM(Measure m) { _m = m; }

void Read_Sensor::stampa() {
    stampa_rilevamento(_m);
    _t.stampa();
}
void Read_Sensor::leggi() {
    leggi_rilevamento(_m);
    _t.leggi();
}