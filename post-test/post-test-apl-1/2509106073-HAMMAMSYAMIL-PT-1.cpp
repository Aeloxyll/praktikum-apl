#include <iostream>
using namespace std;
int main() {
    string username, password;
    int coba = 0;
    bool login = false;
    while (coba < 3) {
        cout << "\n====================================\n";
        cout << "            MENU LOGIN              \n";
        cout << "====================================\n";
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;
        if (username == "073" && password == "073") {
            login = true;
            break;
        } else {
            coba++;
            cout << "\nLogin gagal! Percobaan ke-" << coba << " dari 3.\n";
        }
    }
    if (!login) {
        cout << "\nKesempatan anda login telah habis.\n";
        return 0;
    }
    int pilih;
    double panjang;
    do {
        cout << "\n====================================\n";
        cout << "          MENU KONVERSI             \n";
        cout << "====================================\n";
        cout << "1. Konversi Meter ke KM & CM\n";
        cout << "2. Konversi CM ke Meter & KM\n";
        cout << "3. Konversi KM ke Meter & CM\n";
        cout << "4. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu (1-4) : ";
        cin >> pilih;
        cout << "====================================\n";
        if (pilih == 1) {
            cout << "Masukkan panjang (Meter) : ";
            cin >> panjang;

            cout << "\nHasil Konversi:\n";
            cout << panjang << " Meter = " << panjang / 1000 << " KM\n";
            cout << panjang << " Meter = " << panjang * 100 << " CM\n";
        }
        else if (pilih == 2) {
            cout << "Masukkan panjang (CM) : ";
            cin >> panjang;
            cout << "\nHasil Konversi:\n";
            cout << panjang << " CM = " << panjang / 100 << " Meter\n";
            cout << panjang << " CM = " << panjang / 100000 << " KM\n";
        }
        else if (pilih == 3) {
            cout << "Masukkan panjang (KM) : ";
            cin >> panjang;
            cout << "\nHasil Konversi:\n";
            cout << panjang << " KM = " << panjang * 1000 << " Meter\n";
            cout << panjang << " KM = " << panjang * 100000 << " CM\n";
        }
        else if (pilih == 4) {
            cout << "Terima kasih telah menggunakan program ini.\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 4);
    cout << "\n====================================\n";
    cout << "            PROGRAM SELESAI         \n";
    cout << "====================================\n";
    return 0;
}   