// Time -> O(nlogn), Space -> O(logn) for sorting

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int coins = 0;
        int n = piles.size() / 3;
        sort(piles.begin(), piles.end());

        for(int i = piles.size() - 2; i >= n; i-=2) {
            coins += piles[i];
        }

        return coins;
    }
};