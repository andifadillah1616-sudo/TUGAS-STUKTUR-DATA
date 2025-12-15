#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int data[10];
    srand(time(0));

    cout << "Data awal: ";
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100;
        cout << data[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                cout << "Tukar: ";
                for (int k = 0; k < 10; k++)
                    cout << data[k] << " ";
                cout << endl;
            }
        }
    }

    cout << "Data terurut: ";
    for (int i = 0; i < 10; i++)
        cout << data[i] << " ";

    return 0;
}
