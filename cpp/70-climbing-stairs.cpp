/*
    Time -> O(n), Space -> O(1)
    
    dp[n] = dp[n - 1] + dp[n - 2]
    Reach n step in 2 ways: 
        1) 1 step from n-1, 
        2) 2 steps from n-2
*/

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
