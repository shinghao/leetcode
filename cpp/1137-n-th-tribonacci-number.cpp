// Time -> O(n), Space -> O(1)

class Solution {
public:
    int tribonacci(int n) {
        int t1 = 0, t2 = 1, t3 = 1, cur = 0;
        
        if (n == 1 || n == 2) {
            return 1;
        }

        for (int i = 3; i <= n; i++) {
            cur = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = cur;
        }

        return cur;
    }
};