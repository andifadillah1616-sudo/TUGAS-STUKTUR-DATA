#include <bits/stdc++.h>  
using namespace std;   
// Sebuah fungsi utility untuk menukar 2 elemen   
void swap(int* a, int* b)   
{ 
	int t = *a;
	*a = *b;
	*b = t;  
}  
int partition (int arr[], int low, int high)  
{   
    int pivot = arr[high]; // pivot   
    int i = (low - 1); // Indeks elemen yang lebih kecil 
   
    for (int j = low; j <= high - 1; j++)   
    {   
         
        // Jika elemen saat ini lebih kecil dari pivot   
        if (arr[j] < pivot)   
        {   
            i++; // indeks kenaikan dari elemen yang lebih kecil   
            swap(&arr[i], &arr[j]);   
        }   
    }   
    swap(&arr[i + 1], &arr[high]);   
    return (i + 1);   
}   
   
/* Fungsi utama yang mengimplementasikan QuickSort 
arr [] -> Array untuk diurutkan, 
rendah -> Indeks awal, 
tinggi -> Indeks akhir */ 
void quickSort(int arr[], int low, int high)   
{   
    if (low < high)   
    {   
        /* pi adalah indeks partisi, arr [p] sekarang di tempat yang benar */ 
        int pi = partition(arr, low, high);   
   
        // Urutkan elemen sebelumnya secara terpisah 
        // partisi dan setelah partisi  
        quickSort(arr, low, pi - 1);   
        quickSort(arr, pi + 1, high);   
    } 
    }   
   
/* Fungsi untuk mencetak array */ 
void printArray(int arr[], int size)   
{   
    int i;   
    for (i = 0; i < size; i++)   
        cout << arr[i] << " ";   
    cout << endl;   
}   
   
// Kode untuk mengeksekusi 
int main()   
{   
    int arr[] = {10, 7, 8, 9, 1, 5};   
    int n = sizeof(arr) / sizeof(arr[0]);   
    quickSort(arr, 0, n - 1);   
    cout << "Array yang diurutkan: \n";   
    printArray(arr, n);   
    return 0;   
}
