/* Obiettivo:
    Creare un programma che chieda all’utente di inserire due stringhe, le concateni, elimini tutti i caratteri non
    alfabetici, e conti il numero di doppie contenute nella stringa complessiva.
*/

#include <iostream>
#include <cstring>
#define MAX_STR 256

using namespace std;

void remove_and_transpose(char str[], int len, int indexToRemove);

int main() {
    cout << "This program ..." << endl;
    cout << "=================================" << endl;

    char str1[MAX_STR/2];
    char str2[MAX_STR/2];
    char* str_cat;
    int len_strcat;

    cout << "Enter the first string: ";
    cin.getline(str1, MAX_STR/2, '\n');
    cout << "Enter the second string: ";
    cin.getline(str2, MAX_STR/2, '\n');

    str_cat = strcat(str1, str2);
    len_strcat = strlen(str_cat);
    cout << "Concatenated string: " << str_cat << endl;

    for (int i=0; i<len_strcat; i++) {
        while (i<len_strcat && !isalpha(str_cat[i])) {
            remove_and_transpose(str_cat, len_strcat, i);
            len_strcat--;
        }
    }
    cout << "Concatenated string (with only alphabet letters): " << str_cat << endl;



    // PROBLEM with: ppppp => doubles = 1 !!!!

    int cnt_doubles = 0;
    for (int i=0; i<len_strcat-1; i++) {
        if (str_cat[i] == str_cat[i+1] && ((i!=0)?(str_cat[i] != str_cat[i-1]):1)) {
            cnt_doubles++;
        }
    }
    cout << "The number of double letters is: " << cnt_doubles << endl;


    return 0;
}

void remove_and_transpose(char str[], int len, int indexToRemove) {
    for (int i=indexToRemove; i<len; i++) {
        str[i] = str[i+1];
    }
    str[len-1] = '\0';
}
