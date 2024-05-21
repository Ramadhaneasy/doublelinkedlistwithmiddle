#include <iostream>
#include <string>

using namespace std;

struct Antrian {
    int nomorAntrian;
    string namaPemilik;
    string waktuKedatangan;
    Antrian* next;
    Antrian* prev;
};

Antrian* kepala = nullptr;
Antrian* ekor = nullptr;

// Fungsi untuk menambahkan antrian ke akhir linked list
void tambahAntrianAkhir(int nomorAntrian, string namaPemilik, string waktuKedatangan) {
    Antrian* newNode = new Antrian;
    newNode->nomorAntrian = nomorAntrian;
    newNode->namaPemilik = namaPemilik;
    newNode->waktuKedatangan = waktuKedatangan;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (kepala == nullptr) {
        kepala = ekor = newNode;
    } else {
        ekor->next = newNode;
        newNode->prev = ekor;
        ekor = newNode;
    }
}

// Fungsi untuk menambahkan antrian di tengah linked list
void tambahAntrianTengah(int nomorAntrian, string namaPemilik, string waktuKedatangan) {
    if (kepala == nullptr) {
        tambahAntrianAkhir(nomorAntrian, namaPemilik, waktuKedatangan);
    } else {
        Antrian* newNode = new Antrian;
        newNode->nomorAntrian = nomorAntrian;
        newNode->namaPemilik = namaPemilik;
        newNode->waktuKedatangan = waktuKedatangan;

        Antrian* slow = kepala;
        Antrian* fast = kepala->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        newNode->next = slow->next;
        newNode->prev = slow;

        if (slow->next != nullptr) {
            slow->next->prev = newNode;
        }

        slow->next = newNode;

        if (slow == ekor) {
            ekor = newNode;
        }
    }
}

// Fungsi untuk mencetak semua antrian dari kepala ke ekor
void cetakAntrian() {
    Antrian* current = kepala;
    while (current != nullptr) {
        cout << "Nomor Antrian: " << current->nomorAntrian << endl;
        cout << "Nama Pemilik: " << current->namaPemilik << endl;
        cout << "Waktu Kedatangan: " << current->waktuKedatangan << endl << endl;
        current = current->next;
    }
}

// Fungsi untuk mencetak semua antrian dari ekor ke kepala
void cetakAntrianTerbalik() {
    Antrian* current = ekor;
    while (current != nullptr) {
        cout << "Nomor Antrian: " << current->nomorAntrian << endl;
        cout << "Nama Pemilik: " << current->namaPemilik << endl;
        cout << "Waktu Kedatangan: " << current->waktuKedatangan << endl << endl;
        current = current->prev;
    }
}

// Fungsi utama
int main() {
    tambahAntrianAkhir(1, "John Doe", "08:00");
    tambahAntrianAkhir(2, "Jane Doe", "08:15");
    tambahAntrianAkhir(3, "Alice", "08:30");

    // Menampilkan daftar antrian dari kepala ke ekor
    cout << "Daftar Antrian (dari kepala ke ekor):" << endl;
    cetakAntrian();
    cout << "\n";

    // Menambahkan antrian di tengah
    tambahAntrianTengah(4, "Bob", "08:20");
    tambahAntrianTengah(5, "Eve", "08:25");

    // Menampilkan daftar antrian setelah penambahan di tengah
    cout << "Daftar Antrian setelah penambahan di tengah (dari kepala ke ekor):" << endl;
    cetakAntrian();
    cout << "\n";

    // Menampilkan daftar antrian dari ekor ke kepala
    cout << "Daftar Antrian (dari ekor ke kepala):" << endl;
    cetakAntrianTerbalik();
    cout << "\n";

    return 0;
}
