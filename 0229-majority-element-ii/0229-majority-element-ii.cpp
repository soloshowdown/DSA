class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return {};
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0; cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            if (num == el2) cnt2++;
        }

        vector<int> ls;
        int mini = nums.size() / 3;
        if (cnt1 > mini) ls.push_back(el1);               // use > (strict)
        if (cnt2 > mini && el2 != el1) ls.push_back(el2); // avoid duplicate

        sort(ls.begin(), ls.end());
        return ls;
    }
};