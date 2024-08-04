#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0], count = 1;
        for(const int& i : nums) {
            if(value != i) count--;
            else count++;
            
            if(count == 0) {
                value = i;
                count = 1;
            }
        }

        return value;
    }
};