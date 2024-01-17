// Time -> O(row * col), Space -> O(row * col)

#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, markIslands(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int markIslands(vector<vector<int>> &grid, int row, int col) {
        if(row == grid.size() || row < 0 || col == grid[0].size() || col < 0 || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        return 1 + markIslands(grid, row+1, col) 
                + markIslands(grid, row-1, col) 
                + markIslands(grid, row, col+1) 
                + markIslands(grid, row, col-1);
    }
};