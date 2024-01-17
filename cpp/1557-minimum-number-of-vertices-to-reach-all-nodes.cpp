// Time -> O(n), Space -> O(n)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n);
        for (vector<int> edge : edges) {
            indegree[edge[1]] = true;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};