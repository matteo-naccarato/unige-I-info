#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = a++;
    cout << "a vale " << a << endl;
    cout << "b vale " << b << endl;

    int c = ++a;
    cout << "a vale " << a << endl;
    cout << "c vale " << c << endl;

    b = 7;
    cout << "b vale " << b << endl;
    int z = (a == b);
    cout << "z vale " << z << endl;

    // intervallo interno
    int k = ((a >= 1) && (a <= 10));
    cout << "k vale " << k << endl;

    // intervallo esterno
    int p = ((a < 1) || (a > 10));
    cout << "p vale " << p << endl;


    char car = '5';
    int num = b + car;
    cout << "\nnum vale " << num << ", valore ASCII di " << (b + car) << ". Avrei voluto fare (" << b << " + " << car << ")" << endl;

    num = b + (car - '0');
    cout << "\nCORRETTO: num vale " << num << " dopo l'operazione (num = b + (car - '0'))" << endl;


    return 0;
}
