/*
    [interview cake] 2. hash table. inflight entertainment system.
    * unordered_set
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    // # mysolution
    int sz = movieLengths.size();
    unordered_multimap<int,int> movieSet;

    for(int i=0; i<sz; ++i){
        movieSet.insert(make_pair(movieLengths[i], i));
    }
    
    int m1,m2;
    for(int i=0; i<sz; ++i){
        m1 = movieLengths[i];
        m2 = flightLength - m1;
        if(movieSet.find(m2) == movieSet.end()) continue;
        if(m1==m2 && movieSet.count(m1)==1) continue;
        return true;
    }
    
    // # interview cake solution
    // this is better. 본 영화에 넣기 전에 비교하기 때문에 같은 영화를 두번 보는 것을 막을 수 있음.
    unordered_set<int> movieLengthsSeen;

    for (int firstMovieLength : movieLengths) {
        int matchingSecondMovieLength = flightLength - firstMovieLength;
        if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
            return true;
        }
        movieLengthsSeen.insert(firstMovieLength);
    }
    return false;
}


















// tests

const lest::test tests[] = {
    {CASE("short flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 1) == false);
    }},
    {CASE("long flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("only one movie half flight length") {
        const vector<int> movieLengths {3, 8};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("two movies half flight length") {
        const vector<int> movieLengths {3, 8, 3};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("lots of possible pairs") {
        const vector<int> movieLengths {1, 2, 3, 4, 5, 6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 7) == true);
    }},
    {CASE("not using first movie") {
        const vector<int> movieLengths {4, 3, 2};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 5) == true);
    }},
    {CASE("only one movie") {
        const vector<int> movieLengths {6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("no movies") {
        const vector<int> movieLengths;
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}