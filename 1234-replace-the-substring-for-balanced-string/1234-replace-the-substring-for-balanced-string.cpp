class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), target = n / 4;
        unordered_map<char, int> freq;
        for (char c : s) ++freq[c];

        // Already balanced
        if (freq['Q'] <= target && freq['W'] <= target &&
            freq['E'] <= target && freq['R'] <= target) return 0;

        int res = n, l = 0;
        for (int r = 0; r < n; ++r) {
            --freq[s[r]];  // remove from "outside"
            while (l <= r &&
                   freq['Q'] <= target &&
                   freq['W'] <= target &&
                   freq['E'] <= target &&
                   freq['R'] <= target) {
                res = min(res, r - l + 1);
                ++freq[s[l]];  // restore left
                ++l;
            }
        }
        return res;
    }
};