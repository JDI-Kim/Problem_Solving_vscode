/*
    [interview cake] 2. hash table. palindrome.
    * bruth force 방식보다 unordered_set 사용할 수 있는지 가장 먼저 체크하라
*/
#include <iostream>
#include <string>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome

    // # my solution
    {
        int count[26] = {0,};
        int countOdd = 0;

        bool isEven = true;
        if(str.size() % 2 == 1) isEven =false;
        
        for(char s:str){
            count[s - 'a']++;
        }
        
        int leftover;
        for(int i=0; i<26; ++i){
            leftover = count[i] % 2;
            if(leftover==0) continue;
            if(isEven) return false;
            if(countOdd > 1) return false;
            countOdd++;
            
        }
    }
    // # my solution 2
    {
        int count[26] = {0,};
        for(char s:str){
            int idx= s - 'a';
            if(count[idx]==1) count[idx]--;
            else count[idx]++;
        }
        
        bool existOdd=false;
        for(int i=0;i<26;++i){
            if(count[i]==0) continue;
            if(existOdd) return false;
            existOdd=true;
        }
    }




    // # interview cake solution

    unordered_set<char> countC;
    
    for(char c: str){
        if(countC.find(c) != countC.end()){
            countC.erase(c);
            continue;
        }
        countC.insert(c);
    }
    
    if(countC.size() > 1) return false;
    
    return true;
}


















// tests

const lest::test tests[] = {
    {CASE("permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcbcd");
        EXPECT(result == true);
    }},
    {CASE("permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabccbdd");
        EXPECT(result == true);
    }},
    {CASE("no permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcd");
        EXPECT(result == false);
    }},
    {CASE("no permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabbcd");
        EXPECT(result == false);
    }},
    {CASE("empty string") {
        const auto result = hasPalindromePermutation("");
        EXPECT(result == true);
    }},
    {CASE("one character string") {
        const auto result = hasPalindromePermutation("a");
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}