/*
    [codility] binary gap 
    출처: https://app.codility.com/programmers/lessons/1-iterations/ 
*/
#include <iostream>
using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int max_gap = 0;
    int gap = 0;
    bool start_gap = false;
    
    //binary
    while(N>0){
        if(N%2==1){
            if(start_gap){
                if(max_gap < gap) max_gap = gap;
            }else{
                start_gap = true;
            }
            gap = 0;
        }else{
            if(start_gap){
                gap++;
            }
        }
        N=N/2;
    }
    return max_gap;
}
int main(void){
    int T;
    cin>>T;
    for(int i=1;i<=T;++i){
        int n;
        cin>>n;
        cout<< "#"<<i<<" "<<solution(n)<<"\n";         
    }
}