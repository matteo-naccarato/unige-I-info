#include <iostream>

using namespace std;


const int POWS_CNT = 4;
const int ZERO_POW_INDEX = 0;
const int ONE_POW_INDEX = 1;
const int SQUARE_POW_INDEX = 2;
const int CUBE_POW_INDEX = 3; 


bool isPrime(int num) {
    bool isPrime = true;
    for (int d=2; d<=num/2 && isPrime; d++) {
        if (num % d == 0) 
            isPrime = false;
    }
    return isPrime;
} 

void get_first_n_primes(int* arr, int n) {
    int num = 1;
    int i=0;
    while (i<n) {
        if (isPrime(num)) {
            arr[i] = num;
            i++;
        }
        num++;
    }
}

int pow_zero(int n) {
    return 1;
}

int pow_one(int n) {
    return n;
}

int pow_square(int n) {
    return n*n;
}

int pow_cube(int n) {
    return n*n*n;
}

int sum_with_pows(int* arr, int n, int (*pf)(int)) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += (*pf)(arr[i]);
    }
    return sum;
}


int main() {

    bool err = false;
    int n = -1;

    do {
        err = false;
        cout << "Enter how many prime numbers u wanna sum: ";
        cin >> n;
        if (n < 1) {
            err = true;
            cout << "ERR |  value not valid." << endl;
        }
    } while (err);

    int (*pow_functs[])(int) = {pow_zero, pow_one, pow_square, pow_cube};
    int pow_index = ONE_POW_INDEX;
    int pow_choice = -1;
    do {
        err = false;
        cout << "Enter the pow u wanna apply to numbers before summing: ";
        cin >> pow_choice;
        switch (pow_choice) {
            case 0:
                pow_index = ZERO_POW_INDEX;
                break;
            case 1:
                pow_index = ONE_POW_INDEX;
                break;
            case 2:
                pow_index = SQUARE_POW_INDEX;
                break;
            case 3:
                pow_index = CUBE_POW_INDEX;
                break;

            default:
                err = true;
                cout << "ERR | value not valid." << endl;

        }
    } while (err);

    int* primes = new int[n];
    get_first_n_primes(primes, n);

    for (int i=0; i<n; i++) cout << primes[i] << " ";
    cout << endl;

    int sum = sum_with_pows(primes, n, pow_functs[pow_index]);
    cout << "SUM with powing: " << sum << endl;


    delete[] primes;

    return 0;
}