#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void enqueue(char value) {
    Node* newNode = new Node{value, NULL};
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (!front) return;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (!front) rear = NULL;
}

void display() {
    Node* temp = front;
    cout << "Queue: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue('A');
    enqueue('B');
    enqueue('C');
    display();

    dequeue();
    display();

    enqueue('D');
    display();

    return 0;
}
