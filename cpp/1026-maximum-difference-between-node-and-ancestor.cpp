// Time -> O(n), Space -> O(h), where h is height of tree

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        dfs(root, INT_MIN, INT_MAX, maxDiff);

        return maxDiff;
    }

private:
    void dfs(TreeNode* root, int maxNum, int minNum, int &maxDiff) {
        if (!root) {
            return;
        }
        
        maxNum = max(maxNum, root->val);
        minNum = min(minNum, root->val);
        maxDiff = max(maxDiff, maxNum - minNum);

        dfs(root->left, maxNum, minNum, maxDiff);
        dfs(root->right, maxNum, minNum, maxDiff);
    }
};