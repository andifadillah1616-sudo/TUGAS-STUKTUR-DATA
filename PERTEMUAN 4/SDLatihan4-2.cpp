#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;
    int data;

    cout << "=== PUSH DATA ===\n";
    while (true) {
        cout << "Masukkan data (999 untuk berhenti): ";
        cin >> data;
        if (data == 999) break;
        if (top < MAX - 1) {
            S[++top] = data;
            cout << "Data " << data << " di-PUSH.\n";
        } else {
            cout << "Stack PENUH!\n";
            break;
        }
    }

    cout << "\n=== POP DATA ===\n";
    while (top >= 0) {
        cout << "Data yang diambil: " << S[top--] << endl;
    }

    cout << "Stack sekarang kosong.\n";
    return 0;
}
