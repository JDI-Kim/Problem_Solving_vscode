/*
    [Hackerrank] day 17.  More Exceptions. How to make my own exception class. and exceptional messages.

*/
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class myException: public exception{
    virtual const char* what() const throw()
  {
    return "n and p should be non-negative";
  }
}myex;

class Calculator{
public:
    int power(int n, int p){
        if(n<0 || p<0) throw myex;
        return pow(n,p);
    }
};
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}