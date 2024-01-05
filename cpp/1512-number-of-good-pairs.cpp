// Time -> O(n), Space -> O(n)

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairCount = 0;
        unordered_map<int, int> count;
        for (int i : nums) {
            count[i]++;
            pairCount += count[i] - 1; 
        }
        return pairCount;
    }
};