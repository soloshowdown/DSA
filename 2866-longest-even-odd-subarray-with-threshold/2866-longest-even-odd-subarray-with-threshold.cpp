class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        int currLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                currLen = 1;

                // Check alternation from next elements
                int j = i + 1;
                while (j < nums.size() && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                    currLen++;
                    j++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};
