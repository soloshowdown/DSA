#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, required = need.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            // Check if we satisfied one character requirement
            if (need.count(c) && window[c] == need[c])
                have++;

            // When all chars are satisfied, try to shrink window
            while (have == required) {
                // Update minimum window
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Try to shrink from the left
                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    have--;
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};