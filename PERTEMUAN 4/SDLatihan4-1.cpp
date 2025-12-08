#include <iostream>

using namespace std;
int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;
    int data;

    while (true) {
        cout << "Input data: ";
        cin >> data;

        if (data == 999) {
            cout << "Proses selesai.\n";
            break;
        }
        else if (data >= 60) { 
            if (top < MAX-1) {
                S[++top] = data;
                cout << "PUSH " << data << " ke stack.\n";
            } else {
                cout << "Stack Penuh!\n";
                break;
            }
        }
        else {
            if (top >= 0) {
                cout << "POP " << S[top--] << " dari stack.\n";
            } else {
                cout << "Stack Kosong!\n";
                break;
            }
        }
    }
    return 0;
}
