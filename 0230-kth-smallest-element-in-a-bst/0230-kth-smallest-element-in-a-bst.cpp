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
    void inorder(TreeNode* root , int k , vector<int>&nums){
        if(root == NULL)return;

        //LNR
        inorder(root->left, k ,nums);
        nums.push_back(root->val);
        inorder(root->right,k,nums);


    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nums;
        inorder(root,k ,nums);

       
       return nums[k-1];
    }
};