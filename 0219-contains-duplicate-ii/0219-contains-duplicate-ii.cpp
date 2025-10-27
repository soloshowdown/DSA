class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window; // sliding window set

        for (int i = 0; i < nums.size(); i++) {
            // Step 1: Agar element already window me hai -> duplicate mil gaya
            if (window.find(nums[i]) != window.end())
                return true;

            // Step 2: Add current element in window
            window.insert(nums[i]);

            // Step 3: Maintain window size <= k
            if (window.size() > k)
                window.erase(nums[i - k]); // remove leftmost element
        }

        return false; // koi duplicate nahi mila
    }
};
