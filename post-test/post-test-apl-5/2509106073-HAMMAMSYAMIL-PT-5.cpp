#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Penyewa {
    string nama;
    string noHP;
};
struct Kost {
    int idKamar;
    string tipe;
    int harga;
    Penyewa penyewa;
};
struct User {
    string nama;
    string password;
};

void tampilHeader(string judul) {
    cout << "\n===== " << judul << " =====\n";
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

int cariKamar(Kost dataKost[], int id, int index, int jumlahKost) {
    if (index >= jumlahKost) return -1;                    
    if (dataKost[index].idKamar == id) return index;       
    return cariKamar(dataKost, id, index + 1, jumlahKost); 
}
int totalHarga(Kost dataKost[], int index, int jumlahKost) {
    if (index >= jumlahKost) return 0;                               
    return dataKost[index].harga + totalHarga(dataKost, index + 1, jumlahKost); 
}

bool registerUser(User users[], int &jumlahUser) {
    tampilHeader("REGISTER");
    if (jumlahUser >= 100) {
        cout << "Kapasitas user penuh!\n";
        return false;
    }
    cin.ignore(1000, '\n'); 
    cout << "Username: ";
    getline(cin, users[jumlahUser].nama);
    cout << "Password: ";
    getline(cin, users[jumlahUser].password); 

    jumlahUser++;
    cout << "Registrasi berhasil!\n";
    return true;
}

bool loginUser(User users[], int jumlahUser) {
    tampilHeader("LOGIN");
    string namaLogin, passwordLogin;
    int kesempatan = 3;
    while (kesempatan > 0) {
        cin.ignore(1000, '\n'); 
        cout << "Username      : ";
        getline(cin, namaLogin);
        cout << "Password: ";
        getline(cin, passwordLogin);

        for (int i = 0; i < jumlahUser; i++) {
            if (users[i].nama == namaLogin && users[i].password == passwordLogin) {
                cout << "Login berhasil! Selamat datang, " << namaLogin << "!\n";
                return true;
            }
        }
        kesempatan--;
        if (kesempatan > 0) {
            cout << "Login gagal! Sisa percobaan: " << kesempatan << "\n\n";
        }
    }
    cout << "Kesempatan habis! Program berhenti.\n";
    return false;
}

bool tambahData(Kost dataKost[], int &jumlahKost) {
    tampilHeader("TAMBAH DATA");
    if (jumlahKost >= 100) {
        cout << "Kapasitas kamar penuh!\n";
        return false;
    }
    dataKost[jumlahKost].idKamar = jumlahKost + 1;
    cout << "ID: " << dataKost[jumlahKost].idKamar << endl;
    cin.ignore(1000, '\n');
    cout << "Tipe Kamar    : "; getline(cin, dataKost[jumlahKost].tipe);
    cout << "Harga         : "; cin >> dataKost[jumlahKost].harga;
    cin.ignore(1000, '\n');
    cout << "Nama Penyewa  : "; getline(cin, dataKost[jumlahKost].penyewa.nama);
    cout << "No HP Penyewa : "; getline(cin, dataKost[jumlahKost].penyewa.noHP);
    jumlahKost++;
    cout << "Data berhasil ditambahkan!\n";
    return true;
}
void lihatData(Kost dataKost[], int jumlahKost) {
    tampilHeader("DATA KOST");
    if (jumlahKost == 0) {
        cout << "Belum ada data kost.\n";
        return;
    }
    cout << left
         << setw(5)  << "ID"
         << setw(12) << "Tipe"
         << setw(12) << "Harga"
         << setw(20) << "Nama Penyewa"
         << setw(15) << "No HP"
         << endl;
    cout << string(64, '-') << endl;
    for (int i = 0; i < jumlahKost; i++) {
        cout << left
             << setw(5)  << dataKost[i].idKamar
             << setw(12) << dataKost[i].tipe
             << setw(12) << dataKost[i].harga
             << setw(20) << dataKost[i].penyewa.nama
             << setw(15) << dataKost[i].penyewa.noHP
             << endl;
    }
}
bool updateData(Kost dataKost[], int jumlahKost) {
    tampilHeader("UPDATE DATA");
    int id;
    cout << "Masukkan ID Kamar yang ingin diubah: ";
    cin >> id;

    int index = cariKamar(dataKost, id, 0, jumlahKost);
    if (index == -1) {
        cout << "ID Kamar tidak ditemukan!\n";
        return false;
    }

    cin.ignore(1000, '\n');
    cout << "Tipe Baru: ";
    getline(cin, dataKost[index].tipe);
    cout << "Harga Baru: ";
    cin >> dataKost[index].harga;
    cin.ignore(1000, '\n');
    cout << "Nama Penyewa Baru: ";
    getline(cin, dataKost[index].penyewa.nama);
    cout << "No HP Baru: ";
    getline(cin, dataKost[index].penyewa.noHP);
    cout << "Data berhasil diupdate!\n";
    return true;
}
bool hapusData(Kost dataKost[], int &jumlahKost) {
    tampilHeader("HAPUS DATA");
    int id;
    cout << "Masukkan ID Kamar yang ingin dihapus: ";
    cin >> id;

    int index = cariKamar(dataKost, id, 0, jumlahKost);
    if (index == -1) {
        cout << "ID Kamar tidak ditemukan!\n";
        return false;
    }

    for (int j = index; j < jumlahKost - 1; j++) {
        dataKost[j] = dataKost[j + 1];
    }
    jumlahKost--;
    cout << "Data berhasil dihapus!\n";
    return true;
}
void tampilInfo(Kost *k) {
    cout << "[Info Kamar] ID: " << k->idKamar << " | Tipe: " << k->tipe << endl;
}
void tampilInfo(Kost *k, bool tampilHarga) {
    cout << "[Info Kamar] ID: " << k->idKamar
         << " | Tipe: " << k->tipe;
    if (tampilHarga)
        cout << " | Harga: Rp" << k->harga;
    cout << " | Penyewa: " << k->penyewa.nama
         << " | No HP: " << k->penyewa.noHP << endl;
}
void tampilInfo(Kost dataKost[], int index) {
    Kost *ptr = &dataKost[index];
    cout << "[Info Kamar ke-" << index + 1 << "] "
         << "ID: " << ptr->idKamar
         << " | Tipe: " << ptr->tipe
         << " | Harga: Rp" << ptr->harga
         << " | Penyewa: " << ptr->penyewa.nama << endl;
}

void menuSorting(Kost dataKost[], int jumlahKost) {
    int pil;
    do {
    tampilHeader("MENU SORTING");
    cout << "1. Urutkan Nama Penyewa (Ascending)\n";
    cout << "2. Urutkan Harga Kamar (Descending)\n";
    cout << "3. Urutkan ID Kamar (Ascending)\n";
    cout << "4. Kembali ke Menu Utama\n";
    cout << "Pilihan: ";
    cin >> pil;
    switch(pil) {
        case 1: bubbleSortNamaAsc(dataKost, jumlahKost); cout << "Data berhasil diurutkan berdasarkan nama.\n"; break;
        case 2: selectionSortHargaDesc(dataKost, jumlahKost); cout << "Data berhasil diurutkan berdasarkan harga.\n"; break;
        case 3: insertionSortIDAsc(dataKost, jumlahKost); cout << "Data berhasil diurutkan berdasarkan ID.\n"; break;
        case 4: cout << "Kembali ke Menu Utama.\n"; break;
        default: cout << "Pilihan tidak valid.\n"; break;
        }    
    } while (pil != 4);
}

void tampilRingkasan(Kost dataKost[], int jumlahKost) {
    tampilHeader("RINGKASAN DATA KOST");
    cout << "Total kamar terdaftar : " << jumlahKost << endl;
    cout << "Total pendapatan      : Rp" << totalHarga(dataKost, 0, jumlahKost) << endl;
    cout << "\nDetail setiap kamar:\n";
    for (int i = 0; i < jumlahKost; i++) {
        tampilInfo(dataKost, i);
    }
}
void menuUtama(Kost dataKost[], int &jumlahKost) {
    int menu;
    do {
        tampilHeader("MENU UTAMA");
        cout << "1. Tambah Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Sorting Data\n";
        cout << "6. Ringkasan & Info Kamar\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> menu;
        switch (menu) {
            case 1: tambahData(dataKost, jumlahKost);         break;
            case 2: lihatData(dataKost, jumlahKost);          break;
            case 3: updateData(dataKost, jumlahKost);         break;
            case 4: hapusData(dataKost, jumlahKost);          break;
            case 5: menuSorting(dataKost, jumlahKost);        break;
            case 6: tampilRingkasan(dataKost, jumlahKost);    break;
            case 7: cout << "Keluar dari menu utama.\n";      break;
            default: cout << "Pilihan tidak valid!\n";        break;
        }
    } while (menu != 7);
}
int main() {
    User users[100];
    Kost dataKost[100];
    int jumlahUser = 0;
    int jumlahKost = 0;
    int pilihanAwal;
    do {
        tampilHeader("MENU AWAL");
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihanAwal;
        if (pilihanAwal == 1) {
            registerUser(users, jumlahUser);
        }
        else if (pilihanAwal == 2) {
            bool berhasil = loginUser(users, jumlahUser);
            if (!berhasil) {
                cout << "Tekan Enter untuk keluar...";
                cin.ignore();
                cin.get();
                return 0;   
            }
            menuUtama(dataKost, jumlahKost);
        }
        else if (pilihanAwal != 3) {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihanAwal != 3);
    cout << "\nProgram selesai. Terima kasih!\n";
    cout << "Tekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}