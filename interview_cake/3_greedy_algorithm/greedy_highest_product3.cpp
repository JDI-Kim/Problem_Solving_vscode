#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

int highestProductOf3(const vector<int>& vectorOfInts)
{
    // calculate the highest product of three numbers
    int sz = vectorOfInts.size();

    if(sz<3){
        throw invalid_argument("Getting a highest product of 3 requires at least three items");
    }
    if(sz==3) return vectorOfInts[0]*vectorOfInts[1]*vectorOfInts[2];

    int maxInt[3];
    int negativeInt[2]={0,};
    int numNegative = 0;
    int numPositive = 0;
    
    maxInt[0] = max(max(vectorOfInts[0],vectorOfInts[1]), vectorOfInts[2]);
    maxInt[2] = min(min(vectorOfInts[0],vectorOfInts[1]), vectorOfInts[2]);
    maxInt[1] = vectorOfInts[0] + vectorOfInts[1] + vectorOfInts[2] - maxInt[0] - maxInt[2];
    
    for(int i=0;i<3;++i){
        int num = vectorOfInts[i];
        if(num < 0) numNegative++;
        if(num > 0) numPositive++;
        
        if( num <= negativeInt[0]) {
            negativeInt[1] = negativeInt[0];
            negativeInt[0] = num;
        }else if ( num < negativeInt[1]){
            negativeInt[1] = num;
        }
        
    }
    
    
    for(int i=3; i<sz; ++i){
        int num = vectorOfInts[i];
        
        if(num < 0) numNegative++;
        if(num > 0) numPositive++;
        
        if( num <= negativeInt[0]){
            negativeInt[1] = negativeInt[0];
            negativeInt[0] = num;
        }else if( num < negativeInt[1]){
            negativeInt[1] = num;
        }
        
        if( num <= maxInt[2]) continue;
        
        if(maxInt[0] <= num ){ 
            maxInt[2] = maxInt[1];
            maxInt[1] = maxInt[0];  
            maxInt[0] = num;
            continue;
        }
        if(maxInt[1] <= num){
            maxInt[2] = maxInt[1];
            maxInt[1] = num;
            continue;
            
        }
        if(maxInt[2] <= num){
            maxInt[2] = num;
            continue;
        }
    }
    
    int result  = maxInt[0] * maxInt[1] * maxInt[2];
    
    if(numPositive > 0 && numNegative > 1){
        result = max(result, maxInt[0]*negativeInt[0]*negativeInt[1]);
    }
    
    

    return result;
}


















// tests

const lest::test tests[] = {
    {CASE("short vector") {
        const int actual = highestProductOf3({1, 2, 3, 4});
        const int expected = 24;
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const int actual = highestProductOf3({6, 1, 3, 5, 7, 8, 2});
        const int expected = 336;
        EXPECT(actual == expected);
    }},

    {CASE("vector has one negative") {
        const int actual = highestProductOf3({-5, 4, 8, 2, 3});
        const int expected = 96;
        EXPECT(actual == expected);
    }},

    {CASE("vector has two negatives") {
        const int actual = highestProductOf3({-10, 1, 3, 2, -10});
        const int expected = 300;
        EXPECT(actual == expected);
    }},

    {CASE("vector is all negatives") {
        const int actual = highestProductOf3({-5, -1, -3, -2});
        const int expected = -6;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty vector") {
        EXPECT_THROWS(highestProductOf3({}));
    }},

    {CASE("exception with one number") {
        EXPECT_THROWS(highestProductOf3({1}));
    }},

    {CASE("exception with two numbers") {
        EXPECT_THROWS(highestProductOf3({1, 1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}