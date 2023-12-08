// Time -> O(n) where n is number of nodes in tree
// Space -> O(h) where h is height of tree

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string tree2str(TreeNode* root) {
        string result = "";
        dfs(root, result);
        return result.substr(1, result.length() - 2);
    }

    void dfs(TreeNode* root, string &result) {
        if (!root) {
            return;
        }
        result += '(' + to_string(root->val);
        if (root->right && !root->left) {
            result += "()";
        }
        dfs(root->left, result);
        dfs(root->right, result);
        result += ')';
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
