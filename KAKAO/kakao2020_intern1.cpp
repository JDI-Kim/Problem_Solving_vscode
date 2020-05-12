#include <iostream>
#include <vector>

using namespace std;
long maximumProfit(vector<int> price) {
    long result=0;
    int sz=price.size();
    long max=-1;
    for(int i=sz-1;i>=0;--i){
        cout<<price[i]<<"\n";
        if(price[i]>max){max=price[i]; cout<<max<<"\n";}
        if(price[i]<max){result+=max-price[i];cout<<price[i]<<"\n";}
    }
    for(int i=0;i<price.size();++i){
        cout<<price[i]<<" ";
    }
    cout<<"\n";
    return result;
}


int main(void){
    int Test;
    cin>>Test;
   
    for(int test=1;test<=Test;++test){
        cout<<"#"<<test<<"\n";
        vector<int> price;
        int n;
        int temp;
        cin>>n;
        for(int i=0;i<n;++i){
           cin>>temp;
           price.push_back(temp);
        }
        cout<<maximumProfit(price)<<"\n";;
    }
    return 0;
}