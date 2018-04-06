#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;

//Tipe data customer berisi transaksi apa saja yang telah dilakukan customer,
//email yang pernah digunakan, nomor telepon yang pernah digunakan, dan kartu
//yang pernah digunakan. Method yang dimiliki::
//transactionOutput() : Mengeluarkan semua transaksi yang pernah dilakukan
//emailOutput() : Mengeluarkan semua email yang pernah digunakan
//phoneOutput() : Mengeluarkan semua nomor telepon yang pernah digunakan
//cardOutput() : Mengeluarkan semua kartu yang pernah digunakan

struct customer{
    set<int> transaction;
    set<string> email, phone, card;

    void transactionOutput(){
        for (auto cek = transaction.begin(); cek != transaction.end(); ++cek){
            cout<<*cek<<" ";
        }
        cout<<endl;
    }
    void emailOutput(){
        for (auto cek = email.begin(); cek != email.end(); ++cek){
            cout<<*cek<<" ";
        }
        cout<<endl;
    }
    void phoneOutput(){
        for (auto cek = phone.begin(); cek != phone.end(); ++cek){
            cout<<*cek<<" ";
        }
        cout<<endl;
    }
    void cardOutput(){
        for (auto cek = card.begin(); cek != card.end(); ++cek){
            cout<<*cek<<" ";
        }
        cout<<endl;
    }
};

int lastCustomer, currentCustomer;
customer dataCustomer[105];
int id,emailFind,phoneFind,cardFind;
map<string,int> dataEmail,dataPhone,dataCard;
string email,phone,card;

//Memasukkan data ke list customer

void insertData(int targetCustomer, int id, string email, string phone, string card){
    dataCustomer[targetCustomer].transaction.insert(id);
    dataCustomer[targetCustomer].email.insert(email);
    dataCustomer[targetCustomer].phone.insert(phone);
    dataCustomer[targetCustomer].card.insert(card);
    dataEmail[email] = targetCustomer;
    dataPhone[phone] = targetCustomer;
    dataCard[card] = targetCustomer;
}

//Memerge 2 buah customer

void mergeData(int data1, int data2){
    if(data2 == data1)return;
    else if(data2 < data1) swap(data1,data2);
    customer &customer1 = dataCustomer[data1];
    customer customer2 = dataCustomer[data2];
    for(auto it = customer2.transaction.begin(); it != customer2.transaction.end(); ++it){
        customer1.transaction.insert(*it);
    }
    for(auto it = customer2.email.begin(); it != customer2.email.end(); ++it){
        customer1.email.insert(*it);
        dataEmail[*it] = data1;
    }
    for(auto it = customer2.phone.begin(); it != customer2.phone.end(); ++it){
        customer1.phone.insert(*it);
        dataPhone[*it] = data1;
    }
    for(auto it = customer2.card.begin(); it != customer2.card.end(); ++it){
        customer1.card.insert(*it);
        dataCard[*it] = data1;
    }
    for(int i = data2; i < lastCustomer-1; i++){
        dataCustomer[i] = dataCustomer[i+1];
    }
    customer temp;
    dataCustomer[lastCustomer] = temp;
    lastCustomer--;
}

//Program ini menerima input dengan format:
//id_transaksi email phone card
//Contoh:
//1 e1 p1 c1
//2 e2 p2 c2
//3 e1 p3 c3
//4 e4 p4 c4
//5 e2 p4 c5
//Dan setiap baris akan mengeluarkan semua list Customer yang telah masuk

int main(){
    lastCustomer = 1;
    while(true){
        cin>>id>>email>>phone>>card;
        emailFind = dataEmail[email];
        phoneFind = dataPhone[phone];
        cardFind = dataCard[card];
        if(emailFind != 0){
            currentCustomer = emailFind;
            if(phoneFind != 0){
                mergeData(emailFind,phoneFind);
            }
            if(cardFind != 0 and cardFind != phoneFind){
                mergeData(emailFind,cardFind);
            }
        } else if(phoneFind != 0){
            currentCustomer = phoneFind;
            if(emailFind != 0){
                mergeData(phoneFind,emailFind);
            }
            if(cardFind != 0 and cardFind != emailFind){
                mergeData(phoneFind,cardFind);
            }
        } else if(cardFind != 0){
            currentCustomer = cardFind;
            if(phoneFind != 0){
                mergeData(cardFind,phoneFind);
            }
            if(emailFind != 0 and emailFind != cardFind){
                mergeData(cardFind,emailFind);
            }
        } else{
            currentCustomer = lastCustomer;
            lastCustomer++;
        }
        insertData(currentCustomer,id, email, phone, card);

        for (int i = 1; i < lastCustomer; i++){
            cout<<"Customer: "<<i<<endl;
            //customer temp = )
            cout<<"Transactions:";
            dataCustomer[i].transactionOutput();

            cout<<"Email:";
            dataCustomer[i].emailOutput();

            cout<<"Phones:";
            dataCustomer[i].phoneOutput();

            cout<<"Card:";
            dataCustomer[i].cardOutput();

            cout<<endl;
        }
    }
}
