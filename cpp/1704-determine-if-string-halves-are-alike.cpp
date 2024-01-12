// Time -> O(n), Space -> O(1)

#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int vowelCount = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (vowel.find(s[i]) != vowel.end()) {
                vowelCount++;
            }
        }

        for (int i = s.size() / 2; i < s.size(); i++) {
            if (vowel.find(s[i]) != vowel.end()) {
                vowelCount--;
            }
        }

        return vowelCount == 0;
    }
};