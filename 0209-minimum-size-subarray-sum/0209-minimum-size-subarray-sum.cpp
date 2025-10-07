class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;              // window start
        int sum = 0;               // current window sum
        int minLen = INT_MAX;      // answer

        for (int right = 0; right < n; right++) {
            sum += nums[right];    // expand window by adding right element

            // shrink window from left while sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);  // update smallest window
                sum -= nums[left];   // remove leftmost element
                left++;              // shrink window
            }
        }

        // if no valid subarray found
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
