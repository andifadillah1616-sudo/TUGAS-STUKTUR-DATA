#include <iostream>
#include <cstdlib>
using namespace std;

// Deklarasikan node linked list
struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

// Fungsi push
void push(int data) {
    struct Node* temp = new Node();

    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty() {
    return top == NULL;
}

// Mengambil elemen paling atas
int peek() {
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Menghapus elemen paling atas (pop)
void pop() {
    struct Node* temp;

    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

// Menampilkan seluruh elemen stack
void display() {
    struct Node* temp;

    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    } else {
        temp = top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        
    }
}

// Program utama
int main() {
    push(11);
    push(22);
    push(33);
    push(44);

    display();

    cout << "\nElemen Top adalah " << peek() << endl;

    pop();
    pop();

    display();

    cout << "\nElemen Top adalah " << peek() << endl;

    return 0;
}
