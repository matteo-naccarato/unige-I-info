// Obiettivo: stampare a video la somma di due numeri presi in input

#include <iostream>
#include <stdlib.h> // atoi()
using namespace std;

int main(int argc, char* argv[]) {
	
	if (argc != 1 && argc != 3) {
		cout << "USAGE: " << argv[1] << " NUM1, NUM2" << endl;
		return -1;
	}
	
	// INIZIALIZZAZIONE
	int a = 0, b = 0, sum = 0; 
	
	if (argc == 3) {
		// CMD PARAMS
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	} else {
		// input presi da tastiera dopo aver fatto eseguito il programma
		cout << "Insert two integers to make the sum\n";
		cout << "===================\n";
		cout << "First addend: "; 
		cin >> a;
		cout << "Second addend: ";
		cin >> b;
		cout << "===================\n";
		
		// cout << "Inserire due numeri interi ... " << endl;
		// cout << "Primo numero: ";
		// cin >> a;
		// cout << "Secondo numero: ";
		// cin >> b;
		
		// cin >> a >> b;
	}
	
	sum = a + b;	
	cout << "[SUM] " << a << " + " << b << " = " << sum << endl;
	
	return 0;
}
