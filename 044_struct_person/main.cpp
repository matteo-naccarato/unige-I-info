/* Obiettivo:
    Il programma definisce una struct persona con campi nome, età, altezza e peso.
    Successivamente, chiede all'utente di inserire i dati di tre persone.
    Infine, restituisce il nome della persona più alta e della persona più giovane.
    E' possibile risolvere l'esercizio con un array di strutture persona, o utilizzando tre struct persona. Utilizzando gli
    array, è però più semplice risalire alla persona più alta e quella più giovane.
*/

#include <iostream>
#include <cstdio> // for fflush

using namespace std;

const int MAX_STR = 256;
const int N = 3;

struct Person {
    char name[MAX_STR];
    char age[MAX_STR];
    float height;
    float weight;
};

Person input_person_data();
Person get_tallest(Person people[], int n);
Person get_youngest(Person people[], int n);

int main() {

    cout << "This program shows the name of the tallest person and the youngest one among a group of three people." << endl;
    cout << "============================" << endl;

    Person people[N];
    for (int i=0; i<N; i++) {
        people[i] = input_person_data();
    }

    Person tallest = get_tallest(people, N);
    cout << "---------\nThe name of the tallest person is: " << tallest.name << endl;
    Person youngest = get_youngest(people, N);
    cout << "The name of the youngest person is: " << youngest.name << endl;

    return 0;
}

Person get_tallest(Person people[], int n) {
    Person p_tallest = people[0];
    for (int i=1; i<n; i++) {
        if (people[i].height > p_tallest.height) {
            p_tallest = people[i];
        }
    }
    return p_tallest;
}

Person get_youngest(Person people[], int n) {
    Person p_youngest = people[0];
    for (int i=1; i<n; i++) {
        if (people[i].age < p_youngest.age) {
            p_youngest = people[i];
        }
    }
    return p_youngest;
}

Person input_person_data() {
    Person ret;
    cout << "---------\nPerson:" << endl;
    cout << "\tName: ";
    cin.getline(ret.name, MAX_STR, '\n');
    fflush(stdin);
    cout << "\tAge: ";
    cin.getline(ret.age, MAX_STR, '\n');
    fflush(stdin);
    cout << "\tHeight (in cms): ";
    cin >> ret.height;
    fflush(stdin);
    cout << "\tWeight (in Kgs): ";
    cin >> ret.weight;
    fflush(stdin);
    return ret;
}
