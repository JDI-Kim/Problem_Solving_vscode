/*
    BOJ #1931 회의실 배정. 정렬
 */
#include <iostream>
#include <algorithm>

using namespace std;
int N;
const int maxN=100000;
typedef struct{
    int startTime, endTime;
}info;
info input[maxN];
bool operator<(info a, info b){
    return a.startTime<b.startTime;
}
void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>input[i].startTime>>input[i].endTime;
    }
    sort(input,input+N);
}
void solve(){
    int curEndTime=0;
    bool isEmpty=true;
    int numMeeting=0;
    for(int i=0;i<N;++i){
        if(isEmpty){ isEmpty=false; curEndTime=input[i].endTime; numMeeting++; continue;}
        if(curEndTime<=input[i].startTime){curEndTime=input[i].endTime; numMeeting++; continue;}
        if(input[i].endTime<curEndTime){curEndTime=input[i].endTime;continue;}

    }
    cout<<"NUM MEETING: "<<numMeeting<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();

        cout<<"#"<<test<<" "<<"\n";
        solve();
    }
    return 0;
}