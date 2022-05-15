#include <iostream>

using namespace std;

template<typename T>
class Retta {

    private:
        T _m;
        T _q;

    public:
        Retta();
        Retta(T m, T q);
        Retta(const Retta& r);
        ~Retta();

        T get_m() const;
        Retta& set_m(T m);
        T get_q() const;
        Retta& set_q(T q); 

        void input_data();
        void print_data();
        float calc_distance(T xP, T yP);
};