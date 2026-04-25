#ifndef KOST_LIB_H
#define KOST_LIB_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_DATA = 100;

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

class KostException : public runtime_error {
public:
    KostException(const string& msg) : runtime_error(msg) {}
};

#endif