#include <unordered_set>

class Solution {
public:
    int numberOfSubstrings(string s) {
        array<unsigned, 3> counter = {{0, 0, 0}};
        int ans = 0;
        int count = 0;
        int left = 0, right = 0;
        while (left <= s.size() - 3) {
            while (count < 3 && right < s.size()) {
                if (counter[s[right] - 'a'] == 0) {
                    ++count;
                }
                ++counter[s[right++] - 'a'];
            }
            if (count == 3) {
                ans += (s.size() - right + 1);
            } else {
                break;
            }
            if (counter[s[left] - 'a'] == 1) {
                --count;
            }
            --counter[s[left++] - 'a'];
        }
        return ans;
    }
};