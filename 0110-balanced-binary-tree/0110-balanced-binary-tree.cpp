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

        int maxi = max(leftheight, rightheight)+1;
        return maxi;
    }
  
    bool isBalanced(TreeNode* root) {
        //balance dekhne ke liye check katrte hai whther the tree diff of the leftpart and the rightpart is less than equla to 1
        //base case 
         if(root == NULL){
            return true;
         }

         // 1 case solve kar do
         int leftheight = height(root->left);
         int  rightheight= height(root->right);
         int diff = abs(leftheight - rightheight);
           bool ans1 = (diff<=1);

         bool leftpart =isBalanced(root->left);
         bool rightpart = isBalanced(root->right);

      if(ans1 &&  leftpart && rightpart){
        return true;
      }
      else{
        return false;
      }

    }
};