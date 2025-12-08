#include <iostream>
using namespace std;

int main() 
{
    float panjang, lebar;

    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;

    float luas = panjang * lebar;
    float keliling = 2 * (panjang + lebar);

    cout << "Luas = " << luas << endl;
    cout << "Keliling = " << keliling << endl;

    return 0;
}

