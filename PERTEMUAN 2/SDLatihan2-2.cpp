#include <iostream>
using namespace std;

int main() 
{
    cout << "Array: int x[15]" << endl;
    cout << "Diketahui: &x[3] = 1000 H" << endl;
    cout << "Ukuran int = 4 byte" << endl;
    cout << "Ditanya: &x[9] = ?" << endl << endl;

    int alamat_x3 = 0x1000; 
    int ukuran_int = 4;

    int selisih_index = 9 - 3;
    int alamat_x9 = alamat_x3 + (selisih_index * ukuran_int);

    cout << "Rumus: &x[9] = &x[3] + ((9 - 3) x ukuran int)" << endl;
    cout << "       &x[9] = 1000 H + (6 x 4)" << endl;
    cout << "       &x[9] = 1000 H + 18" << endl;
    cout << "Jawab: &x[9] = " << hex << alamat_x9 << " H" << endl;

    return 0;
}

