/*  Obiettivo:
    Il programma ...
*/

#include <iostream>

#define EXIT_CHAR 'y'

using namespace std;

int main() {

    cout << "This program simulates a calculator" << endl;
    cout << "===================================" << endl;


    float num1 = 0.0f, num2 = 0.0f, result = 0.0f;
    char op = '\0', choice = EXIT_CHAR;

    do {
        /* cout << "Enter the FIRST number: ";
        cin << num1;

        cout << "Enter the SECOND number: ";
        cin << num2;

        cout << "Choose the operation that you want to execute:\n\t1) SUM (+)\n\t2) SUBTRACTION (-)\n\t3) MULTIPLICATION (*)\n\t4) DIVISION (/)\nYour choice is: ";
        */

        bool err = false;

        cout << "Enter the operation you want to execute (ex. \"3 + 5\"): ";
        cin >> num1 >> op >> num2;

        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 != 0) {
                result = num1 / num2;
                } else err = true;
                break;
            default: err = true;
        }
        if (!err) {
            cout << "The result of the operation is: " << result << endl;
        } else cout << "I'm sorry but you entered a wrong operation." << endl;


        cout << "Enter '" << EXIT_CHAR << "' if you want to make another operation, otherwise any other letter to exit." << endl;
        cin >> choice;
    } while (choice == EXIT_CHAR);


    return 0;
}
