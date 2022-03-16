#include <iostream>

using namespace std;



float recursive_pow(float m, float n) {
    if (n == -1) return 1/m;
    if (n == 1) return m;
    if (n<0) 
        return 1/m * recursive_pow(m, n+1);
    else 
        return m * recursive_pow(m, n-1);
}


float input_float(char* str) {
    float num;
    cout << "Enter the number " << str << ": ";
    cin >> num;
    return num; 
}


int main() {
    cout << "Hello buddy! u'are here for making the recursive pow (M^N). sounds cool, right? let's try :P\n" << endl;

    float m = input_float((char*)"M");
    float n = input_float((char*)"N");

    float res = recursive_pow(m, n);

    cout << "The result should be this one: " << res << endl;

    return 0;
}