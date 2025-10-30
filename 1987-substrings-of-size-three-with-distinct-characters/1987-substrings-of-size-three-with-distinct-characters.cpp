class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) { // n-2 tak hi jana hai, warna 3 char nahi milenge
            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];

            if (a != b && b != c && a != c) {
                count++;
            }
        }

        return count;
    }
};
