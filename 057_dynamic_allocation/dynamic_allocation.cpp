#include <iostream>
#include <cstring>

using namespace std;

const int NAME_MAX = 256;

struct Obj {
    char name[NAME_MAX];
    float price;
};


int input_array_length() {
    int n = -1;
    int err = -1;
    do {
        err = 0;
        cout << "Enter the dim: ";
        cin >> n;
        if (n<0) {
            cout << "ERR | input not valid." << endl;
            err = 1;
        }
    } while (err);
    return n;
}

void print_obj_data(Obj* obj) {
    cout << "{ name:\"" << obj->name << "\", price:" << obj->price <<  " }";
}

void input_obj_data(Obj* arr, int i) {
    cout << "\t\t- name: ";
    cin >> (arr+i)->name;
    float pr = -1;
    do {
        cout << "\t\t- price: ";
        cin >> pr;
        if (pr < 0) cout << "\t\t\tERR | price not valid." << endl;
        else (arr+i)->price = pr;
    } while (pr < 0);
}

void input_store_array(Obj* arr, int n, char* str) {
    cout << "Enter the elements for the " << str << " array: " << endl;
    for (int* pi=(int*)arr; pi-(int*)arr < n; pi++) {
        cout << "\t- obj#" << (pi-(int*)arr) << ":" << endl;
        input_obj_data(arr, pi-(int*)arr);
    }
}



void print_array(Obj* arr, int n, char* str) {
    cout << str << " = [\n\t";
    for (Obj* pi=arr; (int)(pi-arr) < n; pi++) {
        print_obj_data(pi);
        cout << ",\n\t";
    }
    cout << "\b\b\b\b\n ]" << endl;
}

void store_cpy(Obj* new_store, Obj* old_store, int dim) {
    for (Obj* pi=old_store; (int)(pi-old_store) < dim; pi++) {
        int temp_i = pi - old_store;
        strcpy((new_store + temp_i)->name, pi->name);
        (new_store + temp_i)->price = pi->price;
    }
}


int main() {

    int n = input_array_length();

    Obj* store = new Obj[n];
    if (store == 0) {
        cout << "ERR | dynamic allocation Obj*" << endl;
        return -1;
    }

    input_store_array(store, n, (char*) "STORE");

    print_array(store, n, (char*) "STORE");


    
    cout << "\n================================" << endl;
    int choice = -1;
    cout << "Do u wanna add another element in the store? if so, enter '1', otherwise any other number u like (excpet 1, pls :P): ";
    cin >> choice;
    if (choice == 1) {

        Obj* new_store = new Obj[n+1];
        if (new_store == 0) {
            cout << "ERR | dynamic allocation Obj*" << endl;
            return -1;
        }
        store_cpy(new_store, store, n);
        delete[] store;

        input_obj_data(new_store, n);
        print_array(new_store, n+1, (char*) "NEW_STORE");

        delete[] new_store;

    } else delete[] store;

    return 0;
}
