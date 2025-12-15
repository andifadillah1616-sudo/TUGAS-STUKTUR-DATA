#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;
void insertData(string nama, string nim, string gender, float nilai) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        cout << "Data berhasil ditambah!\n";
        return;
    }

    Mahasiswa* current = head;

    if (nim < head->nim) {
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode;
        cout << "Data berhasil ditambah!\n";
        return;
    }

    while (current->next != head && current->next->nim < nim) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    cout << "Data berhasil ditambah!\n";
}

void hapusData(string nim) {
    if (head == NULL) {
        cout << "List masih kosong!\n";
        return;
    }

    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;

    if (head->nim == nim) {
    	
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Data berhasil dihapus!\n";
            return;
        }

        while (current->next != head) {
            current = current->next;
        }

        current->next = head->next;
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;

        cout << "Data berhasil dihapus!\n";
        return;
    }

    current = head;
    while (current->next != head && current->next->nim != nim) {
        current = current->next;
    }

    if (current->next->nim == nim) {
        Mahasiswa* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Data dengan NIM tersebut tidak ditemukan!\n";
    }
}

void cetakData() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Mahasiswa* current = head;
    cout << "\n=== DATA MAHASISWA ===\n";
    do {
        cout << "NAMA   : " << current->nama << endl;
        cout << "NIM    : " << current->nim << endl;
        cout << "GENDER : " << current->gender << endl;
        cout << "NILAI  : " << current->nilai << endl;
        cout << "----------------------------\n";
        current = current->next;
    } while (current != head);
}

// MENU
int main() {
    int pilihan;
    string nama, nim, gender;
    float nilai;

    do {
        cout << "\n        CIRCULAR LINKED LIST\n";
        cout << "        ==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "   Pilihan (1 - 4) : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan NAMA   : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM    : ";
            cin >> nim;
            cout << "Masukkan GENDER : ";
            cin >> gender;
            cout << "Masukkan NILAI  : ";
            cin >> nilai;
            insertData(nama, nim, gender, nilai);
            break;

        case 2:
            cout << "Masukkan NIM yang akan dihapus: ";
            cin >> nim;
            hapusData(nim);
            break;

        case 3:
            cetakData();
            break;

        case 4:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
