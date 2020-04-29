/*
    BOJ #1764  듣보잡. **정렬과 이진탐색.. 숫자가 커요.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int N,M;
const int maxN=500000;
int cnt;
string names[maxN];

bool existName(string str,int first,int last){
    if(first>last)return false;
    int mid=(first+last)/2;
    if(names[mid]==str) return true;
    if(str<names[mid]) return existName(str,first,mid-1);
    if(names[mid]<str) return existName(str,mid+1,last);
    return false;
}
void read(){
    cin>>N>>M;

    for(int i=0;i<N;++i){
        cin>>names[i];
    }
    sort(names,names+N);
    string temp;
    priority_queue<string,vector<string>,greater<string> > q;
    for(int i=0;i<M;++i){
        cin>>temp;
        if(existName(temp,0,N-1)){
            q.push(temp);
        }
    }
    cout<<q.size()<<"\n";
    while(!q.empty()){
        cout<<q.top()<<"\n";
        q.pop();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        cout<<"#"<<test<<" "<<"\n";
        read();
    }
    return 0;
}