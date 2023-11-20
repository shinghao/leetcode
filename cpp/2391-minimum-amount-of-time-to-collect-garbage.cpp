/*
    Time -> O(n * k) where n is number of houses and k is maximum garbage in a house
    Space -> O(1)

    Problem breakdown:
        1) Find total number of garbages in all houses
        2) Find the last house that each truck would stop at to calculate total travel time
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int totalTime = 0;
        bool lastHouse[3] = {false};
        string garbageTypes[3] = {"M", "P", "G"};

        for (int house = garbage.size() - 1; house >= 0; house--) {
            totalTime += garbage[house].length();

            for (int g = 0; g < 3; g++) {
                lastHouse[g] = lastHouse[g] || garbage[house].find(garbageTypes[g]) != -1;

                if (lastHouse[g] && house > 0) {
                    totalTime += travel[house - 1];
                }
            }
        }

        return totalTime;
    }
};