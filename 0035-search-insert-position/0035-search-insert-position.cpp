class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // overflow safe

            if (nums[mid] == target) return mid;   // target found
            else if (nums[mid] < target) left = mid + 1;  // target is on right
            else right = mid - 1;  // target is on left
        }

        // left is the insert position if target not found
        return left;
    }
};
