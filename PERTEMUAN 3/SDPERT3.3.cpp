#include <iostream> 
using namespace std; 
 
struct Pribadi { 
    char nama[50]; 
    int usia; 
    int gaji; 
}; 
 
Pribadi getData(Pribadi);  
void displayData(Pribadi);  
 
int main() { 
 
    Pribadi p; 
 
    p = getData(p);    
    displayData(p); 
 
    return 0; 
} 
 
Pribadi getData(Pribadi p) { 
 
    cout << "Masukkan Nama Lengkap: "; 
    cin.get(p.nama, 50); 
 
    cout << "Masukkan Usia: "; 
    cin >> p.usia; 
 
    cout << "Masukkan Gaji: "; 
    cin >> p.gaji; 
 
    return p; 
} 
 
void displayData(Pribadi p) { 
    cout << "\nMenampilkan Informasi." << endl; 
    cout << "Nama: " << p.nama << endl; 
    cout <<"Usia: " << p.usia << endl;
    cout << "Gaji: " << p.gaji; 
}

