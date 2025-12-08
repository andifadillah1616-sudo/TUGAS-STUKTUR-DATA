#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
 	int temp = *xp;
 	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
 	int i, j, min_idx;

 	// Satu per satu batas perpindahan subarray yang tidak disortir
 	for (i = 0; i < n-1; i++)
 	{
 		// Temukan elemen minimum dalam array yang tidak diurutkan
 		min_idx = i;
 		for (j = i+1; j < n; j++)
 		if (arr[j] < arr[min_idx])
 			min_idx;
 	// Tukar elemen minimum yang ditemukan dengan elemen pertama
	swap(&arr[min_idx], &arr[i]);
  }
}

/* Fungsi untuk mencetak sebuah array */
void printArray(int arr[], int size)
{
 	int i;
 	for (i=0; i < size; i++)
 		cout << arr[i] << " ";
 	cout << endl;
}

// kode program untuk eksekusi
int main()
{
 	int arr[] = {64, 25, 12, 22, 11};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	selectionSort(arr, n);
 	cout << "Array yang diurutkan: \n";
 	printArray(arr, n);
 	return 0;
} 
