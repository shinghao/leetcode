#include<vector>
using namespace std;

/*
    1. Space Optimisation
    Time -> O(n), Space -> O(1)
*/
class Solution1 {
public:
    int fib(int n) {
        int a = 0, b = 1;

        for (int i = 1; i < n + 1; i++) {
            int nextNum = a + b;
            a = b;
            b = nextNum;
        }
        
        return a;
    }
};

/*
    2. Tabulation - Bottom Up Iteratively
    Time -> O(n), Space -> O(n)
*/
class Solution2 {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> memo(n + 1);
        memo[0] = 0; 
        memo[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        
        return memo[n];
    }
};

/*
    3. Memoization - Top Down Recursively
    Time -> O(n), Space -> O(n)
*/
class Solution3 {
public:
    int fib(int n) {
        vector<int> memo(n + 1, 0);
        return dp(n, memo);
    }
private:
    int dp(int n, vector<int> &memo) {
        if (n <= 1) {
            return n;
        }
        if (!memo[n]) {
            memo[n] = dp(n - 1, memo) + dp(n - 2, memo);
        }
        return memo[n];
    }
};
