#include <iostream>
using namespace std;
int main() {
    string buah[5] = {"Jeruk", "Mangga", "Nanas", "Apel", "Rambutan"};
    cout << "Array saat ini : buah[5] = {Jeruk, Mangga, Nanas, Apel, Rambutan}" << endl;
    cout << "Mengubah elemen ke-4 (indeks 3) menjadi 'Anggur'" << endl;
    cout << "#buah[3] = Anggur" << endl;
    buah[3] = "Anggur";
    buah[4] = "Rambutan";
    cout<<"\nPengaksesan dengan for biasa"<<endl;
    for (int i = 0; i < 5; i++) {
        cout << buah[i] << endl;
    }
    cout<<"\nPengaksesan dengan for each"<<endl;
    for (string x : buah) {
        cout << x << endl;
    }
    
    // cout << "\n\n--- Program Manajemen Mahasiswa ---" << endl;
    // int panjang = 0;
    // string mahasiswa[100]; // Array untuk menyimpan nama mahasiswa dengan kapasitas maksimum 100
    // string mahasiswa[MAX_MAHASISWA]; // Array untuk menyimpan nama mahasiswa
    // int pilihan, index;
    // do{
    //     cout << "Menu:" << endl;
    //     cout << "1. Tampilkan Mahasiswa" << endl;
    //     cout << "2. Tambah Mahasiswa" << endl;
    //     cout << "3. Ubah Mahasiswa" << endl;
    //     cout << "4. Hapus Mahasiswa" << endl;
    //     cout << "5. Keluar" << endl;
    //     cout << "Pilih menu: ";
    //     cin >> pilihan;

    //     switch (pilihan) {
    //         case 1:
    //             if (panjang < MAX_MAHASISWA) {
    //                 cout << "Masukkan nama mahasiswa: ";
    //                 cin.ignore(); // Membersihkan buffer sebelum membaca string
    //                 getline(cin, mahasiswa[panjang]);   
    //                 cout << "Mahasiswa berhasil ditambahkan!" << endl;
    //                 panjang++;
    //             } else {
    //                 cout << "Kapasitas mahasiswa sudah penuh!" << endl;
    //             }
    //             break;
    //         case 2:
    //             cout << "Daftar Mahasiswa:" << endl;
    //             if (panjang == 0) {
    //                 cout << "Belum ada mahasiswa yang ditambahkan." << endl;
    //             } else {
    //                 for (int i = 0; i < panjang; i++) {
    //                     cout << i+1 << ". " << mahasiswa[i] << endl;
    //                 }
    //             }
    //             break;
    //         case 3:
    //             if (panjang == 0) {
    //                 cout << "Belum ada mahasiswa yang ditambahkan." << endl;
    //             } else {
    //                 cout << "Masukkan nomor mahasiswa yang ingin diubah: ";
    //                 cin >> index;
    //                 if (index > 0 && index <= panjang) {
    //                     cout << "Masukkan nama baru untuk mahasiswa ke-" << index << ": ";
    //                     cin.ignore(); // Membersihkan buffer sebelum membaca string
    //                     getline(cin, mahasiswa[index - 1]);
    //                     cout << "Mahasiswa berhasil diubah!" << endl;
    //                 } else {
    //                     cout << "Nomor mahasiswa tidak valid!" << endl;
    //                 }
    //             }
    //             break;
    //         case 4:
    //             if (panjang == 0) {
    //                 cout << "Belum ada mahasiswa yang ditambahkan." << endl;
    //             } else {
    //                 cout << "Masukkan nomor mahasiswa yang ingin dihapus: ";
    //                 cin >> index;
    //                 if (index > 0 && index <= panjang) {
    //                     for (int i = index - 1; i < panjang - 1; i++) {
    //                         mahasiswa[i] = mahasiswa[i + 1];
    //                     }
    //                     panjang--;
    //                     cout << "Mahasiswa berhasil dihapus!" << endl;
    //                 } else {
    //                     cout << "Nomor mahasiswa tidak valid!" << endl;
    //                 }
    //             }
    //             break;
    //         default:
    //             cout << "Pilihan tidak valid!" << endl;
    //     }
    // }   while (pilihan != 5);
    struct Alamat {
        string jalan;
        int    nomor;
        string kota;
    };

    struct Mahasiswa {
        string nama;
        int    umur;
        string jurusan;
        Alamat alamat;
    }; 
    #define MAX_MAHASISWA 100
    int panjang = 0;
    Mahasiswa mhs[MAX_MAHASISWA];

    int pilihan, index;

        do {
        cout << "==============================" << endl;
        cout << "   Menu Manajemen Mahasiswa  " << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Data Mahasiswa"  << endl;
        cout << "2. Tambah Data Mahasiswa"     << endl;
        cout << "3. Ubah Data Mahasiswa"       << endl;
        cout << "4. Hapus Data Mahasiswa"      << endl;
        cout << "5. Keluar"                    << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {

        case 1: // READ
            if (panjang == 0) {
                cout << "Belum ada data mahasiswa." << endl;
            } else {
                cout << "Daftar Mahasiswa:" << endl;
                cout << "================================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << "Mahasiswa ke-" << i + 1 << endl;
                    cout << "Nama    : " << mhs[i].nama    << endl;
                    cout << "Umur    : " << mhs[i].umur    << endl;
                    cout << "Jurusan : " << mhs[i].jurusan << endl;
                    cout << "Alamat  : " << mhs[i].alamat.jalan
                    cout << " No. " << mhs[i].alamat.nomor
                    cout << ", "    << mhs[i].alamat.kota << endl;
                    cout << "--------------------------------" << endl;
                }
            }
            break;

        case 2: // CREATE
            if (panjang < MAX_MAHASISWA) {
                cin.ignore();
                cout << "Masukkan nama     : ";
                getline(cin, mhs[panjang].nama);

                cout << "Masukkan umur     : ";
                cin >> mhs[panjang].umur;

                cin.ignore();
                cout << "Masukkan jurusan  : ";
                getline(cin, mhs[panjang].jurusan);

                cout << "--- Alamat ---" << endl;
                cout << "Jalan : ";
                getline(cin, mhs[panjang].alamat.jalan);

                cout << "Nomor : ";
                cin >> mhs[panjang].alamat.nomor;

                cin.ignore();
                cout << "Kota  : ";
                getline(cin, mhs[panjang].alamat.kota);

                panjang++;
                cout << "Data berhasil ditambahkan!" << endl;
            } else {
                cout << "Kapasitas penuh!" << endl;
            }
            break;

        case 3: // UPDATE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk diubah." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }

                cout << "Masukkan nomor mahasiswa yang akan diubah: ";
                cin >> index;

                if (index > 0 && index <= panjang) {
                    cin.ignore();
                    cout << "Masukkan nama mahasiswa baru: ";
                    getline(cin, mhs[index - 1].nama);

                    cout << "Masukkan umur mahasiswa baru: ";
                    cin >> mhs[index - 1].umur;

                    cin.ignore();
                    cout << "Masukkan jurusan mahasiswa baru: ";
                    getline(cin, mhs[index - 1].jurusan);

                    cout << "Masukkan alamat mahasiswa baru:" << endl;
                    cout << "Jalan: ";
                    getline(cin, mhs[index - 1].alamat.jalan);

                    cout << "Nomor: ";
                    cin >> mhs[index - 1].alamat.nomor;

                    cin.ignore();
                    cout << "Kota: ";
                    getline(cin, mhs[index - 1].alamat.kota);

                    cout << "Mahasiswa berhasil diubah" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;

        case 4: // DELETE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk dihapus." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }

                cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
                cin >> index;

                if (index > 0 && index <= panjang) {
                    for (int i = index - 1; i < panjang - 1; i++) {
                        mhs[i] = mhs[i + 1];
                    }
                    panjang--;
                    cout << "Mahasiswa berhasil dihapus" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;

        case 5:
            cout << "Sampai jumpa!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    
    } while (pilihan != 5);
    return 0;
}