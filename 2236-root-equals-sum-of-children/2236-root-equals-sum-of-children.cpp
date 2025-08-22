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
    int checksum(TreeNode* root){
         int sum = 0;
         if(root == NULL)return 0;
         if(root->left!=NULL &&root->right!=NULL){
             sum = sum + root->left->val;
             sum = sum + root->right->val;
         }
         return sum;
    }
    bool checkTree(TreeNode* root) {
         if(root == NULL)return true;

         int ans = checksum(root);
         if(root->val == ans)return true;
         return false;
    }
};