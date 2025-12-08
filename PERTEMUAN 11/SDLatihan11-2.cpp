#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[50];
    char NIM[20];
    char gender[10];
    float nilai;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *top = NULL; 

Mahasiswa* buatNode(char nama[], char NIM[], char gender[], float nilai) {
    Mahasiswa *baru = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    strcpy(baru->NIM, NIM);
    strcpy(baru->gender, gender);
    baru->nilai = nilai;
    baru->next = NULL;
    return baru;
}

void push(char nama[], char NIM[], char gender[], float nilai) {
    Mahasiswa *baru = buatNode(nama, NIM, gender, nilai);
    baru->next = top;
    top = baru;
    printf("\nData berhasil dimasukkan ke Stack!\n");
}

void pop() {
    if (top == NULL) {
        printf("\nStack kosong, tidak ada data untuk dihapus.\n");
        return;
    }
    Mahasiswa *hapus = top;
    top = top->next;
    printf("\nData '%s' berhasil dihapus dari Stack.\n", hapus->nama);
    free(hapus);
}

void tampil() {
    if (top == NULL) {
        printf("\nStack kosong.\n");
        return;
    }

    printf("\n=== Isi Stack (TOP ke BOTTOM) ===\n");
    Mahasiswa *temp = top;
    while (temp != NULL) {
        printf("Nama: %s | NIM: %s | Gender: %s | Nilai: %.2f\n",
               temp->nama, temp->NIM, temp->gender, temp->nilai);
        temp = temp->next;
    }
}

int main() {
    int pilih;
    char nama[50], NIM[20], gender[10];
    float nilai;

    do {
        printf("\n===== MENU STACK (TANPA HEAD) =====\n");
        printf("1. INSERT DATA\n");
        printf("2. HAPUS DATA\n");
        printf("3. CETAK DATA\n");
        printf("4. EXIT\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        getchar(); 

        switch (pilih) {
            case 1:
                printf("Masukkan Nama: "); gets(nama);
                printf("Masukkan NIM: "); gets(NIM);
                printf("Masukkan Gender: "); gets(gender);
                printf("Masukkan Nilai Struktur Data: "); scanf("%f", &nilai);
                push(nama, NIM, gender, nilai);
                break;
            case 2:
                pop();
                break;
            case 3:
                tampil();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilih != 4);

    return 0;
}

