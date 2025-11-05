class Solution {
public:
    int longestAlternatingSubarray(const vector<int>& nums, int threshold) const {
        size_t longest = 0;
        int parity = 0;

        for (size_t i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] <= threshold) {
                if ((nums[j] % 2) == parity) {
                    longest = max(longest, j + 1 - i);
                    parity ^= 1;
                } else {
                    i = j + (nums[j] % 2);
                }
            } else {
                i = j + 1;
                parity = 0;
            }
        }

        return static_cast<int>(longest);
    }
};
