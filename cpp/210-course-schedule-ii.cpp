// Time -> O(V + E), Space -> O(V + E)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build adj list & populate a list of indegree count
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        for (vector<int> prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        // 2. Traverse indegree list, add source nodes (indegree == 0) to queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }


        // 3. Topological ordering using BFS
        vector<int> result;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result.push_back(cur);

            for (int child : adjList[cur]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};