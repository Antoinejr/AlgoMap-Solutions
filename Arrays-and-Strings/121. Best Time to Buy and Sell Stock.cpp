#include <vector>

class Solution {
public:
    /**
    * straight forward approaching using two pointers, buy and sell, to keep track of best day
    * to buy stock and sell stock
    */
    // int maxProfit(vector<int>& prices) {
    //     int res = 0, b = 0, s = 1, N = prices.size();

    //     while (s < N) {
    //         if (prices[b] >= prices[s]) {
    //             b = s;
    //         }else {
    //             res = std::max(res,prices[s] - prices[b]);
    //         }
    //         s++;
    //     }
    //     return res;
    // }

    /**
    * Solution using Kadane's algorithm 
    * Link Explanation : https://geeksforgeeks.org/largest-sum-contiguous-subarray/
    * Find Subarray with max Sum
    */
    int maxProfit(std::vector<int>& prices) {
        // {-6, 4, -2, 3, -2}
        int currMax = 0, globalMax = 0, N = prices.size();

        for(int i = 1; i < N; i++) {
            currMax = std::max(0, currMax + (prices[i] - prices[i-1]));
            globalMax = std::max(globalMax, currMax);
        }
        return globalMax;
    }
};