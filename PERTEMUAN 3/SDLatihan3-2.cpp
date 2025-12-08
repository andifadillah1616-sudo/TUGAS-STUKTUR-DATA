#include <iostream>
using namespace std;

struct Mahasiswa
 {
    int no_urut;
    string nama;
    int umur;
};

int main()
{
    const int jumlah = 5;
    Mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++)
	{
        mhs[i].no_urut = i + 1;
        cout << "Mahasiswa ke-" << mhs[i].no_urut << endl;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "Umur  : ";
        cin >> mhs[i].umur;
        cout << endl;
    }

    cout << "\n=== Data Mahasiswa No Urut 2 ===\n";
    cout << "No Urut : " << mhs[1].no_urut << endl;
    cout << "Nama    : " << mhs[1].nama << endl;
    cout << "Umur    : " << mhs[1].umur << endl;

    return 0;
}

