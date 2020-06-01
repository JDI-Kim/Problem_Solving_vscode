/*
   [interview cake] 3. greedy algorithm. product of all ints except me.
    * use greedy approach twice
    : Start with a brute force solution, look for repeat work in that solution, and modify it to only do that work once.
*/
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    // make a vector with the products
    int sz = intVector.size();
    if(sz<2){
        throw invalid_argument("No");
    }
    
    int productBefore = 1;
    int productAfter = 1;
    
    vector<int> result(sz);
    
    for(int i=0; i<sz; ++i){
        result[i] = productBefore;    
        productBefore *=intVector[i];
    }
    
    for(int i=sz-1 ; i>=0 ; --i){
        result[i] *=productAfter;
        productAfter *= intVector[i];
    }

    return result;
}


















// tests

// const lest::test tests[] = {
//     {CASE("small vector") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
//         const auto expected = vector<int> {6, 3, 2};
//         EXPECT(actual == expected);
//     }},

//     {CASE("longer vector") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
//         const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
//         EXPECT(actual == expected);
//     }},

//     {CASE("vector has one zero") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
//         const auto expected = vector<int> {0, 0, 36, 0};
//         EXPECT(actual == expected);
//     }},

//     {CASE("vector has two zeros") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
//         const auto expected = vector<int> {0, 0, 0, 0, 0};
//         EXPECT(actual == expected);
//     }},

//     {CASE("one negative number") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
//         const auto expected = vector<int> {32, -12, -24};
//         EXPECT(actual == expected);
//     }},

//     {CASE("all negative numbers") {
//         const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
//         const auto expected = vector<int> {-8, -56, -14, -28};
//         EXPECT(actual == expected);
//     }},

//     {CASE("error with empty vector") {
//         EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
//     }},

//     {CASE("error with one number") {
//         EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
//     }},
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
// }