// Time -> O(N + K), where N is number of words and K is number of unique characters
// Space -> O(N + K)

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  string findOrder(const vector<string> &words) {
    unordered_map<char, int> indegree;
    unordered_map<char, vector<char>> adjList;

    for (string word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    for (int i = 1; i < words.size(); i++) {
        string w1 = words[i - 1], w2 = words[i];
        for (int j = 0; j < min(w1.size(), w2.size()); j++) {
            char parent = w1[j];
            char child = w2[j];
            if (parent != child) {
            adjList[parent].push_back(child);
            indegree[child]++;
            break;
            }
        }
    }

    queue<char> q;
    for (auto &c : indegree) {
        if (c.second == 0) {
            q.push(c.first);
        }
    }

    string order = "";
    while (!q.empty()) {
        char cur = q.front();
        q.pop();
        order += cur;

        for (char child : adjList[cur]) {
            indegree[child]--;
            if (indegree[child] == 0) {
            q.push(child);
            }
        }
    }

    return (order.size() == indegree.size()) ? order : "";
  }
};
