// Time -> O(c + w), where c is length of chars and w is total characters is words
// Space -> O(1), since we only need fixed array of size 26

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charsCount[26] = {0};
        for (char c : chars) {
            charsCount[c - 'a']++;
        }

        int result = 0;
        for (string word : words) {
            int wordCount[26] = {0};
            result += word.size();
            for (char c : word) {
                wordCount[c - 'a']++;
                if (wordCount[c - 'a'] > charsCount[c - 'a']) {
                    result -= word.size();
                    break;
                }
            }
        }

        return result;
    }
};