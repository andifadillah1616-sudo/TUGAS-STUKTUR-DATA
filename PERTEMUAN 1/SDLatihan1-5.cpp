#include <iostream>
using namespace std;

int main() 
{
    int A, B, temp;
    
    cout << "Masukkan nilai A: ";
    cin >> A;
    cout << "Masukkan nilai B: ";
    cin >> B;

    temp = A;
    A = B;
    B = temp;

    cout << "Setelah ditukar:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    return 0;
}
