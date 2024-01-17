// Time -> O(n^2), Space -> O(n)

#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0, n = isConnected.size();
        vector<bool> visited(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                markVisitedDfs(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }

private:
    void markVisitedDfs(vector<vector<int>>& isConnected, vector<bool> &visited, int cur) {
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[cur][i] == 1 && !visited[i]) {
                visited[i] = true;
                markVisitedDfs(isConnected, visited, i);
            }
        }
      }
};