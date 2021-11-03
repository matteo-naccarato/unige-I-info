/* Obiettivo:
    Creare un programma che risolva le equazioni di secondo grado.
    Potrà capitare all'esame orale (25/10/2021, 16:16).

    TIPS:
        ax^2 + bx + c = 0
        a = 0 -> bx + c = 0
        a != 0 -> x12 = (-b +- sqrt(b^2 - 4ac))2a (se delta > 0)
        sqrt => in cmath
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    double a = 0.0, b = 0.0, c = 0.0;
    double delta = 0.0, x1 = 0.0, x2 = 0.0;
    int choice = -1;
    bool singleValue = false, infValues = false, err = false;

    cout << "This program calculates the result(s) of a second-degree equation given as input  (model: ax^2 + bx + c = 0) ..." << endl;
    cout << "============================" << endl;

    do {
        if (choice != -1) system("CLS");
        singleValue = false, infValues = false, err = false;
        cout << "Insert the value of the first coefficient (a): ";
        cin >> a;

        cout << "Insert the value of the second coefficient (b): ";
        cin >> b;

        cout << "Insert the value of the known term (c): ";
        cin >> c;

        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    infValues = true;
                } else {
                    err = true;
                    cout << "ERR | There are no solutions. (division by zero, -c/b)." << endl;
                }
            } else {
                singleValue = true;
                x1 = -c/b;
            }

        } else {
            delta = pow(b, 2) - (4 * a * c);
            if (delta > 0) {
                x1 = (-b -sqrt(delta)) / (2 * a);
                x2 = (-b +sqrt(delta)) / (2 * a);
            } else {
                if (delta == 0) {
                    singleValue = true;
                    x1 = (-b -sqrt(delta)) / (2 * a);
                } else {
                    err = true;
                    cout << "ERR | There are no solutions in the set of reals (R): negative delta." << endl;
                }
            }
        }

        cout << "============================" << endl;
        if (!err) {
            if (infValues) {
                cout << "There are infinite solutions in R." << endl;
            } else {
                if (singleValue) {
                    cout << "The result is:\n\tx = " << x1 << endl;
                } else {
                    cout << "The results are:\n\tx1 = " << x1 << ",\tx2 = " << x2 << endl;
                }
            }
        }

        cout << "============================" << endl;
        do {
            cout << "Do you want to try again? (YES = 1, NO = 0): ";
            cin >> choice;
            if (choice != 0 && choice != 1) {
                err = true;
                cout << "ERR | The value of your choice can only be 0 (NO) or 1 (YES)." << endl;
            } else err = false;
        } while (err);
    } while (choice == 1);


    return 0;
}
