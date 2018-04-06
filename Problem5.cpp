#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

//Asumsi: input selalu terdiri dari:
//Bus i A xx:xx D yy:yy
//Dengan i merupakan bis ke-berapa, xx:xx jam awal, dan yy:yy jam akhir

//Asumsi 2: xx:xx < yy:yy

//Asumsi 3: input diawali dengan '--' dan diakhir dengan '--'

//Contoh input:
/*
--
Bus 1 A 10:00 D 10:05
Bus 2 A 10:05 D 10:15
Bus 3 A 10:10 D 10:30
Bus 4 A 10:25 D 10:40
Bus 5 A 10:45 D 10:50
--
Contoh output:
Maximum bus in station: 2

*/

string s;
int departTime,arrivalTime,cur,res;
vector<pair<int,int> > v;

int convertTime(char a, char b, char c, char d){
    return (a-'0')*600 + (b-'0')*60 + (c-'0')*10 + (d-'0');
}

int main(){
    getline(cin,s);
    while(true){
        getline(cin,s);
        if(s[0] == '-')break;
        arrivalTime = convertTime(s[8],s[9],s[11],s[12]);
        departTime = convertTime(s[16],s[17],s[19],s[20]);
        v.push_back(make_pair(arrivalTime,0));
        v.push_back(make_pair(departTime,1));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i].second ==  0)cur++;
        else cur--;
        res = max(res,cur);
    }
    cout<<"Maximum bus in station: " << res<<endl;
}
