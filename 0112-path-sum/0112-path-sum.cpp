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
    bool solve(TreeNode *root , int targetSum ,int currSum ){
        //base case 
        if(root == NULL){
            return false;
        }
    
        // 1 case solve karo do
         currSum+=root->val; 
         // to check for the leaf node 
          if(currSum == targetSum && root->left == NULL && root->right== NULL){
            return true;
        }
         return solve(root->left,targetSum , currSum )|| solve(root->right , targetSum, currSum);
    }
   
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int currSum =0;
        return solve(root , targetSum , currSum );
    }
};