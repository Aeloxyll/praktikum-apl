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