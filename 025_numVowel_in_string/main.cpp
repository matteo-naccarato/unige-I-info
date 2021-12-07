/* Obiettivo:
    Funzione che calcoli il numero di vocali ('a', 'e', 'i', 'o', 'u')
    contenute in una stringa.
    Supponiamo che i caratteri siano minuscoli
*/

#include <iostream>
#include <cstring>

#define MAX_STR 1024

using namespace std;

int cntVowels(char s[], int& cntConsonants, int& cntOthers);
int isVowel(char ch);

int main() {

    cout << "This countes the number of vowels in a phrase given as input." << endl;
    cout << "===========================================" << endl;

    char str[MAX_STR];
    int cntVow = 0, cntCons = 0, cntOthers = 0;
    cout << "Enter the string: ";
    cin.getline(str, MAX_STR, '\n');
    strlwr(str);
    cntVow = cntVowels(str, cntCons, cntOthers);


    cout << "===========================================" << endl;
    cout << "The phrase \"" << str << "\" contains " << cntVow << " vowels, " << cntCons << " consonants and " << cntOthers << " other characters." << endl;

    return 0;
}

int cntVowels(char s[], int& cntConsonants, int& cntOthers) {
    int cntVow = 0, cntCons = 0;
    for (int i=0; s[i] != '\0'; i++) {
        switch (isVowel(s[i])) {
        case -1: cntOthers++; break;
        case 0: cntCons++; break;
        case 1: cntVow++; break;
        }
    }
    cntConsonants = cntCons;
    return cntVow;
}

/*
-1: NOT a lower letter
0: lower CONSONANT
1: lower VOWEL
*/
int isVowel(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    return -1;

}
