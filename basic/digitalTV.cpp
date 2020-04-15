/*
    BOJ #2816. 디지털티비
*/
#include <iostream>
#include <string>
using namespace std;
int N;
const int maxN=100;
char name[maxN][11];
int nKBS1;
int nKBS2;
void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>name[i];
        if(name[i][4]!='\0') continue;
        if( (name[i][0]=='K') && (name[i][1]=='B')  &&  (name[i][2]=='S')){
            if( name[i][3]=='1') {nKBS1=i;}
            else if (name [i][3]=='2'){nKBS2=i;}           
        }
    }
    
}
void init(){
}

void solve(){
    if(nKBS1<nKBS2){
        for(int i=0;i<nKBS1;++i){
            cout<<1;
        }
        for(int i=nKBS1;i>0;--i){
            cout<<4;
        }
        for(int i=0;i<nKBS2;++i){
            cout<<1;
        }
        for(int i=nKBS2;i>1;--i){
            cout<<4;
        }
    }
    else{
         for(int i=0;i<nKBS2;++i){
            cout<<1;
        }
        for(int i=nKBS2;i>0;--i){
            cout<<4;
        }
        for(int i=0;i<nKBS1;++i){
            cout<<1;
        }
        for(int i=nKBS1;i>0;--i){
            cout<<4;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        init();
        cout<<"#"<<test<<" "<<"\n";
        solve();
        cout<<" "<<"\n";

    }
    return 0;
}