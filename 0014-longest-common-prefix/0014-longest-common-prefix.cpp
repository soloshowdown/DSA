class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        for (int i = 0; i < strs[0].size(); i++){
            char p = strs[0][i];
            for (string &s : strs){
                if (i >= s.size() || s[i] != p){
                    return prefix;
                }
            }
            prefix += p;
        }
        return prefix;
    }
};