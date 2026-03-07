#include <iostream>
#include <iomanip>
using namespace std;

struct Penyewa{
    string nama;
    string noHP;
};
struct Kost{
    int idKamar;
    string tipe;
    int harga;
    Penyewa penyewa;
};
struct User{
    string nama;
    string nim;
};
int main(){
    User users[100];
    Kost dataKost[100];
    int jumlahUser = 0;
    int jumlahKost = 0;
    int pilihanAwal;
    do{
        cout<<"\n===== MENU AWAL =====\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"Pilihan: ";
        cin>>pilihanAwal;
        if(pilihanAwal==1){
            cout<<"\n===== REGISTER =====\n";
            cout<<"Nama: ";
            cin>>users[jumlahUser].nama;
            cout<<"NIM: ";
            cin>>users[jumlahUser].nim;
            jumlahUser++;
            cout<<"Registrasi berhasil!\n";
        }
        else if(pilihanAwal==2){
            string namaLogin, nimLogin;
            int kesempatan=3;
            bool berhasil=false;
            while(kesempatan>0){
                cout<<"\n===== LOGIN =====\n";
                cout<<"Username: ";
                cin>>namaLogin;
                cout<<"Password: ";
                cin>>nimLogin;
                for(int i=0;i<jumlahUser;i++){
                    if(users[i].nama==namaLogin && users[i].nim==nimLogin){
                        berhasil=true;
                        break;
                    }
                }
                if(berhasil){
                    cout<<"Login berhasil!\n";
                    break;
                }
                kesempatan--;
                cout<<"Login gagal! Sisa percobaan: "<<kesempatan<<endl;
            }
            if(!berhasil){
                cout<<"Kesempatan habis!. Program berhenti.\n";
                cout<<"Tekan Enter untuk keluar...";
                cin.ignore();
                cin.get();
                return 0;
            }
            int menu;
            do{
                cout<<"\n===== MENU UTAMA =====\n";
                cout<<"1. Tambah Data\n";
                cout<<"2. Lihat Data\n";
                cout<<"3. Update Data\n";
                cout<<"4. Hapus Data\n";
                cout<<"5. Keluar\n";
                cout<<"Pilihan: ";
                cin>>menu;
                if(menu==1){
                    cout<<"\n===== TAMBAH DATA =====\n";
                    cout<<"ID Kamar: ";
                    cin>>dataKost[jumlahKost].idKamar;
                    cout<<"Tipe Kamar: ";
                    cin>>dataKost[jumlahKost].tipe;
                    cout<<"Harga: ";
                    cin>>dataKost[jumlahKost].harga;
                    cout<<"Nama Penyewa: ";
                    cin>>dataKost[jumlahKost].penyewa.nama;
                    cout<<"No HP: ";
                    cin>>dataKost[jumlahKost].penyewa.noHP;
                    jumlahKost++;
                    cout<<"Data berhasil ditambahkan!\n";
                }
                else if(menu==2){
                    cout<<"\n===== DATA KOST =====\n";
                    cout << "ID|Tipe|Harga|Nama Penyewa|No HP\n";
                    for(int i=0;i<jumlahKost;i++){
                        cout<<dataKost[i].idKamar << "|"
                            <<dataKost[i].tipe << "|"
                            <<dataKost[i].harga << "|"
                            <<dataKost[i].penyewa.nama << "|"
                            <<dataKost[i].penyewa.noHP << endl;
                    }
                }
                else if(menu==3){
                    int id;
                    cout<<"Masukkan ID kamar yang ingin diubah: ";
                    cin>>id;
                    for(int i=0;i<jumlahKost;i++){
                        if(dataKost[i].idKamar==id){
                            cout<<"Tipe Baru: ";
                            cin>>dataKost[i].tipe;
                            cout<<"Harga Baru: ";
                            cin>>dataKost[i].harga;
                            cout<<"Nama Penyewa Baru: ";
                            cin>>dataKost[i].penyewa.nama;
                            cout<<"No HP Baru: ";
                            cin>>dataKost[i].penyewa.noHP;
                            cout<<"Data berhasil diupdate!\n";
                        }
                        else{
                            cout<<"ID kamar tidak ditemukan!\n";
                        }
                    }
                }
                else if(menu==4){
                    int id;
                    cout<<"Masukkan ID kamar yang ingin dihapus: ";
                    cin>>id;
                    for(int i=0;i<jumlahKost;i++){
                        if(dataKost[i].idKamar==id){
                            for(int j=i;j<jumlahKost-1;j++){
                                dataKost[j]=dataKost[j+1];
                            }
                            jumlahKost--;
                            cout<<"Data berhasil dihapus!\n";
                        }
                        else{
                            cout<<"ID kamar tidak ditemukan!\n";
                        }
                    }
                }
            }while(menu!=5);
        }
    }while(pilihanAwal!=3);
    cout<<"Program selesai.\n";
    cout<<"Tekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
}