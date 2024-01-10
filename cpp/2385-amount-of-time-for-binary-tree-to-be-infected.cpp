// Time -> O(n), Space -> O(n)

#include <unordered_set>
#include <unordered_map>
#include <queue>
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        convertToGraph(root, -1, graph);
       
        queue<int> q;
        q.push(start);
        int time = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int cur = q.front();
                visited.insert(cur);
                q.pop();
                
                for (int neighbour : graph[cur]) {
                    if (visited.find(neighbour) == visited.end()) {
                        q.push(neighbour);
                    }
                }
            }
            time++;
        }

        return time - 1;
    }
    
private:
    void convertToGraph(TreeNode* cur, int parent, unordered_map<int, vector<int>> &graph) {
        if (!cur) {
            return;
        }
        if (parent != -1) {
            graph[cur->val].push_back(parent);
        }
        if (cur->left) {
            graph[cur->val].push_back(cur->left->val);
        }
        if (cur->right) {
            graph[cur->val].push_back(cur->right->val);
        }
        convertToGraph(cur->left, cur->val, graph);
        convertToGraph(cur->right, cur->val, graph);
    }
};