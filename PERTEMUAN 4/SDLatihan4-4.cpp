#include <iostream>
using namespace std;

int main() 
{
    const int MAX = 10;
    int S[MAX] = {11,22,33,44,55,66,77,88,99,100};
    int top = MAX - 1;

    cout << "Isi stack (POP):\n";
    while (top >= 0) 
	{
        cout << S[top--] << endl;
    }
    cout << "Stack Kosong.\n";

    return 0;
}
