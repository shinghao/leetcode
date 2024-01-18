// Time -> O(C^(t/m)), where C = number of canidates, t = target, m = min canidate
// Space -> t/m

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        backtrack(candidates, target, result, {}, 0);
        return result;
    }

    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> cur, int i) {
        if(target == 0) {
            result.push_back(cur);
        }
        if(target <= 0) {
            return;
        }
        for(; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, cur, i);
            cur.pop_back();
        }
    }
};