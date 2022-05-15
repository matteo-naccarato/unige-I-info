#include "Retta.cpp"

const int MIN_N = 1;
const int MAX_N = 256;

int main() {

    int n = -1;
    double xP = 0, yP = 0, distance = 0;

    do {
        cout << "Inserire la grandezza dell'array: ";
        cin >> n;
        if (n < MIN_N || n > MAX_N) cout << "ERR | Input not valid." << endl;
    } while (n < MIN_N || n > MAX_N);

    Retta<double>* arr = new Retta<double>[n];

    for (int i=0; i<n; i++) {
        arr[i].input_data();
    }

    cout << "Inserire le coordinate del punto P: ";
    cin >> xP >> yP;
    for (int i=0; i<n; i++) {
        distance = arr[i].calc_distance(xP, yP);
        cout << i << ") Distance: " << distance << endl;
    }


    delete[] arr;

    return 0;
}