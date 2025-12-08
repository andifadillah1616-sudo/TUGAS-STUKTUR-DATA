#include <iostream>
using namespace std;

int main()
{
    const int MAX = 10;
    int S[MAX];
    int top = -1;
    int data;

    cout << "Masukkan data (akan berhenti jika stack penuh):\n";
    while (top < MAX-1) 
	{
        cin >> data;
        S[++top] = data;
    }
    cout << "Stack Penuh, tidak bisa diisi lagi.\n";

    return 0;
}
