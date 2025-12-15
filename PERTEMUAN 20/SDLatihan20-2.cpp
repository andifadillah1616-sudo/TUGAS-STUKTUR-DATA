#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node{value, NULL};
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void del(int value) {
    if (!head) return;
    Node *curr = head, *prev = NULL;

    do {
        if (curr->data == value) {
            if (prev) prev->next = curr->next;
            else {
                Node* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

void traverse() {
    if (!head) return;
    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();

    del(20);
    traverse();

    return 0;
}
