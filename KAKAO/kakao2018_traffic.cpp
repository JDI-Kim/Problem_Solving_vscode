/*
    [programmers] 2017 카카오코드 예선 보행자 천국
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int>> cnt;
    for(int i=0;i<m;++i){
        vector<int> v;
        for(int j=0;j<n;++j){
            v.push_back(0);
        }
        cnt.push_back(v);
    }
    for(int i=0;i<m;++i){
       //첫번째 줄1이 나올때까지 1을 넣는다
        if(city_map[i][0]==1)break;
        cnt[i][0]=1;
    }
    for(int j=0;j<n;++j){
        if(city_map[0][j]==1)break;
        cnt[0][j]=1;
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(city_map[i][j]==1) {cnt[i][j]=0;continue;}
            int left=0; int up=0;
            if(city_map[i][j-1]!=2){left=cnt[i][j-1];}
            else{
                for(int k=j-2;k>=0;--k){
                    if(city_map[i][k]!=2){ left=cnt[i][k];break;}
                }
            }
            if(city_map[i-1][j]!=2){up=cnt[i-1][j];}
            else{
                for(int k=i-2;k>=0;--k){
                    if(city_map[k][j]!=2){ up=cnt[k][j];break;}
                }
            }
            cnt[i][j]=left+up;   
            if(cnt[i][j]>=MOD) cnt[i][j]%=MOD;
        }
    }
    answer=cnt[m-1][n-1];
    return answer;
}