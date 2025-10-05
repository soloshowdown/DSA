class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;                  // Pointer from start
        int right = numbers.size() - 1; // Pointer from end
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                // +1 because the array is 1-indexed in the problem statement
                return {left + 1, right + 1};
            } 
            else if (sum < target) {
                left++;  // Need a bigger sum → move left forward
            } 
            else {
                right--; // Need a smaller sum → move right backward
            }
        }
        return {}; // If no pair found (though problem guarantees one solution)
    }
};
