class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;   // two pointers
        int leftMax = 0, rightMax = 0; // max so far from both sides
        int water = 0;                 // total trapped water

        while (left < right) {
            // Agar left side chhoti hai
            if (height[left] < height[right]) {
                // Agar current bar chhoti hai leftMax se → water trap hoga
                if (height[left] < leftMax) {
                    water += leftMax - height[left];
                } 
                else {
                    // Naya leftMax set karo
                    leftMax = height[left];
                }
                left++;
            }
            // Agar right side chhoti ya equal hai
            else {
                if (height[right] < rightMax) {
                    water += rightMax - height[right];
                } 
                else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return water;
    }
};
