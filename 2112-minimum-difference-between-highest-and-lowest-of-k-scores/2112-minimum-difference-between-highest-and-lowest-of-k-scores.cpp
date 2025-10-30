class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; // Only one student -> difference 0
        
        sort(nums.begin(), nums.end()); // Step 1: Sort the scores
        
        int minDiff = INT_MAX;

        // Step 2: Use sliding window of size k
        for (int i = 0; i <= nums.size() - k; i++) {
            int diff = nums[i + k - 1] - nums[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};
