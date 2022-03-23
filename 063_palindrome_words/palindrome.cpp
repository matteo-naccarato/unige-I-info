#include <iostream>
#include <cstring>

using namespace std;

const int MAX_WORD = 256;


bool inner_palindrome(char* str, int i) {
    if (i >= strlen(str)/2) return true;
    if (str[i] == str[(strlen(str)-1)-i])
        return true && inner_palindrome(str, ++i);
    else return false;
}

bool isPalindrome(char* str) {
    return inner_palindrome(str, 0);
}


int main() {

    char word[MAX_WORD];
    cout << "Enter a word to test if it's palindrome or not: ";
    cin.getline(word, MAX_WORD, '\n');

    cout << "\nThe word '" << word << "' " << ((isPalindrome(word))?"is":"isn't") << " palindrome." << endl;

    return 0;
}