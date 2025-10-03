class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;

        int start = nums[0]; // current range start

        for(int i = 0; i < nums.size(); i++) {
            // Check agar next element consecutive nahi hai
            if(i == nums.size()-1 || nums[i] + 1 != nums[i+1]) {
                if(start == nums[i]) {
                    // single element hai
                    ans.push_back(to_string(start));
                } else {
                    // range hai start -> nums[i]
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                if(i != nums.size()-1) {
                    start = nums[i+1]; // new range start
                }
            }
        }
        return ans;
    }
};
