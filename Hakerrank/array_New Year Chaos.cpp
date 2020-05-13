/*
    [Hackerrank] Practice > Interview Preparation Kit > Arrays > New Year Chaos
    * 전처리는 전에 해야 됨. 문제 푸는 중에 q가 바뀌기 때문에 바뀌기 전을 확인해야지 
    * 하나씩 옮겨서 저장할 때 인덱스 주의
    from: https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.

void minimumBribes(vector<int> q) {
    int sz = q.size();
    int result=0;

    for(int i=0;i<sz;++i){
       if(q[i]>i+3) {cout<<"Too chaotic\n"; return;}
    }

    for(int i=sz-1; i>0; --i){
        if(q[i]==i+1) continue;
        int temp=q[i];
        if(1<=i && q[i-1]==i+1){
            q[i]=q[i-1];
            q[i-1]=temp;
            result+=1;
            continue;
        } 
        if(2<=i &&q[i-2]==i+1){
            q[i]=q[i-2];
            q[i-2]=q[i-1];
            q[i-1]=temp;
            
            result+=2;
            continue;
        }
    }

   cout<<result<<"\n";
   return;
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item ;
            cin>>q_item;

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}
