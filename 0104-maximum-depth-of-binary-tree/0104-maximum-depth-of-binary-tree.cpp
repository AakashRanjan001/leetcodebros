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
    int maxHeight(TreeNode* temp){
         if(temp == NULL)return 0;
         
         int leftheight = maxHeight(temp->left);
         int rightheight = maxHeight(temp->right);

         return max(leftheight,rightheight) +1 ;
    }
    int maxDepth(TreeNode* root) {
        TreeNode* temp = root;
         int height = maxHeight(temp);
         return height;
         
    }
};