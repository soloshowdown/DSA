class Solution {
public:
    int romanToInt(string s) {
        // Map for Roman numerals
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = s.size();
        int total = 0;
        
        for(int i = 0; i < n; i++) {
            // Agar current character ki value agle se chhoti hai → subtract
            if(i+1 < n && mp[s[i]] < mp[s[i+1]]) {
                total -= mp[s[i]];
            }
            else {
                total += mp[s[i]];
            }
        }
        
        return total;
    }
};
