class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        int n = s.length();

        int count = 0;

        int left = 0;

        vector<int> a(2,0);

        for(int right = 0;right<n;right++){

            a[s[right]-'0']++;

            while(a[0]>k && a[1]>k){
                a[s[left]-'0']--;
                left++;
            }
            count+= right-left+1;

        }

        return count;


    }
};