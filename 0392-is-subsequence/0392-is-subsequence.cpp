class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; // move in s if match found
            }
            j++; // always move in t
        }

        return i == s.size(); // if all chars of s matched in t
    }
};
