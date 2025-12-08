#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int noUrut;
    string nama;
    int umur;
    string alamat;
    float nilai;
};

int main() {
    Mahasiswa mhs[15];

    for (int i = 0; i < 15; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << ":\n";
        mhs[i].noUrut = i + 1;
        cout << "Nama: ";
        cin.ignore(); 
        getline(cin, mhs[i].nama);
        cout << "Umur: ";
        cin >> mhs[i].umur;
        cin.ignore();
        cout << "Alamat: ";
        getline(cin, mhs[i].alamat);
        cout << "Nilai: ";
        cin >> mhs[i].nilai;
        cout << endl;
    }

    cout << "\nData 15 Mahasiswa:\n";
    for (int i = 0; i < 15; i++) {
        cout << "No Urut: " << mhs[i].noUrut << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << "Alamat: " << mhs[i].alamat << endl;
        cout << "Nilai: " << mhs[i].nilai << endl;
        cout << "--------------------------\n";
    }

    return 0;
}

