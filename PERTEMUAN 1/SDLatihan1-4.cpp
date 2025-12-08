#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    float x1, y1, x2, y2;

    cout << "Masukkan koordinat A (x y): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat B (x y): ";
    cin >> x2 >> y2;
    float jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Jarak antara A dan B = " << jarak << endl;

    return 0;
}
