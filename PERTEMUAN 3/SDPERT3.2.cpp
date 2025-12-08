#include <iostream> 
using namespace std; 
 
struct Pribadi { 
    char nama[50]; 
    int usia; 
    int gaji; 
};

void displayData(Pribadi);   // Deklarasi Fungsi 
 
int main() { 
    Pribadi p; 
 
    cout << "Masukkan Nama Lengkap: "; 
    cin.get(p.nama, 50); 
    cout << "Masukkan Usia: "; 
    cin >> p.usia; 
    cout << "Enter Gaji: "; 
    cin >> p.gaji; 
 
    // Memanggil Fungsi dengan Struktur Variabel sebagai argumen 
    displayData(p); 
 
    return 0; 
} 
 
void displayData(Pribadi p) { 
    cout << "\nMenampilkan Informasi." << endl; 
    cout << "Nama: " << p.nama << endl; 
    cout <<"Usia: " << p.usia << endl; 
    cout << "Gaji: " << p.gaji; 
} 


