// Time -> O(n), Space -> O(1)
#include<vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, curAltitude = 0;
        for (int i : gain) {
            curAltitude += i;
            maxAltitude = max(maxAltitude, curAltitude);
        }
        return maxAltitude;
    }
};