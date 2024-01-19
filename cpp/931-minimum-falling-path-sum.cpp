// Time -> O(m * n)
// Space -> O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = matrix.size() - 2; i >= 0; i--) {
            for (int j = matrix[i].size() - 1; j >= 0; j--) {
                int minSum = matrix[i + 1][j];
                if (j - 1 >= 0) {
                    minSum = min(minSum, matrix[i + 1][j - 1]);
                }
                if (j + 1 < matrix[i].size()) {
                    minSum = min(minSum, matrix[i + 1][j + 1]);
                }
                matrix[i][j] += minSum;
            }
        }

        int minSum = matrix[0][0];
        for (int c = 1; c < matrix[0].size(); c++) {
            minSum = min(matrix[0][c], minSum);
        }

        return minSum;
    }
};