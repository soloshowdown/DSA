class Solution {
public:
   int lengthOfLongestSubstring(string s) {
       vector<bool> a(95, false);
       int ans = 0, l = 0, r = 0;
       
       while (r < s.size()) {
           if ( !a[ s[r] - 32 ] ) {
               ans = max(ans, r - l + 1);
               a[ s[r++] - 32 ] = true;
           }
           else a[ s[l++] - 32 ] = false;
       }

       return ans;
   }
};