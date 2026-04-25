#include "kost_lib.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void tampilHeader(string judul) {
    cout << "\n\033[1;36m" << string(10, '=') << " " << judul << " " << string(10, '=') << "\033[0m\n";
}

void bubbleSortNamaAsc(Kost dataKost[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dataKost[j].penyewa.nama > dataKost[j + 1].penyewa.nama) {
                 Kost temp = dataKost[j];
                 dataKost[j] = dataKost[j + 1];
                 dataKost[j + 1] = temp;
            }
        }
    }
}
void selectionSortHargaDesc(Kost dataKost[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (dataKost[j].harga > dataKost[max_idx].harga) {
                max_idx = j;
            }
        }
        Kost temp = dataKost[max_idx];
        dataKost[max_idx] = dataKost[i];
        dataKost[i] = temp;
    }
}
void insertionSortIDAsc(Kost dataKost[], int n) {
    for (int i = 1; i < n; i++) {
        Kost key = dataKost[i];
        int j = i - 1;
        while (j >= 0 && dataKost[j].idKamar > key.idKamar) {
            dataKost[j + 1] = dataKost[j];
            j = j - 1;
        }
        dataKost[j + 1] = key;
    }
}

int binarySearchID(Kost dataKost[], int n, int target) {
    insertionSortIDAsc(dataKost, n);
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (dataKost[mid].idKamar == target) return mid;
        if (dataKost[mid].idKamar < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int linearSearchNama(Kost dataKost[], int n, string target) {
    for (int i = 0; i < n; i++) {
        if (dataKost[i].penyewa.nama == target) {
            return i;
        }
    }
    return -1;
}

int totalHarga(Kost dataKost[], int index, int jumlahKost) {
    if (index >= jumlahKost) return 0;                               
    return dataKost[index].harga + totalHarga(dataKost, index + 1, jumlahKost); 
}

void registerUser(User users[], int &jumlahUser) {
    tampilHeader("REGISTER");
    try {
        if (jumlahUser >= MAX_DATA) throw KostException("Kapasitas user penuh!");
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Username: ";
        getline(cin, users[jumlahUser].nama);
        if(users[jumlahUser].nama.empty()) throw KostException("Username tidak boleh kosong!");
        
        cout << "Password: ";
        getline(cin, users[jumlahUser].password); 
        if(users[jumlahUser].password.length() < 4) throw KostException("Password minimal 4 karakter!");

        jumlahUser++;
        cout << "\033[1;32mRegistrasi berhasil!\033[0m\n";
    } catch (const KostException& e) {
        cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}
bool loginUser(User users[], int jumlahUser) {
    tampilHeader("LOGIN");
    string namaLogin, passwordLogin;
    int kesempatan = 3;
    while (kesempatan > 0) {
        try {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Username: ";
            getline(cin, namaLogin);
            cout << "Password: ";
            getline(cin, passwordLogin);

            for (int i = 0; i < jumlahUser; i++) {
                if (users[i].nama == namaLogin && users[i].password == passwordLogin) {
                    cout << "\033[1;32mLogin berhasil! Selamat datang, " << namaLogin << "!\033[0m\n";
                    return true;
                }
            }
            kesempatan--;
            if (kesempatan > 0) {
                throw KostException("Username atau Password salah!");
            }
        } catch (const KostException& e) {
            cout << "\033[1;31m" << e.what() << " Sisa percobaan: " << kesempatan << "\033[0m\n\n";
        }
    }
    return false;
}

void tambahData(Kost dataKost[], int &jumlahKost) {
    tampilHeader("TAMBAH DATA");
    try {
        if (jumlahKost >= MAX_DATA) throw KostException("Kapasitas kamar penuh!");

        dataKost[jumlahKost].idKamar = jumlahKost + 1;
        cout << "ID: " << dataKost[jumlahKost].idKamar << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Tipe Kamar    : "; getline(cin, dataKost[jumlahKost].tipe);
        cout << "Harga         : "; 
        if(!(cin >> dataKost[jumlahKost].harga)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw KostException("Input harga harus berupa angka!");
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama Penyewa  : "; getline(cin, dataKost[jumlahKost].penyewa.nama);
        cout << "No HP Penyewa : "; getline(cin, dataKost[jumlahKost].penyewa.noHP);
        
        jumlahKost++;
        cout << "\033[1;32mData berhasil ditambahkan!\033[0m\n";
    } catch (const KostException& e) {
        cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}
void lihatData(Kost dataKost[], int jumlahKost) {
    tampilHeader("DATA KOST");
    if (jumlahKost == 0) {
        cout << "Belum ada data kost.\n";
        return;
    }
    cout << left << setw(5) 
         << "ID" << setw(12) 
         << "Tipe" << setw(12) 
         << "Harga" << setw(20) 
         << "Nama" << setw(15) 
         << "No HP" << endl;
    cout << string(64, '-') << endl;
    for (int i = 0; i < jumlahKost; i++) {
        cout << left << setw(5) 
             << dataKost[i].idKamar << setw(12) 
             << dataKost[i].tipe << setw(12) 
             << dataKost[i].harga << setw(20) 
             << dataKost[i].penyewa.nama << setw(15) 
             << dataKost[i].penyewa.noHP << endl;
    }
}

void tampilInfo(Kost *k) {
    cout << "\033[1;33m[Info Kamar]\033[0m ID: " 
         << k->idKamar << " | Tipe: " 
         << k->tipe << " | Harga: Rp" 
         << k->harga << " | Penyewa: " 
         << k->penyewa.nama << endl;
}

void updateData(Kost dataKost[], int jumlahKost) {
    tampilHeader("UPDATE DATA");
    try {
        int id;
        cout << "Masukkan ID Kamar: ";
        if(!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw KostException("Input ID harus angka!");
        }

        int index = binarySearchID(dataKost, jumlahKost, id);
        if (index == -1) throw KostException("ID Kamar tidak ditemukan!");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Tipe Baru: "; getline(cin, dataKost[index].tipe);
        cout << "Harga Baru: "; cin >> dataKost[index].harga;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama Penyewa Baru: "; getline(cin, dataKost[index].penyewa.nama);
        cout << "No HP Baru: "; getline(cin, dataKost[index].penyewa.noHP);
        cout << "\033[1;32mData berhasil diupdate!\033[0m\n";
    } catch (const KostException& e) {
        cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}
void hapusData(Kost dataKost[], int &jumlahKost) {
    tampilHeader("HAPUS DATA");
    try {
        int id;
        cout << "Masukkan ID Kamar: ";
        cin >> id;

        int index = binarySearchID(dataKost, jumlahKost, id);
        if (index == -1) throw KostException("ID Kamar tidak ditemukan!");

        for (int j = index; j < jumlahKost - 1; j++) {
            dataKost[j] = dataKost[j + 1];
        }
        jumlahKost--;
        cout << "\033[1;32mData berhasil dihapus!\033[0m\n";
    } catch (const KostException& e) {
        cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}

void menuCari(Kost dataKost[], int jumlahKost) {
    int pil;
    tampilHeader("MENU SEARCHING");
    cout << "1. Cari ID Kamar\n2. Cari Nama Penyewa\nPilihan: ";
    cin >> pil;
    if (pil == 1) {
        int id; cout << "ID: "; cin >> id;
        int idx = binarySearchID(dataKost, jumlahKost, id);
        if (idx != -1) tampilInfo(&dataKost[idx]);
        else cout << "Data tidak ditemukan.\n";
    } else {
        string nama; cin.ignore(); cout << "Nama: "; getline(cin, nama);
        int idx = linearSearchNama(dataKost, jumlahKost, nama);
        if (idx != -1) tampilInfo(&dataKost[idx]);
        else cout << "Data tidak ditemukan.\n";
    }
}

void menuSorting(Kost dataKost[], int jumlahKost) {
    int pil;
    tampilHeader("MENU SORTING");
    cout << "1. Nama (Asc)\n2. Harga (Desc)\n3. ID (Asc)\nPilihan: ";
    cin >> pil;
    if(pil == 1) bubbleSortNamaAsc(dataKost, jumlahKost);
    else if(pil == 2) selectionSortHargaDesc(dataKost, jumlahKost);
    else if(pil == 3) insertionSortIDAsc(dataKost, jumlahKost);
    cout << "Sorting selesai.\n";
}

void menuUtama(Kost dataKost[], int &jumlahKost) {
    int menu;
    do {
        tampilHeader("MENU UTAMA");
        cout << "1. Tambah  2. Lihat  3. Update  4. Hapus\n5. Sorting 6. Cari   7. Ringkasan 8. Keluar\nPilihan: ";
        if(!(cin >> menu)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (menu) {
            case 1: tambahData(dataKost, jumlahKost); break;
            case 2: lihatData(dataKost, jumlahKost); break;
            case 3: updateData(dataKost, jumlahKost); break;
            case 4: hapusData(dataKost, jumlahKost); break;
            case 5: menuSorting(dataKost, jumlahKost); break;
            case 6: menuCari(dataKost, jumlahKost); break;
            case 7: 
                cout << "Total Pendapatan: Rp" << totalHarga(dataKost, 0, jumlahKost) << endl;
                lihatData(dataKost, jumlahKost);
                break;
        }
    } while (menu != 8);
}

int main() {
    User users[MAX_DATA];
    Kost dataKost[MAX_DATA];
    int jumlahUser = 0, jumlahKost = 0, pil;
    do {
        tampilHeader("SISTEM MANAGEMENT KOST");
        cout << "1. Register\n2. Login\n3. Keluar\nPilihan: ";
        if(!(cin >> pil)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pil == 1) registerUser(users, jumlahUser);
        else if (pil == 2) {
            if (loginUser(users, jumlahUser)) menuUtama(dataKost, jumlahKost);
            else break;
        }
    } while (pil != 3);
    return 0;
}