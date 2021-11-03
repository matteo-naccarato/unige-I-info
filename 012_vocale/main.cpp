/*
Obiettivo:


*/

#include <iostream>

using namespace std;

int main() {

   cout << "Controllo vocale" << endl;
   char chal;
   cout << "Inserire un carattere: ";
   cin >> chal;

   bool voc = false;

   switch (chal) {
       case 'a': voc = true; break;
       case 'e': voc = true; break;
       case 'i': voc = true; break;
       case 'o': voc = true; break;
       case 'u': voc = true; break;
       case 'A': voc = true; break;
       case 'E': voc = true; break;
       case 'I': voc = true; break;
       case 'O': voc = true; break;
       case 'U': voc = true; break;
   }

   cout << "Il carattere '" << chal << "' " << ((!voc)? " NON " : "") << " e' una vocale." << endl;

    return 0;
}
