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
     int  height(TreeNode* root){
          if(root == NULL){
            return 0;
          }

         int leftheight = height(root->left);
         int rightheight = height(root->right);

         int ans =1 +  max(leftheight, rightheight);

         return ans;
     }


   
    bool isBalanced(TreeNode* root) {
        //bas ecase 
        if(root == NULL){
            return true;
        }
        //1 case solve karo do that is for root node 
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);

        bool ans1 = (diff<=1);

        //recursiion sambhal lega
        bool leftpart = isBalanced(root->left);
        bool rightpart = isBalanced(root->right);

        if(ans1 && leftpart && rightpart){
            return true;
        }
        else{
            return false;
        }
    }
};