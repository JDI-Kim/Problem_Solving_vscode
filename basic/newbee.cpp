/*
    BOJ #1946 신입사원 **시간초과주의
    - 각 input의 등수가 이미 정해져있으므로 index이용해서 저장하면 정렬안해도 됨.
    - 면접 1등의 서류등수 아래 사람들은 다 탈락
    - 서류 1등의 면접등수 아래 사람들은 다 탈락
    이므로, 둘 중 등수 높은 애를 골라서, 그 위 등수만 확인하면 됨.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int maxN=100001;
int maxNewCrew;
int orderDoc[maxN];
int orderItv[maxN];

void init(){
    maxNewCrew=N;
}
void read(){
    cin>>N;
    init();
    int D,I;
    for(int i=0;i<N;++i){
        cin>>D>>I;
        orderDoc[D]=I;
        orderItv[I]=D;
    }
}
void solve(){
    int minOrder=N+1;
    if(orderDoc[1]<orderItv[1]){
        maxNewCrew=orderDoc[1];
        for(int i=1;i<orderDoc[1];++i){
            if(orderItv[i]<minOrder){
                minOrder=orderItv[i];
                continue;
            }
            maxNewCrew--;
        }
    }else{
        maxNewCrew=orderItv[1];
        for(int i=1;i<orderItv[1];++i){
            if(orderDoc[i]<minOrder){
                minOrder=orderDoc[i];
                continue;
            }
            maxNewCrew--;
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
        solve();
        cout<<"#"<<test<<" "<<maxNewCrew<<"\n";
    }
    return 0;
}