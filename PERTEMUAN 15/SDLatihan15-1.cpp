#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama, nim, gender;
    float nilai;
    Mahasiswa *next, *prev;
};

Mahasiswa *head = NULL;

// =========================================================
// ANIMASI CETAK NODE (ASCII)
// =========================================================
void animasiNode(Mahasiswa* node) {
    cout << "\n[ " << node->nim << " | "
         << node->nama << " | "
         << node->gender << " | "
         << node->nilai << " ]\n";
    cout << "   ^prev        nextv\n";
}

// =========================================================
// INSERT DATA (Ascending berdasarkan NIM)
// =========================================================
void insertData(string nama, string nim, string gender, float nilai) {
    Mahasiswa* baru = new Mahasiswa();
    baru->nama = nama;
    baru->nim = nim;
    baru->gender = gender;
    baru->nilai = nilai;
    baru->next = baru->prev = NULL;

    cout << "\n=== Animasi Insert ===\n";

    // Jika list masih kosong ? node pertama
    if (head == NULL) {
        head = baru;
        head->next = head;
        head->prev = head;
        animasiNode(baru);
        cout << "Node pertama ditambahkan!\n";
        return;
    }

    Mahasiswa *curr = head;

    // INSERT di depan (NIM lebih kecil dari head)
    if (nim < head->nim) {

        // cari node terakhir
        Mahasiswa* tail = head->prev;

        // pasang node baru
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;

        head = baru;

        animasiNode(baru);
        cout << "Node ditambahkan di depan (head).\n";
        return;
    }

    // INSERT di tengah atau terakhir
    while (curr->next != head && curr->next->nim < nim) {
        curr = curr->next;
    }

    // sisipkan setelah curr
    baru->next = curr->next;
    baru->prev = curr;
    curr->next->prev = baru;
    curr->next = baru;

    animasiNode(baru);
    cout << "Node ditambahkan pada posisi yang sesuai.\n";
}

// =========================================================
// HAPUS DATA berdasarkan NIM
// =========================================================
void hapusData(string nim) {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    Mahasiswa *curr = head;

    cout << "\n=== Animasi Hapus ===\n";

    // Jika head yang dihapus
    if (head->nim == nim) {

        // jika hanya 1 node
        if (head->next == head) {
            animasiNode(head);
            delete head;
            head = NULL;
            cout << "Node terakhir dihapus!\n";
            return;
        }

        Mahasiswa *tail = head->prev;

        animasiNode(head);
        // menghapus head
        tail->next = head->next;
        head->next->prev = tail;

        Mahasiswa *del = head;
        head = head->next;

        delete del;
        cout << "Node head berhasil dihapus!\n";
        return;
    }

    // Hapus di tengah/akhir
    do {
        if (curr->next->nim == nim) {
            Mahasiswa* del = curr->next;

            animasiNode(del);

            curr->next = del->next;
            del->next->prev = curr;

            delete del;
            cout << "Node berhasil dihapus!\n";
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "NIM tidak ditemukan!\n";
}

// =========================================================
// CETAK LIST
// =========================================================
void cetakData() {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    Mahasiswa *curr = head;

    cout << "\n======= DATA MAHASISWA (CDLL) =======\n";
    cout << left << setw(12) << "NIM"
         << setw(15) << "NAMA"
         << setw(10) << "GENDER"
         << setw(6) << "NILAI" << endl;
    cout << "----------------------------------------\n";

    do {
        cout << left
             << setw(12) << curr->nim
             << setw(15) << curr->nama
             << setw(10) << curr->gender
             << setw(6) << curr->nilai << endl;

        curr = curr->next;
    } while (curr != head);
}

// =========================================================
// MENU
// =========================================================
int main() {
    int pilihan;
    string nama, nim, gender;
    float nilai;

    do {
        cout << "\n         CIRCULAR DOUBLY LINKED LIST\n";
        cout << "         ============================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cin.ignore();
            cout << "Masukkan Nama   : ";
            getline(cin, nama);
            cout << "Masukkan NIM    : ";
            cin >> nim;
            cout << "Masukkan Gender : ";
            cin >> gender;
            cout << "Masukkan Nilai  : ";
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
