#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 21;
int A[maxN][maxN];
int P[5];
int N;
int minDiff;

void read(){
    cin>>N;
    for(int i = 1; i <=N; ++i){
        for(int j = 1; j <= N; ++j){
            cin>>A[i][j];
        }
    }    
}
void init(){
    for(int i = 0 ; i<5; ++i){
        P[i] = 0;
    }
    minDiff =100000;
}
void calculateP(int x, int y, int d1, int d2){
    int P[5]={0,};
    int area = -1;
    
    for(int i = 1; i<=N; ++i){
        for(int j =1; j<=N; ++j){
            int D1 = i-x;
            int D2 = j-y;
            
            if( 0<=D1+D2 && D1+D2 <= d2*2 && 0 <=D1-D2 && D1-D2<=d1*2){
                area = 4;
            }
            //1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
            else if( (i < x+d1) && (j <= y)){
                area = 0;
            }
            else if((i <= x+d2)&&( y <j )){
                //2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
                area = 1;      
            }else if ((x+d1 <= i) && (j < (y-d1+d2))){
                //3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
               area = 2;
            }else if ( (x+d2 < i) && (y-d1+d2 <= j)){
                //4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
                area = 3;
            }else{
               area = -1;

            }
            P[area] += A[i][j];
          //  cout<<area<<" ";
        } 
     //   cout<<"\n";
    }
  //  cout<<"\n";
    int maxP = max( max( max(P[0],P[1]), max(P[2],P[3])), P[4]);
    int minP = min( min( min(P[0],P[1]), min(P[2],P[3])), P[4]);
  //  cout<<"DIFF: "<<maxP-minP<<"\n";
    minDiff = min( minDiff, maxP-minP);
}
void solve(){
    for(int r = 1; r<=N; ++r){
        for(int c = 1; c<=N; ++c){
            //check (r,c)
            for(int d1 = 1; d1<=N; ++d1){
                for(int d2 = 1; d1+d2<=N; ++d2){
                    //d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
                    if((r+d1+d2 > N) || (c-d1 < 1) ||(c+d2 > N)) continue;
                    cout<<"("<<r<<","<<c<<"),("<<d1<<","<<d2<<")"<<"\n";
                    calculateP(r,c,d1,d2);
                }
            }
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
        solve();
        cout<<"#"<<test<<" "<<minDiff<<"\n";
    }

    return 0;
}














