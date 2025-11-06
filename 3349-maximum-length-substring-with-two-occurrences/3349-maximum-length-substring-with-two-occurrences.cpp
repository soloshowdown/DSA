class Solution {
public:
int maximumLengthSubstring(string s) {
        // Frequency array to track how many times each lowercase letter appears
        // 'a' to 'z' → 26 letters → indices 0–25
        vector<int> seen(26);
        int left = 0, result = 0;

        // Expand the window by moving the right pointer
        for (int right = 0; right < s.length(); right++) {
            // Map character to index using ASCII modulo
            int idx = int(s[right]) % 97;
            seen[idx]++;

            while (seen[idx] > 2) {
                seen[int(s[left]) % 97]--;
                left++;
            }

            // Update the maximum valid window length
            result = max(result, right - left + 1);
        }

        return result;
    }
};