#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    cout << "a vale " << a << endl;

    {
        int a = 20;
        cout << "a vale " << a << endl;
    }

    cout << "a vale " << a << endl;

    return 0;
}
