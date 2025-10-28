class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        // Step 1: Calculate initial window sum
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k]; // add next element, remove the leftmost one
            maxSum = max(maxSum, sum);    // update maximum sum
        }

        // Step 3: Divide by k to get average
        return maxSum / k;
    }
};
