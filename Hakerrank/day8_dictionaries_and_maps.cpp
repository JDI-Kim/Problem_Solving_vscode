/*
    How to use map
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */      int n;
    string name, phone;
    map<string,string> m;
    map<string,string>::iterator it;

    cin>>n;
    
    for(int i=0; i<n; ++i){
        cin>>name>>phone;
        m[name]=phone;
    }
    
    while(cin>>name){
        it = m.find(name);
        if(it == m.end()){
            cout<<"Not found\n";
        }else{
            phone=it->second;
            cout<<name<<"="<<phone<<"\n";
        }
        cout<<m[name]<<"\n";
    }


    return 0;
}
