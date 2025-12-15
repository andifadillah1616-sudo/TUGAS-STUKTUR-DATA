#include <stdio.h>  
#include <stdlib.h>  
   
// Menggabungkan dua subarrays dari arr []. 
// Subarray pertama adalah arr [l..m] 
// Subarray kedua adalah arr [m + 1..r]  
void merge(int arr[], int l, int m, int r)  
{  
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
      /* buat array temp */ 
    int L[n1], R[n2];  
   
    /* Salin data ke array temp L [] dan R [] */ 
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
   
   /* Salin data ke array temp L [] dan R [] */ 
    i = 0; // Indeks awal dari subarray pertama  
    j = 0; // Indeks awal dari subarray kedua  
    k = l; // Indeks awal dari sub-array gabungan  
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
   
    /* Salin sisa elemen L [], jika ada */ 
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
   /* Salin sisa elemen R [], jika ada */ 
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  
}  
   
/* l untuk indeks kiri dan r adalah indeks kanan dari sub-array arr yang akan 
diurutkan */ 
void mergeSort(int arr[], int l, int r)  
{  
    if (l < r) {  
        // Sama dengan (l + r) / 2, tetapi menghindari overflow for 
        // besar l dan h 
        int m = l + (r - l) / 2;  
   
        // Urutkan bagian pertama dan kedua 
        mergeSort(arr, l, m);  
        mergeSort(arr, m + 1, r);  
   
        merge(arr, l, m, r);  
    }  
}  
/* UTILITY FUNCTIONS */ 
/* Fungsi untuk mencetak array */ 
void printArray(int A[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
  printf("%d ", A[i]);  
    printf("\n");  
}  
   
/* kode untuk mengeksekusi */ 
int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6, 7 };  
    int arr_size = sizeof(arr) / sizeof(arr[0]);  
   
    printf("Array yang diberikan adalah \n");  
    printArray(arr, arr_size);  
   
    mergeSort(arr, 0, arr_size - 1);  
   
    printf("\nArray yang diurutkan adalah \n");  
    printArray(arr, arr_size);  
    return 0;  
} 
