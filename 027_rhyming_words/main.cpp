/* Obiettivo:

*/

#include <iostream>
#include <cstring>
#define MAX_STR 256

using namespace std;


int main() {

    cout << "This program ..." << endl;
    cout << "=====================" << endl;

    char str1[MAX_STR], str2[MAX_STR];
    int cnt = 0;
    cout << "Enter the first word: ";
    cin.getline(str1, MAX_STR, '\n');
    cout << "Enter the second word: ";
    cin.getline(str2, MAX_STR, '\n');

    for (int index1=strlen(str1)-1, index2=strlen(str2)-1; index1>=0 && index2>=0; index1--, index2--) {
        if (isalpha(str1[index1]) && isalpha(str2[index2])) {
            if (str1[index1] == str2[index2])
                cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}
