/*
    BOJ #1759 암호만들기 DFS
*/
#include <iostream>
#include <algorithm>
using namespace std;
int L,C;
const int maxL=15+1;
const int maxC=15+1;
char alphabet[maxC];
char result[maxL];
bool visit[maxC];

void read(){
    cin>>L>>C;
    for(int i=0;i<C;++i){
        cin>>alphabet[i];
    }
    sort(alphabet,alphabet+C);
}

void init(){
    for(int i=0;i<C;++i){
        visit[i]=false;
    }
}

bool check(){
    int aeiou=0;
    for(int i=0;i<L;++i){
       if(result[i]=='a' || result[i]=='e' ||result[i]=='i' ||result[i]=='o' ||result[i]=='u'){
            aeiou++; 
       }
    }
    if(aeiou==0) return false;
    if(L-aeiou<2) return false;
    return true;
}

void solve(int count, int startI){
    if(count==L) {
        if(check()){ cout<<result<<"\n";}
        return;
    }
    for(int i=startI;i<C;++i){
        if(visit[i])continue;
        result[count]=alphabet[i];
        visit[i]=true;
        solve(count+1,i+1);
        visit[i]=false;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        
        cout<<"#"<<test<<" "<<"\n";
        solve(0,0);
    }

    return 0;
}