/* Obiettivo:
I file temperatura1.txt e temperatura2.txt riportano per ciascuna riga le temperature misurate in due motori, motore1 e motore2, durante un test. I motori vengono fatti funzionare in parallelo e le temperature sono misurate allo stesso istante di tempo. Le temperature sono rappresentate con numeri reali. Il numero di righe che compongono i file non è noto al programmatore. Tuttavia, è noto che i due file contengono lo stesso numero di righe. Si scriva un programma C++ che legga i file temperatura1.txt e temperatura2.txt, calcoli e stampi a video la percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2.

Esempio:
Se il contenuto dei file temperatura1.txt  e temperatura2.txt è il seguente:

temperatura1.txt

temperatura2.txt

70

80

82

83

83

75

78

80

82

85

la percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 è del 60%.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream fin1, fin2;
    fin1.open("temperatura1.txt", ios::in);
    if (!fin1) {
        cout << "Errore durante l'apertura del file" << endl;
        return -1;
    }

    int n_rows = 0;
    while (!fin1.eof()) {
        int temp;
        fin1 >> temp;
        cout << temp << endl;
        n_rows++;
    }
    fin1.close();
    fin1.open("temperatura1.txt", ios::in);
    if (!fin1) {
        cout << "Errore durante l'apertura del file" << endl;
        return -1;
    }
    int temps1[n_rows], temps2[n_rows];
    for (int i=0; !fin1.eof() && i<n_rows; i++) {
        fin1 >> temps1[i];
    }
    fin2.open("temperatura2.txt", ios::in);
    if (!fin2) {
        cout << "Errore durante l'apertura del file" << endl;
        return -1;
    }
    for (int i=0; !fin2.eof() && i<n_rows; i++) {
        fin2 >> temps2[i];
    }
    fin1.close();
    fin2.close();


    int cnt = 0;
    for (int i=0; i<n_rows; i++) {
        if (temps1[i] > temps2[i]) cnt++;
    }
    float perc = (float) cnt/n_rows;
    cout << "La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 e' del " << (perc*100) << "%." << endl;

    return 0;
}

