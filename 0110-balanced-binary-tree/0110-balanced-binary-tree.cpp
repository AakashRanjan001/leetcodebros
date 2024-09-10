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
    int height(TreeNode* root){
        if(root == NULL){
           return 0;
        }
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        int maxdepth = 1 + max(leftheight, rightheight);
        return maxdepth;
    }
    
    bool isBalanced(TreeNode* root) {
         //base case 1 hi node hai toh pakka ye hoga 
         if(root == NULL){
            return true;
         }

// 1 case solve kar lo 
         int leftheight = height(root->left);
         int rightheight = height(root->right);
       int diff = abs(leftheight-rightheight);
       bool ans1 = (diff<=1);

   // baaki recursion solve kar leag 
     bool leftpart = isBalanced(root->left);
     bool rightpart = isBalanced(root->right);

     if((ans1 && leftpart && rightpart) == true){
        return true;
     }
     else{
        return false;
     }


         

    }
};