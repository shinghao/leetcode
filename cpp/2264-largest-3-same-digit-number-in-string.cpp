// Time -> O(n), Space -> O(1)

#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int largestGoodDigit = -1;
        
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                largestGoodDigit = max(largestGoodDigit, num[i] - '0');
            }
        }

        return (largestGoodDigit == -1) ? "" : string(3, largestGoodDigit + '0');
    }
};