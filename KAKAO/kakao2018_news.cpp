/*
    [programmers] 2018 KAKAO BLIND RECRUITMENT [1차] 뉴스 클러스터링 **중복체크
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct{ 
    int n1,n2;
}element;
int cnt[2][26][26];

// 교집합크기/합집합크기
// 공집합인 경우 =1
// 교집합: min, 합집합 max
// 1.두글자씩->다중집합원소: 영문자가 아닌경우 그 쌍을 버림.대소문자차이는 무시함. 그럼 숫자로 저장하자.
// 
void init(){
    for(int i=0;i<26;++i){
        for(int j=0;j<26;++j){
            cnt[0][i][j]=0;
            cnt[1][i][j]=0;
        }
    }
    
}
int check(char c){
    if('A'<=c && c<='Z') return c - 'A';
    if('a'<=c && c<='z') return c - 'a';
    return -1;
}
void strToSet(string s, vector<element> &e,int cntI){
    int sz=s.size()-1;
    int n1,n2;
    for(int i=0;i<sz;++i){
        n1=check(s[i]);
        if(n1==-1) continue;
        n2=check(s[i+1]);
        if(n2==-1){ i++;continue;}
        element el={n1,n2};
        if(cnt[cntI][n1][n2]==0) e.push_back(el); 
        cnt[cntI][n1][n2]++;       
    }
}
// void crossSet(vector<element> &e1, vector<element> &e2,int &cE){
//     int sz=e1.size();
//     cE=0;
//     int cnt1,cnt2;
//     //e1에 있는것 중에 e2에 있으면, 갯수 비교해서 더 작은것 개수 추가
//     for(int i=0;i<sz;++i){
//         cnt2=cnt[1][e1[i].n1][e1[i].n2];
//         if(cnt2==0) continue;
//         cnt1=cnt[0][e1[i].n1][e1[i].n2];
//         cE+=min(cnt1,cnt2);
//     }
// }
// void unionSet(vector<element> &e1, vector<element> &e2, int &uE){
//    int sz=e1.size();
//     uE=0;
//     int cnt1,cnt2;
//     //e1에 있는것 중에 e2에 있으면, 갯수 비교해서 더 큰 것 개수 추가
//     //하나라도 있으면 추가
//     for(int i=0;i<sz;++i){    //e1에서는 교집합 추가 안하고 e2에서 추가하자.   
//         cnt1=cnt[0][e1[i].n1][e1[i].n2];
//         cnt2=cnt[1][e1[i].n1][e1[i].n2];        
//         if(cnt2>0) continue;
//         uE+=cnt1;
//     }
//     sz=e2.size();
    
//     for(int i=0;i<sz;++i){
//         cnt2=cnt[1][e2[i].n1][e2[i].n2];  
//         cnt1=cnt[0][e2[i].n1][e2[i].n2];
//         if(cnt1>0) {uE+=max(cnt1,cnt2); continue;}
//         uE+=cnt2;
//     }
// }
void calculateSet(vector<element> &e1, vector<element> &e2, int &cE,int &uE){
    int sz=e1.size();
    uE=0; cE=0;
    int cnt1,cnt2;
    //e1에 있는것 중에 e2에 있으면, 갯수 비교해서 더 큰 것 개수 추가
    //하나라도 있으면 추가
    for(int i=0;i<sz;++i){    //e1에서는 교집합 추가 안하고 e2에서 추가하자.   
        cnt1=cnt[0][e1[i].n1][e1[i].n2];
        cnt2=cnt[1][e1[i].n1][e1[i].n2];        
        if(cnt2>0) continue;
        uE+=cnt1;
    }
    sz=e2.size();
    
    for(int i=0;i<sz;++i){
        cnt2=cnt[1][e2[i].n1][e2[i].n2];  
        cnt1=cnt[0][e2[i].n1][e2[i].n2];
        if(cnt1>0) {uE+=max(cnt1,cnt2); cE+=min(cnt1,cnt2); continue;}
        uE+=cnt2;
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<element> e1,e2;
    int crossE,unionE;
    init();
    strToSet(str1,e1,0);
    strToSet(str2,e2,1);
    //crossSet(e1,e2,crossE);
    //unionSet(e1,e2,unionE);
    calculateSet(e1,e2,crossE,unionE);
    if(unionE==0) answer=65536;
    else answer=65536*crossE/unionE;
    return answer;
}
int main(void){
    
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        cout<<"#"<<t<<"\n";
        string str1, str2;
        cin>>str1>>str2;
        cout<< solution(str1,str2)<<"\n";
        
    }
    return 0;
}