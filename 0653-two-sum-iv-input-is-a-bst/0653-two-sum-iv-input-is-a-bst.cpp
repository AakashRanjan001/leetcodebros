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
    void inorder(TreeNode* root, int k ,vector<int>&nums){
        if(root == NULL)return;

        //lnr
        inorder(root->left,k,nums);
        nums.push_back(root->val);
        inorder(root->right,k,nums);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        inorder(root,k,nums);

        int s =0;
        int e = nums.size()-1;

        while(s<e){
            if(nums[s]+nums[e] == k){
                return true;
            }
            else if(nums[s]+nums[e] > k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};