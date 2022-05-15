#include <cmath>
#include "Retta.h"

template<typename T>
Retta<T>::Retta() : _m(0), _q(0) {}

template<typename T>
Retta<T>::Retta(T m, T q) : _m(m), _q(q) {}

template<typename T>
Retta<T>::Retta(const Retta& r) : _m(r._m), _q(r._q) {}

template<typename T>
Retta<T>::~Retta() {}

template<typename T>
T Retta<T>::get_m() const { return _m; }
template<typename T>
Retta<T>& Retta<T>::set_m(T m) {
    _m = m;
    return *this;
}
template<typename T>
T Retta<T>::get_q() const { return _q; }
template<typename T>
Retta<T>& Retta<T>::set_q(T q) {
    _q = q;
    return *this;
}

template<typename T>
void Retta<T>::input_data() {
    cout << "Inserire coefficiente angolare: ";
    cin >> _m;

    cout << "Inserire intercetta: ";
    cin >> _q;
}   

template<typename T>
void Retta<T>::print_data() {
    cout << "r: y = " << _m << "x " << ((_q<0)? "-":"+")  << ((_q<0)? -_q:_q) << endl;
}

template<typename T>
float Retta<T>::calc_distance(T xP, T yP) {
    return abs(yP-(_m*xP + _q))/sqrt(1 + _m*_m);
}

