class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly k odds = at most k - at most (k-1)
        return func(nums, k) - func(nums, k - 1);
    }

    // Counts subarrays with at most 'goal' odd numbers
    int func(vector<int>& nums, int goal) {
        if(goal < 0) return 0;  
        int left = 0, right = 0, sum = 0, count = 0;

        while(right < nums.size()) {
            sum += (nums[right] % 2);  // Count odd numbers

            // Shrink window if too many odds
            while(sum > goal) {
                sum -= (nums[left] % 2);
                left++;
            }

            // All subarrays ending at right are valid
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};