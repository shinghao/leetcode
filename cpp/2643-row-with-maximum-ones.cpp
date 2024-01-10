// Time -> O(n * m), space -> O(1)

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findMaxOnesRow(vector<vector<int>>& mat) {
        int maxOnesIdx = 0;
        int maxOnesCount = 0;
        for (int i = 0; i < mat.size(); i++) {
            vector<int> row = mat[i];
            int ones = accumulate(row.begin(), row.end(), 0);
            if (ones > maxOnesCount) {
                maxOnesCount = ones;
                maxOnesIdx = i;
            }
        }
        return {maxOnesIdx, maxOnesCount};
    }
};
