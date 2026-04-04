#include <iostream>
using namespace std;
void tambah(int *x){
    *x = *x + 5;
}
void tambahbukan(int x){
    x = x + 5;
}
int main(){
    
    int angka = 5;
    // tambahbukan(angka);
    tambah(&angka);
    cout << angka;
    cout << "pointer yang menunjuk ke suatu array"<< endl;
    int a[5] = {1,2,3,4,5}; 
    int (*aPtr)[5] = &a; 
    for (int i =0; i <5; i++){ 
        cout<<aPtr<<endl;
    }
    return 0;
}