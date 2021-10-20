// Obiettivo:
//  Creare un programma in c++ che chieda all’utente di inserire cinque interi e ne stampi a terminale la
//  media (approssimandola ad intero).

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define MAX_STR 1024

using namespace std;

// char* array_toString(int[], int);
void print_array(int[], int);

int main(){
    int nums[N] = {0}, sum = 0, avg = 0;
    const char* ORD[N] = { "first", "second", "third", "fourth", "fifth" };

    cout << "This program will calculate the average (int) of " << N << " integers ..." << endl;
    cout << "========================" << endl;

    for (int i=0; i<N; i++) {
        cout << "Insert the " << ORD[i] << " number: ";
        cin >> nums[i];
        sum += nums[i];
    }

    cout << "========================" << endl;
    avg = sum / N;
    // char* tmp = array_toString(nums, N);
    cout << "The average of the numbers ";
    print_array(nums, N);
    cout << "is (" << avg << ")" << endl;

    return 0;
}

void print_array(int arr[], int len) {
    for (int i=0; i<len; i++) {
        cout << arr[i] << "; ";
    }
}

/* char* array_toString(int arr[], int len) {
    char* toString = (char*) malloc(sizeof(char) * MAX_STR);
    toString[0] = '\0';
    char temp[MAX_STR];
    cout << "INIZIO: " << toString << endl;
    for (int i=0; i<len; i++) {
        sprintf(temp, "%d", arr[i]);
        strcat(toString, temp);
        cout << toString << endl;
    }
    toString[len] = '\0';
    return toString;
} */
