// Program C++ linear search
#include<bits/stdc++.h>
using namespace std;

void search(vector<int> arr, int search_Element)
{
 int left = 0;
 int length = arr.size();
 int position = -1;
 int right = length - 1;

 // Jalankan putaran dari 0 ke kanan
 for(left = 0; left <= right;)
 {

 // Jika search_element ditemukan dengan
 // tersisa
 if (arr[left] == search_Element)
 {

 position = left;
 cout << "Elemen ditemukan dalam Array di "
 << position + 1 << " Posisikan dengan "
 << left + 1 << " Attempt";

 break;
 }

 // Jika search_element ditemukan dengan
 // Variabel benar
 if (arr[right] == search_Element)
 {
 position = right;
 cout << "Elemen ditemukan dalam Array di "
 << position + 1 << " Posisikan dengan "
 << length - right << " Attempt";

 break;
 }
 left++;
 right--;
 }

 // Jika elemen tidak ditemukan
 if (position == -1)
 cout << "Tidak ditemukan di Array dengan "
 << left << " Attempt";
}

// Driver code
int main()
{
 vector<int> arr{ 1, 2, 3, 4, 5 };
 int search_element = 5;

 // Function call
 search(arr, search_element);
}
