#include <iostream>
#include <string>
using namespace std;

struct Node {
    string NIM;
    string NAMA;
    float NILAI;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void tambahData(string nim, string nama, float nilai) {
        Node* newNode = new Node();
        newNode->NIM = nim;
        newNode->NAMA = nama;
        newNode->NILAI = nilai;
        newNode->next = nullptr;
        if (head == nullptr || nilai < head->NILAI) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->NILAI <= nilai)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void tampilkanNilai90() {
        Node* current = head;
        bool found = false;
        cout << "\nData mahasiswa dengan NILAI = 90:\n";
        while (current != nullptr) {
            if (current->NILAI == 90) {
                cout << "NIM: " << current->NIM << ", Nama: " << current->NAMA << ", Nilai: " << current->NILAI << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "Tidak ada mahasiswa dengan nilai 90.\n";
    }

    void tampilkanSemua() {
        if (head == nullptr) {
            cout << "\nData kosong.\n";
            return;
        }
        cout << "\nDaftar seluruh data mahasiswa:\n";
        Node* current = head;
        while (current != nullptr) {
            cout << "NIM: " << current->NIM << ", Nama: " << current->NAMA << ", Nilai: " << current->NILAI << endl;
            current = current->next;
        }
    }

    void hapusData(string nim) {
        if (head == nullptr) {
            cout << "\nData kosong.\n";
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->NIM != nim) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "\nData dengan NIM " << nim << " tidak ditemukan.\n";
            return;
        }
        if (prev == nullptr)
            head = current->next;
        else
            prev->next = current->next;
        delete current;
        cout << "\nData dengan NIM " << nim << " berhasil dihapus.\n";
    }

    void hitungRata() {
        if (head == nullptr) {
            cout << "\nData kosong, tidak dapat menghitung rata-rata.\n";
            return;
        }
        float total = 0;
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            total += current->NILAI;
            count++;
            current = current->next;
        }
        cout << "\nNilai rata-rata kelas: " << (total / count) << endl;
    }
};

int main() 
{
    LinkedList daftar;
    daftar.tambahData("2007140001", "Ikhsan", 85);
    daftar.tambahData("2007140002", "Reza", 90);
    daftar.tambahData("2007140003", "Tera", 78);
    daftar.tambahData("2007140022", "Rani", 92);
    daftar.tambahData("2007140005", "Alka", 90);
    daftar.tampilkanSemua();
    daftar.tampilkanNilai90();
    daftar.hapusData("2007140022");
    daftar.tampilkanSemua();
    daftar.hitungRata();
    return 0;
}
