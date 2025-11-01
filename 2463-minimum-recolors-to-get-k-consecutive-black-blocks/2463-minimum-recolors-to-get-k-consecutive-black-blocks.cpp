class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        int minOperations = INT_MAX;

        // Step 1: First window (size k)
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                whiteCount++;
        }

        minOperations = whiteCount;

        // Step 2: Slide the window
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') whiteCount++;        // Add new entering block
            if (blocks[i - k] == 'W') whiteCount--;    // Remove exiting block

            minOperations = min(minOperations, whiteCount);
        }

        return minOperations;
    }
};
