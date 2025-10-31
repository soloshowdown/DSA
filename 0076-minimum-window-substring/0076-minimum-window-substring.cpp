class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        unordered_map<char, int> window;
        int have = 0, required = freq.size();
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (freq.count(c) && window[c] == freq[c])
                have++;

            while (have == required) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Shrink window
                window[s[left]]--;
                if (freq.count(s[left]) && window[s[left]] < freq[s[left]])
                    have--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
