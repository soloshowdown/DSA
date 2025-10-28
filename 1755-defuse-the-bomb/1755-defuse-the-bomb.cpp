class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) return result;

        int start, end, sum = 0;

        // For positive k → window on next k elements
        if (k > 0) {
            start = 1;
            end = k;
        }
        // For negative k → window on previous k elements
        else {
            start = n + k;
            end = n - 1;
            k = -k;  // Make k positive for loop count
        }

        // Step 1: Initial window sum
        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }

        // Step 2: Slide the window
        for (int i = 0; i < n; i++) {
            result[i] = sum;
            sum -= code[start % n];       // remove element going out
            start++;
            end++;
            sum += code[end % n];         // add element coming in
        }

        return result;
    }
};
