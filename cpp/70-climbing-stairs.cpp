class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int first = 1, second = 2, curStairs = 0;
        
        for(int i = 2; i < n ; i++) {
            curStairs = first + second;
            first = second;
            second = curStairs;
        }
        
        return curStairs;
    }
};
