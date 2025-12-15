#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &steps) {
    int left = 0, right = n - 1;
    steps = 0;

    while (left <= right) {
        steps++;
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int data[15] = {3,7,12,18,25,30,35,40,44,50,55,60,65,70,80};
    int key = 40, steps;

    int index = binarySearch(data, 15, key, steps);

    cout << "Angka dicari: " << key << endl;
    cout << "Index: " << index << endl;
    cout << "Jumlah langkah: " << steps << endl;

    return 0;
}
