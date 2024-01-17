// Time -> O(V + E), Space -> O(V + E)
// Main idea -> Check if cycle exist = topological ordering not possible = impossible to take all courses

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build adj list & populate a list of indegree count
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        for (vector<int> prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }

        // 2. Traverse indegree list, add source nodes (indegree == 0) to queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }


        // 3. Topological ordering using BFS
        int sortedNodes = 0; // Nodes that we have topologically sorted
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            sortedNodes++;

            for (int child : adjList[cur]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        // Return true if topological ordering possible
        return sortedNodes == numCourses;
    }
};