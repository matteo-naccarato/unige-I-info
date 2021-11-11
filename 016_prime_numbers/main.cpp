/* Obiettivo:
    Il programma chiede ...
*/

#include <iostream>

using namespace std;

int main() {

    int num = -1;
    int isPrime = 1;

    cout << "This program determines if number given as input is a prime number or not" << endl;
    cout << "=====================================" << endl;

    do {
        cout << "Enter a number (> 1): ";
        cin >> num;

        if (num <= 1) {
            cout << "ERR | The number must be greater than 1 (> 1). Try again!" << endl;
        }
    } while (num <= 1);


    for (int i = 2; (isPrime=(num%i == 0)? 0: 1)==1 && i < num/2 && isPrime == 1; i++) {}
    cout << "The number (" << num << ") IS" << ((isPrime == 1)? " ": " NOT ") << "a prime number." << endl;

    return 0;
}
