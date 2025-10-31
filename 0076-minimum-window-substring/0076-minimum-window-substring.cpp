class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        } 

        vector<int> target(256, 0);
        for (int i = 0; i < t.size(); ++i) {
            target[t[i]] = target[t[i]] + 1;
        }


        int left = 0, right = 0;
        vector<int> recordTimes(256, 0); 
        int remain = t.size();

        string res = "";
        int minLen = s.size() + 1;

        while (right < s.size()) {
            while (remain > 0 && right < s.size()) {
                auto charRight = s[right];
                if (target[charRight] > 0) { 
                    recordTimes[charRight] += 1; 
                    if (recordTimes[charRight] <= target[charRight]) {
                        remain -= 1;
                    }
                    
                    while (target[s[left]] == 0 || 
                        (recordTimes[s[left]]) > target[s[left]]) {
                        if (recordTimes[s[left]] > 0) {
                            recordTimes[s[left]] -= 1; 
                        }
                        ++left;
                    }
                }
                ++right;
            }

            if (remain != 0) {
                break;
            }

            if (right - left < minLen) {
                minLen = right - left;
                res = s.substr(left, minLen);
            }

            while (remain <= 0 && left < right && left < s.size()) {
                auto leftChar = s[left];
                if (target[leftChar] > 0) {
                    recordTimes[leftChar] -= 1;

                    if (recordTimes[leftChar] < target[leftChar]) {
                        ++left;
                        while(left < s.size() && (target[s[left]] == 0 || recordTimes[s[left]] > target[s[left]])) {
                            if (target[s[left]] > 0) {
                                recordTimes[s[left]] -= 1;
                            }
                            ++left;
                        }
                        remain = 1;
                        break;
                    }
                }

                ++left;
            }
        }

        return res;
    }
};