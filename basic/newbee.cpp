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
typedef struct{
    int doc, interview;
    bool check;
}info;
info input[maxN];
int orderDoc[maxN];
int orderItv[maxN];
bool operator<(info a, info b){
    return a.doc<b.doc;
}
void init(){
    maxNewCrew=N;
    for(int i=0;i<N;++i){
        input[i].check=true;
    }
}
void read(){
    cin>>N;
    init();
    for(int i=0;i<N;++i){
        cin>>input[i].doc>>input[i].interview;
        orderDoc[input[i].doc]=i;
        orderItv[input[i].interview]=i;
    }
}
void solve(){
    int docOrderofFirstItv=input[orderItv[1]].doc;
    int itvOrderofFirstDoc=input[orderDoc[1]].interview;
    if(docOrderofFirstItv<itvOrderofFirstDoc){
        maxNewCrew=docOrderofFirstItv;
        int minOrder=N+1;
        for(int i=1;i<docOrderofFirstItv;++i){
            int order=input[orderDoc[i]].interview;
            if(minOrder>order){
                minOrder=order;
                continue;
            }
            maxNewCrew--;
        }

    }else{
        maxNewCrew=itvOrderofFirstDoc;
        int minOrder=N+1;
        for(int i=1;i<itvOrderofFirstDoc;++i){
            int order=input[orderItv[i]].doc;
            if(minOrder>order){
                minOrder=order;
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