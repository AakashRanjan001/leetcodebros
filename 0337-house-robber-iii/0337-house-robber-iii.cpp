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
    int solve(TreeNode* root){
         if(root == NULL)return 0;

         // 1 case solve kardo 
         int robThisHouse =0;
         int dontRobthisHouse =0;

         //robb the current house
          robThisHouse+=root->val;
          if(root->left!=NULL){
             robThisHouse+=solve(root->left->left) + solve(root->left->right);
          }
          if(root->right!=NULL){
             robThisHouse+=solve(root->right->left)+ solve(root->right->right);
          }
         //dont rob current house 
         dontRobthisHouse = solve(root->left) + solve(root->right);
         int ans = max(dontRobthisHouse,robThisHouse);
         return ans;
    }
    int rob(TreeNode* root) {
        
       int ans = solve(root);
       return ans;   
    }
};