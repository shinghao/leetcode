/*
    Time -> O(m * n), Space -> O(n)
    
    Only need to store 1 row as for each update, only need 
    the left cell (curRow[c - 1]) & the cell above (curRow[c] before update)
*/

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> curRow(n, 1);

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                curRow[c] = curRow[c] + curRow[c - 1];
            }
        }

        return curRow.back();
    }
};