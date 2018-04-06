#include <iostream>
#include <string>
using namespace std;

string phone,normalizedPhone;
bool cekDepan;

//Pengunaan: Masukkan nomor telepon yang ingin dinormalisasi, contoh:
//08111338062 / 08788
//Maka ia akan menghapus karakter selain angka dan mengubah angka 0 didepannya
//dan mengubah angka 0 didepan sehingga output menjadi
//62811133806208788

//Namun jika tidak ada satupun karakter angka, maka output dari user = input

int main(){
    cekDepan = true;
    cout<<"Phone: "<<endl;
    getline(cin,phone);
    for(int i = 0; i < phone.size(); i++){
        if(cekDepan){
            if(phone[i] == '0'){
                normalizedPhone += "62";
                cekDepan = false;
            } else if(phone[i] > '0' and phone[i] <= '9'){
                normalizedPhone += phone[i];
                cekDepan = cekDepan;
            }
        } else if(phone[i] >= '0' and phone[i] <= '9'){
            normalizedPhone += phone[i];
        }
    }
    cout<<"normalized_phone: ";
    if(normalizedPhone.size() == 0){
        cout<<phone<<endl;
    } else{
        cout<<normalizedPhone<<endl;
    }
}
