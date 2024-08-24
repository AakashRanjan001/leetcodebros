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
  void solve(TreeNode* root , int tsum , int csum , vector<int>path , vector<vector<int>>&ans ){
      
      if(root == NULL){
        return;
      }
      if(root->left == NULL && root->right == NULL){
           path.push_back(root->val);
       csum+=root->val;

            if(csum == tsum){
                ans.push_back(path);
            }
            return;
      }

      // 1 case solve 
       path.push_back(root->val);
       csum+=root->val;

       solve(root->left,tsum , csum , path, ans);
       solve(root->right,tsum , csum , path, ans);
  }
    vector<vector<int>> pathSum(TreeNode* root, int tsum) {
        int csum =0;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root, tsum  ,csum , temp ,ans);
        return ans;
    }
};