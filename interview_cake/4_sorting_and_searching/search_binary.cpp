/*
    [interview cake] 4. sorting, searching and logarithms. find rotating point of vector.
    * if array is sorted, or almoset sorted, binary search is useful
*/
#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

size_t findRotationPoint(const vector<string>& words)
{
    // find the rotation point in the array
    int startI = 0;
    int endI = words.size() - 1;
    int curI;
    
    while(startI < endI){
        curI = (startI + endI)/2;
        
        if(words[curI] < words[0]) { endI = curI; }
        else startI = curI ;
        
        if(startI + 1 == endI){
            break;
        }
    }
    
    return endI;
}


















// tests

// const lest::test tests[] = {
//     {CASE("small array") {
//         const vector<string> words {"cape", "cake"};
//         const size_t actual = findRotationPoint(words);
//         const size_t expected = 1;
//         EXPECT(actual == expected);
//     }},
//     {CASE("medium array") {
//         const vector<string> words {"grape", "orange", "plum", "radish", "apple"};
//         const size_t actual = findRotationPoint(words);
//         const size_t expected = 4;
//         EXPECT(actual == expected);
//     }},
//     {CASE("large array") {
//         const vector<string> words {"ptolemaic", "retrograde", "supplant", "undulate",
//             "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
//             "othellolagkage"};
//         const size_t actual = findRotationPoint(words);
//         const size_t expected = 5;
//         EXPECT(actual == expected);
//     }},
//     {CASE("possibly missing edge case") {
//         // are we missing any edge cases?

//     }}
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
// }