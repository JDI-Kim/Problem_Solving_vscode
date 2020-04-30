/*
    BOJ #5052 전화번호 목록. 정렬, 서치
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n;
const int maxN=10000+1;
string tel[maxN];
void read(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tel[i];
    }
}
bool solve(){
    sort(tel,tel+n);
    
    for(int i=0;i<n;++i){
        int j=i+1;
        int sz=tel[i].size();
        while(sz<tel[j].size() && tel[i][0]==tel[j][0]){
            bool isSub=true;
            for(int k=1;k<sz;++k){
                if(tel[i][k]==tel[j][k]) continue;
                isSub=false; break;
            }
            if(isSub) return true;
            j++;
        }
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        if(solve()) cout<<"NO\n";
        else cout<<"YES\n";
        cout<<"#"<<test<<" "<<"\n";
    }
    return 0;
}