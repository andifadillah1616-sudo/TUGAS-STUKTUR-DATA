#include <iostream>
using namespace std;

int main() 
{
    cout << "Array: float x[5][8]" << endl;
    cout << "Diketahui: &x[0][0] = 1000 H" << endl;
    cout << "Ukuran float = 4 byte" << endl;
    cout << "Ditanya: &x[2][4] = ?" << endl << endl;

    int alamat_awal = 0x1000;
    int ukuran_float = 4;

    
    int index_target = (2 * 8) + 4;
    int alamat_x24 = alamat_awal + (index_target * ukuran_float);

    cout << "Rumus: &x[i][j] = &x[0][0] + ((i * kolom) + j) x ukuran float" << endl;
    cout << "       &x[2][4] = 1000 H + ((2 * 8) + 4) x 4" << endl;
    cout << "       &x[2][4] = 1000 H + (16 + 4) x 4" << endl;
    cout << "       &x[2][4] = 1000 H + (20 x 4)" << endl;
    cout << "       &x[2][4] = 1000 H + 50" << endl;
    cout << "Jawab  &x[2][4] = " << hex << alamat_x24 << " H" << endl;

    return 0;
}

