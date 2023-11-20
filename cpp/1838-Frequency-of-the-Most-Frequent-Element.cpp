/*
    Time -> O(nlogn) for sorting
    Space -> O(logn) for sorting
    Problem breakdown:
        1) Sort
        2) Use sliding window to find largest window
            - In each operation from 1 -> n:
                - Increase sliding window by 1 from right, check value of k 
                - If k < 0, shrink sliding window by 1 from left, recalculate k
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int result = 1, leftIndx = 0;

        sort(nums.begin(), nums.end());

        for (int rightIndx = 1; rightIndx < nums.size(); rightIndx++) {
            long target = nums[rightIndx];

            int lengthOfWindow = rightIndx - leftIndx;
            int incrementNeeded = target - nums[rightIndx - 1];
            k -= lengthOfWindow * incrementNeeded;

            if (k < 0) {
                k += (target - nums[leftIndx]);
                leftIndx++;
            }
        }

        return nums.size() - leftIndx;
    }

};
