class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window; // store unique characters in current window
        int left = 0, right = 0;    // window boundaries
        int maxLen = 0;             // stores longest valid substring length
        
        while (right < s.size()) {
            // If current character already in window -> shrink window from left
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            
            // Add current character to window
            window.insert(s[right]);
            
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
            
            // Move right pointer to expand window
            right++;
        }
        
        return maxLen;
    }
};
