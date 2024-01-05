// Time -> O(i * j), where i is number of customers and j is number of banks
// Space -> O(1)

#include<vector>
#include <numeric>
using namespace std;

class Solution {
public:
    static int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (vector<int> account : accounts) {
            int wealth = accumulate(account.begin(), account.end(), 0);
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
