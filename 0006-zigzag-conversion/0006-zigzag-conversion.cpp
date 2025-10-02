class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int cur = 0;
        int dir = 1;     // 1 = for down, -1 = for up

        for (int i = 0; i < s.size(); i++) {
            rows[cur] += s[i];
            if (cur == 0) dir = 1;
            else if (cur == numRows - 1) dir = -1;
            cur += dir;
        }

        string ans;
        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }

        return ans;
    }
};