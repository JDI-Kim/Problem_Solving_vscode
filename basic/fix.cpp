/*
    BOJ #1449. 수리공 항승 **인풋 정렬해야함 
*/
#include <iostream>
#include <algorithm>

using namespace std;
int N,L;
const int maxN=1000+2;
int P[maxN];
int tape;
void read(){
    cin>>N>>L;
    for(int i=0;i<N;++i){
        cin>>P[i];
    }
    sort(P,P+N);

}
void taping(){
    int first=P[0]-0.5;
    tape=1;
    for(int i=1;i<N;++i){
        if(first+L<P[i]){first=P[i]-0.5;tape++;}
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
    
        read();
        taping();
        cout<<"#"<<test<<" "<<tape<<"\n";
    }
    
    return 0;
}
