#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Asumsi: Jika kita menghapus satu jenis char (misal: 'a'), maka kita akan
//menghapus semua karakter 'a' di kedua string tersebut

//Asumsi kedua: char dapat dinyatakan dalam ascii(0 - 255)

int cnt[256];
string s1,s2;
int res;
vector<char> deleteChar;

void add(string a, int val){
    for(int i = 0; i < a.size(); i++){
        cnt[a[i]] += val;
    }
}

/*
Contoh input:
abcde
bczah
Contoh output:
4
Removing: d,e,h,z

*/

int main(){
    cout<<"String 1:"<<endl;
    cin>>s1;
    cout<<"String 2:"<<endl;
    cin>>s2;

    add(s1,1);
    add(s2,-1);
    for(int i = 0; i <= 255; i++){
        if(cnt[i] != 0){
            deleteChar.push_back(i);
            res++;
        }
    }
    cout<<res<<endl;
    if(res != 0){
        cout<<"Removing: ";
        for(int i = 0; i < deleteChar.size(); i++){
            cout<<deleteChar[i];
            if(i==deleteChar.size()-1)cout<<endl;
            else cout<<",";
        }
    }
}
