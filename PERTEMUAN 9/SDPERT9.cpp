#include <iostream>
#include <cstdlib>
using namespace std;

struct SIMPUL {
    int INFO;
    SIMPUL *LINK;
};

SIMPUL* BUAT_SIMPUL(int x) {
    SIMPUL *P = new SIMPUL;   // gunakan new
    if (P != nullptr) {
        P->INFO = x;
        P->LINK = nullptr;
    } else {
        cout << "Pembuatan Simpul Gagal" << endl;
    }
    return P;
}

int main() {
    int x;
    cout << "Masukan Data : ";
    cin >> x;
    SIMPUL *P = BUAT_SIMPUL(x);
    if (P != nullptr)
        cout << "Data : " << P->INFO << endl;
    return 0;
}
