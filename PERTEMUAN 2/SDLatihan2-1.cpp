#include <iostream>
using namespace std;

int main() 
{
    cout << "Menghitung alamat elemen array berdasarkan alamat awal" << endl << endl;
    cout << "Array: char x[12]" << endl;
    cout << "Diketahui: &x[0] = 1000 H" << endl;
    cout << "Ukuran char = 1 byte" << endl;
    cout << "Ditanya: &x[8] = ?" << endl;
    
    int alamat_x0 = 0x1000;
    int ukuran_char = 1;
    int alamat_x8 = alamat_x0 + (8 * ukuran_char);
    
    cout << "Rumus: &x[8] = &x[0] + (8 x ukuran char)" << endl;
    cout << "       &x[8] = 1000 H + (8 x 1)" << endl;
    cout << "       &x[8] = 1000 H + 8 H" << endl;
    cout << "Jawab: &x[8] = " << hex << alamat_x8 << " H" << endl << endl;
    
    return 0;
}
