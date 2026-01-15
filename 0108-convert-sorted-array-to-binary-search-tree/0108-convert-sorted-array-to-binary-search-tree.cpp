/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // unordered_map<int,int> mp;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=new TreeNode(0);
        
        // for(int i=0;i<n;i++) mp[nums[i]]=i;
        return f(root, nums, 0, n-1);
    }
    TreeNode* f(TreeNode* root, vector<int>& nums, int aS, int aE){
        if(aS>aE) return NULL;

        int mid=(aS+aE)/2;
        int ele=nums[mid];
        // int i=mp[ele];

        root=new TreeNode(ele);
        root->left = f(root, nums, aS, mid-1);
        root->right= f(root, nums, mid+1, aE);

        return root;
    }
};