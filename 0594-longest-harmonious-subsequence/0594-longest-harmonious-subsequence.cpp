class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;

        // Step 2: Check each number if (num + 1) exists
        for (auto& pair : freq) {
            int num = pair.first;
            if (freq.find(num + 1) != freq.end()) {
                maxLen = max(maxLen, pair.second + freq[num + 1]);
            }
        }

        return maxLen;
    }
};
