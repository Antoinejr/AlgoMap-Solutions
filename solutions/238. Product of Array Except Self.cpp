#include <vector>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int N = nums.size();
        std::vector<int> ans(N);
        // left pass through
        int leftProduct = 1;
        for(int i = 0; i < N; i++) {
            if(i > 0) leftProduct *= nums[i-1];
            ans[i] = leftProduct;
        }
        // right pass through
        int rightProduct = 1;
        for(int i = N-1; i >= 0; i--) {
            if(i < N-1) rightProduct *= nums[i+1];
            ans[i] *= rightProduct;
        }

        return ans;

        
    }
};
