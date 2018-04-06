#include <iostream>
#include <string>
#include <map>
using namespace std;

//Asumsi: input selalu diawali oleh
//input: (angka)

//Asumsi 2: input tidak perlu divalidasi

string s,name;
int n;
map<string,int> cnt;

/*
Contoh input:
input : 10
add hendra
add sreix
add maji
add srimulyani
add hendro
add heru
find sr
find he
find hen
find m

Contoh output:
2
3
2
1

*/

int main(){
    getline(cin,s);
    for(int i = 8; i < s.size(); i++){
        n *= 10;
        n += (s[i]-'0');
    }
    for(int i = 1; i <= n; i++){
        getline(cin,s);
        name = "";
        if(s[0] == 'a'){
            for(int j = 4; j < s.size(); j++){
                name += s[j];
                cnt[name]++;
            }
        } else{
            for(int j = 5; j < s.size(); j++){
                name += s[j];
            }
            cout<<cnt[name]<<endl;
        }
    }
}
