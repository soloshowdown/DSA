class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxXor = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {

                // Check strong pair condition
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    
                    // Update max XOR
                    maxXor = max(maxXor, nums[i] ^ nums[j]);
                }
            }
        }

        return maxXor;
    }
};
