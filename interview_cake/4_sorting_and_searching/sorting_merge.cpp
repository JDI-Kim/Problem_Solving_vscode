/*
   [interview cake] 4. sorting, searching and logarithms.
    sorting + merging
*/
#include <iostream>
#include <vector>
#include <algorithm>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
    bool operator< (const Meeting& other) const{
        return
            startTime_ < other.startTime_;
    }
};

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    // merge meeting ranges
    vector<Meeting> sorted(meetings);
    int sz = sorted.size();
    
    sort(sorted.begin(), sorted.end());
    
    vector<Meeting> merged;
    merged.push_back(sorted[0]);
    
    for(int i = 1 ; i <sz; ++i){
       Meeting& m = merged.back();
       
       if(sorted[i].getStartTime() <= m.getEndTime()){
           m.setEndTime( max(sorted[i].getEndTime(), m.getEndTime()) );
       }
       else
       { merged.push_back(sorted[i]);}
       
    }

    return merged;
}


















// // tests

// const lest::test tests[] = {
//     {CASE("meetings overlap") {
//         const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 4)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("meetings touch") {
//         const auto meetings = vector<Meeting> {Meeting(5, 6), Meeting(6, 8)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(5, 8)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("meeting contains other meeting") {
//         const auto meetings = vector<Meeting> {Meeting(1, 8), Meeting(2, 5)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 8)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("meetings stay separate") {
//         const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("multiple merged meetings") {
//         const auto meetings = vector<Meeting> {Meeting(1, 4), Meeting(2, 5), Meeting(5, 8)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 8)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("meetings not sorted") {
//         const auto meetings = vector<Meeting> {Meeting(5, 8), Meeting(1, 4), Meeting(6, 8)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 4), Meeting(5, 8)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("one long meeting contains smaller meetings") {
//         const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
//             Meeting(9, 10), Meeting(10, 12)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(1, 12)};
//         EXPECT(actual == expected);
//     }},

//     {CASE("sample input") {
//         const auto meetings = vector<Meeting> {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
//             Meeting(10, 12), Meeting(9, 10)};
//         const auto actual = mergeRanges(meetings);
//         const auto expected = vector<Meeting> {Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)};
//         EXPECT(actual == expected);
//     }},
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
// }