/*
    [programmers] 2018 KAKAO BLIND RECRUITMENT 비밀지도  *벡터쓰는법 알아둘 것
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

*/
#include <string>
#include <vector>

using namespace std;
const int maxN=16;

void makeBinary(int n, vector<int> arr, vector<vector<int> > &result){
    
    for(int i=0;i<n;++i){
        vector<int> vec;
        for(int j=0;j<n;++j){
            vec.insert(vec.begin(),arr[i]%2);
            arr[i]=arr[i]/2;
        }
        result.push_back(vec);
    }
}
void makeMap(int n, vector<vector<int> > &map1, vector<vector<int> > &map2, vector<string> &ans){
    
    int check=-1;
    for(int i=0;i<n;++i){
        string str="";
        for(int j=0;j<n;++j){
            check=map1[i][j]+map2[i][j];
            if(check>=1){//wall
                str+="#";
                continue;
            }
            //check==0, blank
            str+=" ";            
        }
        ans.push_back(str);
        
    }
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int> > a1, a2;
    makeBinary(n,arr1,a1);
    makeBinary(n,arr2,a2);
    makeMap(n,a1,a2,answer);
    return answer;
}