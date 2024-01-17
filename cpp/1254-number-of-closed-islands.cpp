// Time -> O(row * col), Space -> O(row * col)

#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int countClosedIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0 && isClosedIsland(grid, i, j)) {
                    countClosedIslands++;
                }
            }
        }
        return countClosedIslands;
    }

private:
    bool isClosedIsland(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[i].size()) {
            return false;
        }
        if (grid[i][j] != 0) {
            return true;
        }

        grid[i][j] = 2;

        bool isConnected = true;
        isConnected &= isClosedIsland(grid, i + 1, j);
        isConnected &= isClosedIsland(grid, i - 1, j);
        isConnected &= isClosedIsland(grid, i, j + 1);
        isConnected &= isClosedIsland(grid, i, j - 1);
        return isConnected;
    }
};