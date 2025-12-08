#include <iostream>
#include <vector>
using namespace std;

struct Buku {
    string judul, penulis;
    int jumlah;
};

vector<Buku> perpustakaan;

void tampil() {
    if (perpustakaan.empty()) return void(cout << "Perpustakaan kosong!\n");
    for (int i = 0; i < perpustakaan.size(); i++)
        cout << i+1 << ". " << perpustakaan[i].judul << " | " 
             << perpustakaan[i].penulis << " | Stok: " 
             << perpustakaan[i].jumlah << endl;
}

void tambah() {
    Buku b;
    cin.ignore();
    cout << "Judul: "; getline(cin, b.judul);
    cout << "Penulis: "; getline(cin, b.penulis);
    cout << "Jumlah: "; cin >> b.jumlah;
    perpustakaan.push_back(b);
    cout << "Buku ditambahkan!\n";
}

void cariPenulis() {
    string p; bool ada = false;
    cin.ignore();
    cout << "Nama penulis: "; getline(cin, p);
    for (auto &b : perpustakaan)
        if (b.penulis == p) cout << "- " << b.judul << " (" << b.jumlah << ")\n", ada = true;
    if (!ada) cout << "Tidak ditemukan.\n";
}
void jumlahJudul() {
    string j; int total = 0;
    cin.ignore();
    cout << "Judul: "; getline(cin, j);
    for (auto &b : perpustakaan)
        if (b.judul == j) total += b.jumlah;
    cout << "Total buku \"" << j << "\": " << total << endl;
}

void total() {
    int t = 0;
    for (auto &b : perpustakaan) t += b.jumlah;
    cout << "Jumlah semua buku: " << t << endl;
}

void terbit() {
    string j;
    cin.ignore();
    cout << "Judul yang diterbitkan: "; getline(cin, j);
    for (auto &b : perpustakaan)
        if (b.judul == j) return void((b.jumlah>0 ? b.jumlah--, cout<<"Terbit! Sisa: "<<b.jumlah<<endl :
		cout<<"Stok habis!\n"));
    cout << "Buku tidak ditemukan.\n";
}

int main() {
    int p;
    do {
        cout << "\n=== Menu Perpustakaan ===\n"
             << "1. Tampilkan semua buku\n2. Tambah buku\n3. Cari penulis\n"
             << "4. Cek jumlah judul\n5. Total buku\n6. Terbitkan\n0. Keluar\nPilih: ";
        cin >> p;
        switch (p) {
            case 1: tampil(); break;
            case 2: tambah(); break;
            case 3: cariPenulis(); break;
            case 4: jumlahJudul(); break;
            case 5: total(); break;
            case 6: terbit(); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (p != 0);
    
    return 0;
}
