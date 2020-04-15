/*
BOJ #1652. 누울 자리를 찾아라
Solved by J. Kim
*/
#include <iostream>
using namespace std;
int N;
const int maxN=100;
char room[maxN][maxN];
int result_row,result_column;
void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>room[i][j];
        }
    }
}
void init(){
    result_row=0;
    result_column=0;
}
void solve(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N-1;++j){
            if(room[i][j]=='.'&&room[i][j+1]=='.')
            {
                result_row++;
                while(room[i][j]=='.'&&j<N-1) ++j;
            }
        }
    }
    for(int j=0;j<N;++j){
        for(int i=0;i<N-1;++i){
            if(room[i][j]=='.'&&room[i+1][j]=='.'){
            result_column++;
            while(room[i][j]=='.'&&i<N-1) ++i;
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
        cout<<"#"<<test<<" "<<result_row<<" "<<result_column<<"\n";
    }
    return 0;
}