/*
    Time -> O(n), Space -> O(1)
*/

#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int curStep = std::min(a, b) + cost[i];
            a = b;
            b = curStep;
        }
        
        return std::min(a, b);
    }
};