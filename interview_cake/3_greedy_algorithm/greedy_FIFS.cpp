/*
    [interview cake] 3. greedy algorithm. 
*/
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    // check if we're serving orders first-come, first-served
    int sz = servedOrders.size();
    int szT = takeOutOrders.size();
    int szD = dineInOrders.size();
    
    int tI = 0;
    int dI = 0;
    
    for(int i=0; i<sz; ++i){
        int o = servedOrders[i];
        
        if(tI<szT && o == takeOutOrders[tI]){
            tI++;
            continue;
        }
        if(dI<szD &&  o == dineInOrders[dI]){
            dI++;
            continue;
        }
        return false;
    }
    if(tI!=szT || dI !=szD) return false;
    
    return true;
}


















// // tests

// const lest::test tests[] = {
//     {CASE("both registers have same number of orders") {
//         const vector<int> takeOutOrders {1, 4, 5};
//         const vector<int> dineInOrders {2, 3, 6};
//         const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == true);
//     }},
//     {CASE("registers have different lengths") {
//         const vector<int> takeOutOrders {1, 5};
//         const vector<int> dineInOrders {2, 3, 6};
//         const vector<int> servedOrders {1, 2, 6, 3, 5};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == false);
//     }},
//     {CASE("one register is empty") {
//         const vector<int> takeOutOrders;
//         const vector<int> dineInOrders {2, 3, 6};
//         const vector<int> servedOrders {2, 3, 6};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == true);
//     }},
//     {CASE("served orders is missing orders") {
//         const vector<int> takeOutOrders {1, 5};
//         const vector<int> dineInOrders {2, 3, 6};
//         const vector<int> servedOrders {1, 6, 3, 5};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == false);
//     }},
//     {CASE("served orders has extra orders") {
//         const vector<int> takeOutOrders {1, 5};
//         const vector<int> dineInOrders {2, 3, 6};
//         const vector<int> servedOrders {1, 2, 3, 5, 6, 8};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == false);
//     }},
//     {CASE("one register has extra orders") {
//         const vector<int> takeOutOrders {1, 9};
//         const vector<int> dineInOrders {7, 8};
//         const vector<int> servedOrders {1, 7, 8};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == false);
//     }},
//     {CASE("one register has unserved orders") {
//         const vector<int> takeOutOrders {55, 9};
//         const vector<int> dineInOrders {7, 8};
//         const vector<int> servedOrders {1, 7, 8, 9};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == false);
//     }},
//     {CASE("order numbers are not sequential") {
//         const vector<int> takeOutOrders = {27, 12, 18};
//         const vector<int> dineInOrders = {55, 31, 8};
//         const vector<int> servedOrders = {55, 31, 8, 27, 12, 18};
//         const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
//         EXPECT(result == true);
//     }}
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
}