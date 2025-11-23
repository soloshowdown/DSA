class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<string,int>substring_mp;
        map<char,int>count_mp;
        int ans =0; 
        int left =0;
        int n = s.size();
        for(int right=0; right <n; right++){
            count_mp[s[right]]++;
            if(right - left + 1 > minSize){
                count_mp[s[left]]--;
                if(count_mp[s[left]] == 0){
                    count_mp.erase(s[left]);
                }
                left++;
            }
            if(right - left + 1 == minSize && count_mp.size() <= maxLetters){
                string temp = s.substr(left,minSize);
                substring_mp[temp]++;
                ans = max(ans,substring_mp[temp]);
            }
        }
        return ans; 
    }
};