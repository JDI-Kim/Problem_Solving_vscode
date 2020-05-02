/*
    [programmers] 2020 KAKAO BLIND RECRUITMENT 괄호변환 *재귀함수, 시뮬레이션
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool checkString(string &p){
    int sz=p.size();
    int left=0;
    int right=0;
    for(int i=0;i<sz;++i){
        if(p[i]=='(')left++;
        else right++;
        if(right>left)return false;
    }
    return true;
}
void separateString(string &p, string &u, string &v){
    int sz=p.size();
    int cnt=0; 
    for(int i=0;i<sz;++i){
        if(p[i]=='(') cnt++;
        else cnt--;
        if(cnt==0) {            
            u=p.substr(0,i+1);
            v=p.substr(i+1,sz-1);
            return;
        }
    }    
}
string solution(string p) {
    string answer = "";

    if(p=="") return p;
    if(checkString(p)) return p;
    
    string u, v;
    separateString(p,u,v);
    if(checkString(u)) return u + solution(v);

    int sz=u.size();
    u=u.substr(1,sz-2);
    for(int i=0;i<sz;++i){
        if(u[i]=='(') u[i]=')';
        else u[i]='(';
    }
    answer = "(" + solution(v) + ")" + u;

    return answer;
}

int main(void)
{
    int Test;
    cin>>Test;
    string p;
    for(int test=1;test<=Test;++test){
        cin>>p;
        cout<<solution(p)<<"\n";
    }
    return 0;
}