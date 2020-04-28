#include <iostream>
#include <algorithm>
using namespace std;
int  x,n;
const int maxX=20+1;
const int maxN=1000000+1;
int l[maxN];
int diff;
int l1,l2;
void read(){
    int cnt=0;
    diff=l1=l2=-1;
    cin>>n;

    x *=10000000;
   
    int temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        if(temp>x) continue;
        l[cnt]=temp;
        
        for(int j=0;j<cnt;++j){
            if(l[cnt]+l[j]!=x)continue;
            int tempDiff =abs(l[cnt]-l[j]);
            if(diff>=tempDiff)continue;
            l1=l[j];
            l2=l[cnt];
            diff=tempDiff;                
        }
        cnt++;
    }
    if(diff==-1) cout<<"danger"<<"\n";
    else{
        if(l2<l1){int num=l1; l1=l2;l2=num;}
        cout<<"yes "<<l1<<" "<<l2<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>x)
    {        
        read();
    }
    // int Test;
    // cin>>Test;
    // for(int test=1;test<=Test;++test){
        
    //     cout<<"#"<<test<<" "<<"\n";
    //     read();
    // }
    return 0;
}