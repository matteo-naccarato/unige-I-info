#include <iostream>

using namespace std;

/* MyTime */
const int INIT_H = 0;
const int INIT_M = 0;
const int INIT_S = 0;
const int MIN_H = 0;
const int MAX_H = 23;
const int MIN_M = 0;
const int MAX_M = 59;
const int MIN_S = 0;
const int MAX_S = 59;

class MyTime {
    private: 
        int _hour;
        int _min;
        int _sec;
    
    public:
        MyTime();
        MyTime(int hour, int min, int sec);
        MyTime(const MyTime& t);
        ~MyTime();
        void setHour(int h);
        int getHour();
        void setMin(int m);
        int getMin();
        void setSec(int s);
        int getSec();
        void stampa();
        void leggi();
};

MyTime::MyTime() {
    _hour = INIT_H;
    _min = INIT_M;
    _sec = INIT_S;
    // cout << "Costruttore di default della classe tempo" << endl;
}

MyTime::MyTime(int hour, int min, int sec) {
    _hour = (hour < MIN_H || hour > MAX_H)? INIT_H:hour;
    _min = (min < MIN_M || min > MAX_M)? INIT_M:min;
    _sec = (min < MIN_S || MAX_S)? INIT_S:sec;
}

MyTime::~MyTime() {
    // cout << "Distruttore della classe tempo" << endl;
}

MyTime::MyTime(const MyTime& t) : MyTime(t._hour, t._min, t._sec) {}

void MyTime::setHour(int h) { _hour = (h < MIN_H || h > MAX_H)? _hour:h; }
int MyTime::getHour() { return _hour; }
void MyTime::setMin(int m) { _min = (m < MIN_M || m > MAX_M)? _min:m; }
int MyTime::getMin() { return _min; }
void MyTime::setSec(int s) { _sec = (s < MIN_S || s > MAX_S)? _sec:s; }
int MyTime::getSec() { return _sec; }

void MyTime::stampa() { 
    cout << "\tOre: " << _hour << ":" << _min << ":" << _sec << endl;
}

void MyTime::leggi() {
    int h,m,s;
    do {
        cout << "Enter hours: ";
        cin >> h;
        if (h < MIN_H || h > MAX_H) cout << "\tERR | value not valid." << endl;
    } while(h < MIN_H || h > MAX_H);

    do {
        cout << "Enter minutes: ";
        cin >> m;
        if (m < MIN_M || m > MAX_M) cout << "\tERR | value not valid." << endl;
    } while (m < MIN_M || m > MAX_M);

    do {
        cout << "Enter seconds: ";
        cin >> s;
        if (s < MIN_S || s > MAX_S) cout << "\tERR | value not valid." << endl;
    } while(s < MIN_S || s > MAX_S);

    _hour = h;
    _min = m;
    _sec = s;
}