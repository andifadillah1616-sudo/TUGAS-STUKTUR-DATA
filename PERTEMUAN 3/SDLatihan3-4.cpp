#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int nomorAkses;
    string penulis;
    string judul;
    bool diterbitkan;
};

int main() {
    Buku buku1;

    cout << "Masukkan nomor akses buku: ";
    cin >> buku1.nomorAkses;
    cin.ignore();
    
    cout << "Masukkan nama penulis: ";
    getline(cin, buku1.penulis);
    
    cout << "Masukkan judul buku: ";
    getline(cin, buku1.judul);

    char status;
    cout << "Apakah buku diterbitkan? (y/n): ";
    cin >> status;
    buku1.diterbitkan = (status == 'y' || status == 'Y');

    cout << "\n=== Data Buku ===\n";
    cout << "Nomor Akses : " << buku1.nomorAkses << endl;
    cout << "Penulis     : " << buku1.penulis << endl;
    cout << "Judul Buku  : " << buku1.judul << endl;
    cout << "Status      : ";
    if (buku1.diterbitkan)
        cout << "Sudah diterbitkan" << endl;
    else
        cout << "Belum diterbitkan" << endl;

    return 0;
}

