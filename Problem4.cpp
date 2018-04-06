#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct passenger{
    string name;
    int origin, dest;

};

//Asumsi: n <= 50, lantai <= 30

int opsi[10005];
pair<pair<int,int>,int> val[10005];
int dp[55][55][35],finalCondition;
bool visited[5][1<<6][1<<6];
int nex[10005];
int dest[10005],ori[10005];
const int upCost = 1;
const int downCost = 1;
const int embarkCost = 2;
const int disembarkCost = 2;

priority_queue<pair<pair<int,int>,pair<int,pair<int,int> > > > pq;

void inputPq(int nowCost, int nowPos, int finishedPassenger, int curPassenger, int lastCondition){
    pq.push(make_pair(make_pair(nowCost,nowPos),make_pair(finishedPassenger,make_pair(curPassenger,lastCondition))));
}

int minCost(){
    int nowCost = 0;
    int nowPos = 1;
    int finishedPassenger = 0;
    int curPassenger = 0;
    int lastCondition = 0;
    int curVal = 0;
    inputPq(nowCost,nowPos,finishedPassenger,curPassenger,lastCondition);
    while(!pq.empty()){
        pair<pair<int,int>,pair<int,pair<int,int> > > top = pq.top();
        pq.pop();
        nowCost = top.first.first;
        nowPos = top.first.second;
        finishedPassenger = top.second.first;
        curPassenger = top.second.second.first;
        lastCondition = top.second.second.second;
        curVal++;

        if(visited[nowPos][finishedPassenger][curPassenger])continue;
        visited[nowPos][finishedPassenger][curPassenger] = 1;
        nex[curVal] = lastCondition;

        int lastPos = val[lastCondition].first.first;
        int lastFinishedPassenger = val[lastCondition].first.second;
        int CurPassenger = val[lastCondition].second;

        if(lastPos > nowPos)opsi[curVal] = 1;
        else if(lastPos < nowPos)opsi[curVal] = -1;
        else if(lastFinishedPassenger != finishedPassenger)opsi[curVal] = -2;
        else opsi[curVal] = 2;

        if(finishedPassenger ==  (1<<5)-1){
            finalCondition = curVal;
            return nowCost;
        }

        if(nowPos < 5)inputPq(nowCost+1,nowPos+1,finishedPassenger,curPassenger,curVal);
        if(nowPos > 1)inputPq(nowCost+1,nowPos+1,finishedPassenger,curPassenger,curVal);
        int temp = curPassenger;
        int cur = 0;
        while(temp){
            if(temp%2){
                if(dest[cur] == nowPos)inputPq(nowCost+2,nowPos,finishedPassenger+(1<<cur),curPassenger-(1<<cur),curVal);
            }
        }
        temp = finishedPassenger;
        cur = 0;
        while(temp){
            if(temp%2){
                if(ori[cur] == nowPos)inputPq(nowCost+2,nowPos,finishedPassenger,curPassenger+(1<<cur),curVal);
            }
            temp /= 2;
            cur++;
        }
    }
}

//Mereturn langkah-langkah yang dilakukan oleh lift untuk mendapatkan minimalcost
//Asumsi: ori[] dan dest[] sudah terisi

vector<string> smallestCost(vector<passenger> passengerList){
    int nowPos = 1;
    int arrivedPassenger = 0;
    int currentPassenger = 0;
    vector<string> res;
    cout<<minCost()<<endl;
    while(finalCondition != 0){
        int curState = opsi[finalCondition];
        if(curState == -1){
            res.push_back("Down");
            nowPos -= 1;
        } else if(curState == 1){
            res.push_back("Up");
            nowPos += 1;
        } else if(curState == 2){
            res.push_back("Embark");
            currentPassenger += 1;
        } else{
            res.push_back("Disembark");
            arrivedPassenger += 1;
            currentPassenger -= 1;
        }
        finalCondition = nex[finalCondition];
    }
    reverse(res.begin(),res.end());
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }
    return res;
}

int main(){
    passenger p1;
    passenger p2;
    passenger p3;
    passenger p4;
    passenger p5;

}
