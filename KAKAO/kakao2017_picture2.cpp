/*
    [programmers] 2017 카카오코드 본선 * DFS
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int maxF=8;
int seat[maxF];
int pos[maxF];
bool visit[maxF];
int num;
typedef struct{
    int n1,n2;
    char op;
    int dis;
}info;
vector<info> INFO;

int nameToNumber(char c){
    switch(c){
        case 'A': return 0;
        case 'C': return 1;
        case 'F': return 2;
        case 'J': return 3;
        case 'M': return 4;
        case 'N': return 5;
        case 'R': return 6;
        case 'T': return 7;
    }
    return -1;
}
void init(int n,vector<string> &d){
    num=0;
    for(int i=0;i<maxF;++i){
        seat[i]=pos[i]=-1;
        visit[i]=false;
    }
    INFO.clear();
    
    for(int i=0;i<n;++i){
        info I;
        I.n1=nameToNumber(d[i][0]);
        I.n2=nameToNumber(d[i][2]);
        I.op=d[i][3];
        I.dis= d[i][4]-'0';
        INFO.push_back(I);
    }
}
bool checkCondition(){
    int sz=INFO.size();
    for(int i=0;i<sz;++i){
        info I=INFO[i];
        int D = abs(pos[I.n1]-pos[I.n2])-1;
        if(I.op=='<'){
            if(D>=I.dis) return false;
            continue;
        }else if(I.op=='>'){
            if(D<=I.dis) return false;
            continue;
        }else{ // =
            if(D!=I.dis) return false;
            continue;
        }
    }
    return true;
}
void allCase(int count){
    if(count==maxF){
        if(checkCondition()) num++;
        return;
    }
    for(int i=0;i<maxF;++i){
        if(visit[i])continue;
        visit[i]=true;
        pos[i]=count;
        seat[count]=i;
        allCase(count+1);
        pos[i]=-1;
        visit[i]=false;
    }    
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    init(n,data);
    allCase(0);
    answer=num;
    return answer;
}

 int main(void){
     ios::sync_with_stdio(false);
     cin.tie(0);
     int Test;
     cin>>Test;

     for(int test=1;test<=Test;++test){
         int n;
         string str;
         vector<string> data;
         cin>>n;
         for(int i=0;i<n;++i){
             cin>>str;
            data.push_back(str);
         }
            
         cout<<"#"<<test<<" "<<solution(n,data)<<"\n";
     }

     return 0;
 }