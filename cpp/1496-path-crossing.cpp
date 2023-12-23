// Time -> O(n), Space -> O(n)

#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> dir;
        dir['N'] = {0, 1};
        dir['S'] = {0, -1};
        dir['E'] = {1, 0};
        dir['W'] = {-1, 0};

        unordered_set<string> visited = {"0-0"};
        int x = 0, y = 0;

        for (char p : path) {
            x += dir[p].first, y += dir[p].second;
            string hashedCurPos = to_string(x) + '-' + to_string(y); 
            if (visited.find(hashedCurPos) != visited.end()) {
                return true;
            }
            visited.insert(hashedCurPos);
        }

        return false;
    }
};