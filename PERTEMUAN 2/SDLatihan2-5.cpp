#include <iostream>
using namespace std;

int main() {
	cout << "Array 3D: int x[2][3][5]" << endl;
    cout << "Diketahui: &x[1][1][4] = 12EF H" << endl;
    cout << "Ukuran int = 4 byte" << endl;
    cout << "Ditanya: &x[0][0][3] = ?" << endl;
    
    int alamat_114 = 0x12EF; 
	int ukuran_int = 4; 
    int posisi_114 = (1*3*5) + (1*5) + 4;  
    int posisi_003 = (0*3*5) + (0*5) + 3;  
    int alamat_003 = alamat_114 - ((posisi_114 - posisi_003) * ukuran_int);
    
    cout << "Posisi linear x[1][1][4] = 1x3x5 + 1x5 + 4 = 24" << endl;
    cout << "Posisi linear x[0][0][3] = 0x3x5 + 0x5 + 3 = 3" << endl;
    cout << "Selisih posisi = 24 - 3 = 21" << endl;
    cout << "Rumus: &x[0][0][3] = &x[1][1][4] - (21 x ukuran int)" << endl;
    cout << "       &x[0][0][3] = 12EF H - (21 x 4)" << endl;
    cout << "       &x[0][0][3] = 12EF H - 54 H" << endl;
    cout << "Jawab: &x[0][0][3] = " << hex << alamat_003 << " H" << endl;
    
    return 0;
}

