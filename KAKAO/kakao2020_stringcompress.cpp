/*
    [programmers] 2020 KAKAO BLIND RECRUITMENT 문자열 압축

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int result;

int countNum(string &s, int len){
    int sz=s.size();
    int cnt=0;
    int last=0;
    string ans="";
    for(int i=0;i<sz;i+=len){
        
        string temp=s.substr(i,len);
        string temp2;
        int tempCnt=1;
        for(int j=i+len;j<sz;j+=len){
            temp2=s.substr(j,len);
            if(temp!=temp2) { break;}
            cnt++;
            tempCnt++;
        }
        i+=(tempCnt-1)*len;
        if(tempCnt>1) { ans.append(to_string(tempCnt));}
        last=i;
    }
    int result=sz - len*cnt + ans.size();
    if(cnt==0) return sz;
    return result;
}
int solution(string s) {
    int sz=s.size();
    int answer = sz;
    int len=sz/2;
    int temp;
    for(int i=len; i>0; --i){
        temp=countNum(s,i);
        if(temp<answer)answer=temp;
    }
    return answer;
} 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        string str;
        cin>>str;
        result=solution(str);
        cout<<"#"<<test<<" "<<result<<"\n";
    }
    return 0;
}