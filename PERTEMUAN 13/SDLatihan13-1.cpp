#include <iostream>
#include <string>
#include <iomanip> // Untuk setw dan setprecision

using namespace std;

// --- STRUKTUR DATA MAHASISWA (KOMPONEN NODE) ---
struct Mahasiswa {
    string NAMA;
    string NIM; // Kunci pengurutan (ascending)
    string GENDER;
    double NILAI;
};

// --- STRUKTUR NODE DOUBLY LINKED LIST ---
struct Node {
    Mahasiswa data;
    Node *prev;
    Node *next;
};

// Global Pointers
Node *head = NULL; // Pointer ke awal list
Node *tail = NULL; // Pointer ke akhir list

// --- FUNGSI UTAMA LIST ---

// 1. Cek List Kosong
bool isEmpty() {
    return head == NULL;
}

// 2. Tambah Data (Terurut Ascending berdasarkan NIM)
void insertData() {
    Mahasiswa mhs;
    cout << "\n--- ? INSERT DATA ---" << endl;
    cout << "NIM    : "; cin >> mhs.NIM;
    
    // Pengecekan Duplikasi NIM sederhana (opsional)
    Node *check = head;
    while(check != NULL) {
        if (check->data.NIM == mhs.NIM) {
            cout << "? Error: NIM " << mhs.NIM << " sudah ada dalam list." << endl;
            return;
        }
        check = check->next;
    }

    cout << "NAMA   : "; cin.ignore(); getline(cin, mhs.NAMA);
    cout << "GENDER : "; cin >> mhs.GENDER;
    cout << "NILAI  : "; cin >> mhs.NILAI;

    // Buat Node baru
    Node *newNode = new Node;
    newNode->data = mhs;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (isEmpty()) {
        // Kasus 1: List kosong
        head = newNode;
        tail = newNode;
    } else if (newNode->data.NIM < head->data.NIM) {
        // Kasus 2: Sisip di depan
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        // Kasus 3: Sisip di tengah atau di belakang
        Node *current = head;
        // Cari posisi yang tepat: selama NIM newNode > NIM current
        while (current != NULL && newNode->data.NIM > current->data.NIM) {
            current = current->next;
        }

        if (current == NULL) {
            // Sisip di belakang (NIM terbesar)
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            // Sisip di tengah
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }
    cout << "? Data Mahasiswa dengan NIM **" << mhs.NIM << "** berhasil ditambahkan dan diurutkan." << endl;
}

// 3. Hapus Data berdasarkan NIM
void hapusData() {
    if (isEmpty()) {
        cout << "\n? List kosong, tidak ada data untuk dihapus!" << endl;
        return;
    }

    string nimHapus;
    cout << "\n--- ??? HAPUS DATA ---" << endl;
    cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
    cin >> nimHapus;

    Node *hapus = head;
    bool ditemukan = false;

    // Cari node
    while (hapus != NULL) {
        if (hapus->data.NIM == nimHapus) {
            ditemukan = true;
            break;
        }
        hapus = hapus->next;
    }

    if (ditemukan) {
        if (hapus == head) {
            // Hapus di depan
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL; // List menjadi kosong
            }
        } else if (hapus == tail) {
            // Hapus di belakang
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                 head = NULL; // List menjadi kosong
            }
        } else {
            // Hapus di tengah
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        
        cout << "? Data Mahasiswa dengan NIM **" << nimHapus << "** berhasil dihapus." << endl;
        delete hapus;
    } else {
        cout << "? Data Mahasiswa dengan NIM **" << nimHapus << "** tidak ditemukan." << endl;
    }
}

// 4. Cetak Data
void cetakData() {
    if (isEmpty()) {
        cout << "\n? List kosong, tidak ada data untuk dicetak!" << endl;
        return;
    }

    Node *current = head;
    cout << "\n--- ?? CETAK DATA MAHASISWA (Terurut Berdasarkan NIM) ---" << endl;
    cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
    cout << "| " << setw(10) << left << "NIM" 
         << "| " << setw(20) << left << "NAMA" 
         << "| " << setw(8) << left << "GENDER" 
         << "| " << setw(6) << left << "NILAI" << "|" << endl;
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    while (current != NULL) {
        cout << "| " << setw(10) << left << current->data.NIM
             << "| " << setw(20) << left << current->data.NAMA
             << "| " << setw(8) << left << current->data.GENDER
             << "| " << setw(6) << left << fixed << setprecision(2) << current->data.NILAI << "|" << endl;
        current = current->next;
    }
    cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
}

// 5. Fungsi Pembersihan Memori
void cleanup() {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}

// --- FUNGSI UTAMA (MENU) ---
int main() {
    int pilihan;

    do {
        // Tampilan Menu
        cout << "\n==========================" << endl;
        cout << "LIN. DOUBLY LINKED LIST" << endl;
        cout << "==========================" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilihan (1 - 4) : ";
        
        // Memastikan input adalah angka
        if (!(cin >> pilihan)) {
            cout << "\n? Input tidak valid. Masukkan angka (1-4)." << endl;
            cin.clear(); // Hapus status error
            cin.ignore(10000, '\n'); // Buang sisa input
            pilihan = 0; // Set pilihan ke nilai non-aktif
            continue;
        }

        switch (pilihan) {
            case 1:
                insertData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cetakData();
                break;
            case 4:
                cout << "\nTerima kasih. Program selesai. ??" << endl;
                cleanup(); // Bersihkan memori sebelum keluar
                break;
            default:
                cout << "\n? Pilihan tidak valid. Silakan masukkan angka antara 1 dan 4." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
