/* Obiettivo:
     Creare un programma in c++ che chieda all’utente di immettere due interi, divida il primo numero per
    il secondo, e stampi a terminale il quoziente e il resto
*/

#include <iostream>

using namespace std;

int main(){

    int num1 = 0, num2 = 0, q = 0, r = 0;

    cout << "This program calculates and shows the quotient and the remainder of the division between two integers previously given as input ..." << endl;
    cout << "=========================" << endl;

    cout << "Insert the first number: ";
    cin >> num1;
    do {
        cout << "Insert the second number: ";
        cin >> num2;
        if (num2 == 0) {
            cout << "ERR - you can't divide by 0. Try again." << endl;
        }
    } while (num2 == 0);


    q = num1/num2;
    r = num1 % num2;

    cout << "=========================" << endl;
    cout << "The quotient is: " << q << endl;
    cout << "The remainder is: " << r << endl;

    return 0;
}
