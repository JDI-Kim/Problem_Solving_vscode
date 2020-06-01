/*
    [interview cake] 3. greedy algorithm. apple stock
    * find max Profit
*/
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit
    int sz = stockPrices.size();
    if(sz < 2 ) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }
    
    
    int maxPrice = stockPrices[sz-1];
    int maxProfit = stockPrices[sz-1]-stockPrices[sz-2];
    int tempProfit = 0;
    

    // for(int i=sz-2; i>=0; --i){
    //     tempProfit = maxPrice - stockPrices[i];
    //     if(maxProfit < tempProfit) maxProfit = tempProfit;
        
    //     if(maxPrice < stockPrices[i]) maxPrices = stockPrices[i];
    // }

    int minPrice = stockPrices[0];
        maxProfit = stockPrices[1] - stockPrices[0];
    
    for(int i = 1; i<sz; ++i){
        tempProfit = stockPrices[i] - minPrice;
        maxProfit = max(maxProfit, tempProfit);
        minPrice = min(minPrice, stockPrices[i]);
    }
    return maxProfit;
}


















// tests

// const lest::test tests[] = {
//     {CASE("price goes up then down") {
//         const int actual = getMaxProfit({1, 5, 3, 2});
//         const int expected = 4;
//         EXPECT(actual == expected);
//     }},

//     {CASE("price goes down then up") {
//         const int actual = getMaxProfit({7, 2, 8, 9});
//         const int expected = 7;
//         EXPECT(actual == expected);
//     }},

//     {CASE("price goes up all day") {
//         const int actual = getMaxProfit({1, 6, 7, 9});
//         const int expected = 8;
//         EXPECT(actual == expected);
//     }},

//     {CASE("price goes down all day") {
//         const int actual = getMaxProfit({9, 7, 4, 1});
//         const int expected = -2;
//         EXPECT(actual == expected);
//     }},

//     {CASE("price stays the same all day") {
//         const int actual = getMaxProfit({1, 1, 1, 1});
//         const int expected = 0;
//         EXPECT(actual == expected);
//     }},

//     {CASE("exception with empty prices") {
//         EXPECT_THROWS(getMaxProfit({}));
//     }},

//     {CASE("exception with one price") {
//         EXPECT_THROWS(getMaxProfit({1}));
//     }},
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
// }