class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Convert both to lowercase for comparison
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // not palindrome
            }

            left++;
            right--;
        }

        return true; // all matched
    }
};
