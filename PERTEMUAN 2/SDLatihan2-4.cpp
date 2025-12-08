#include <iostream>
using namespace std;

int main() 
{
    cout << "Array: long x[12][14]" << endl;
    cout << "Diketahui: &x[0][0] = 1000 H" << endl;
    cout << "Ukuran long = 8 byte (diasumsikan 64-bit system)" << endl;
    cout << "Ditanya: &x[2][4] = ?" << endl << endl;

    int alamat_awal = 0x1000;
    int ukuran_long = 8;

    int baris = 2, kolom = 4;
    int jumlah_kolom = 14;

    int index_target = (baris * jumlah_kolom) + kolom;
    int alamat_x24 = alamat_awal + (index_target * ukuran_long);

    cout << "Rumus: &x[i][j] = &x[0][0] + ((i * jumlah_kolom) + j) x ukuran long" << endl;
    cout << "       &x[2][4] = 1000 H + ((2 * 14) + 4) x 8" << endl;
    cout << "       &x[2][4] = 1000 H + (28 + 4) x 8" << endl;
    cout << "       &x[2][4] = 1000 H + (32 x 8)" << endl;
    cout << "       &x[2][4] = 1000 H + 256 (desimal)" << endl;
    cout << "       &x[2][4] = 1000 H + 0x100 (hex)" << endl;
    cout << "Jawab  &x[2][4] = " << hex << alamat_x24 << " H" << endl;

    return 0;
}

