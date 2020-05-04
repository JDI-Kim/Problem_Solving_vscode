/*
    [programmers] 2019 카카오 개발자 겨울 인턴십 튜플 **파싱 제대로..
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int maxN=500+1;
vector<int> res[maxN];
/*
string에서 1개,2개,3개...최대 500개짜리의 집합을 분리해냄 
vector500에 넣고, 사이즈별로 인덱스 만들어서 
이전 집합에 포함된 애들은 자리가 정해졌으니 이전 집합에서 없었던 원소를 찾아서 다음 자리에 넣으면 됨.
*/
void init(){
    for(int i=0;i<500;++i){
        res[i].clear();
    }
}
void strToVector(string s, int &tuple_size){
    int sz=s.size()-2;
    int startI,endI;
    vector<string> v;
    for(int i=2;i<sz;++i){
        if(s[i-1]=='{') {
            startI=i;            
        }
        if(s[i+1]=='}') {
            endI=i;  
            string str=s.substr(startI,endI-startI+1);
            v.push_back(str);
        }
    }
    tuple_size=v.size();
    vector<int> vec;
    for(int i=0;i<tuple_size;++i){
        vec.clear();
        int len=v[i].size();
        int num=0;
        for(int j=0;j<=len;++j){
            if(v[i][j]==','||j==len){
                vec.push_back(num);
                num=0;
                continue;

            }
            num = num*10+(v[i][j]-'0');
        }
        int cnt=vec.size();
        res[cnt]=vec;
    }
    
}
void makeTuple(int t_s, vector<int> &ans){

  
    ans.push_back(res[1][0]);
    for(int i=2;i<=t_s;++i){
        int sz=i-1;
        int num=res[i][sz];
        for(int j=0;j<i;++j){ //size==i
            bool ck=false;
            for(int k=0;k<sz;++k){
                if(ans[k]==res[i][j]) ck=true;
            }
            if(!ck) {num=res[i][j];break;}
        }
        ans.push_back(num);
    }
    
}
vector<int> solution(string s) {

    vector<int> answer;
    int tupleSize=0;
    init();
    strToVector(s,tupleSize);
    makeTuple(tupleSize,answer);
    return answer;
}
int main(void){
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        cout<<"#"<<t<<"\n";

        string str;
        cin>>str;
        vector<int> result=solution(str);
        int sz=result.size();
        cout<<"result: "<<"\n";
        for(int i=0;i<sz;++i){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}