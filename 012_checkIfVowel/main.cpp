/* Obiettivo:
    Creare un programma che fa inserire all'utente un carattere, e verifica che il carattere immesso sia una vocale o
    meno, utilizzando lo statement "switch".
*/

#include <iostream>

using namespace std;

int main() {

   cout << "This program checks if a character given as input is a vowel." << endl;
   cout << "=====================================" << endl;

   char cha;
   cout << "Enter the character: ";
   cin >> cha;

   bool vow = false;

   switch (cha) {
       case 'a': vow = true; break;
       case 'e': vow = true; break;
       case 'i': vow = true; break;
       case 'o': vow = true; break;
       case 'u': vow = true; break;
       case 'A': vow = true; break;
       case 'E': vow = true; break;
       case 'I': vow = true; break;
       case 'O': vow = true; break;
       case 'U': vow = true; break;
   }

   cout << "=====================================" << endl;
   cout << "The character '" << cha << "' IS" << ((!vow)? " NOT " : " ") << "a vowel." << endl;

    return 0;
}
