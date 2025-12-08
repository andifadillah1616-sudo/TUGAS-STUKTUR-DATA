#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
 	int temp = *xp;
	*xp = *yp;
 	*yp = temp;
}

// Fungsi untuk mengimplementasikan bubble sort
void bubbleSort(int arr[], int n)
{
 	int i, j;
 	for (i = 0; i < n-1; i++)

 // Elemen terakhir i sudah ada
	for (j = 0; j < n-i-1; j++)
 		if (arr[j] > arr[j+1])
 			swap(&arr[j], &arr[j+1]);
}

/* Fungsi untuk mencetak array */
void printArray(int arr[], int size)
{
 	int i;
 	for (i = 0; i < size; i++)
 		cout << arr[i] << " ";
 	cout << endl;
}

// Kode eksekusi
int main()
{
 	int arr[] = {64, 34, 25, 12, 22, 11, 90};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	bubbleSort(arr, n);
	cout<<"Array yang diurutkan: \n";
 	printArray(arr, n);
 	return 0;
} 
