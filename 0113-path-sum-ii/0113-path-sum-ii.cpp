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

    void solve(TreeNode* root , int targetSum , int currSum ,vector<int> path , vector<vector<int>>&ans){
        cout<< "currSum is"<<currSum<<endl;
      // base case 
       if(root == NULL)return;

      // means apon leaf node mei hai 
       if(root->left == NULL && root->right == NULL){
              path.push_back(root->val);
               currSum+=root->val;
           if(currSum == targetSum){
               ans.push_back(path);
           }
           return ;
       }
     // 1 case solve kar lo
      path.push_back(root->val);
      currSum+=root->val;

      // check karo ki currSum targetSum ke barabar hai ki nhi agar nhi hai aaage call maar do
        solve(root->left, targetSum, currSum , path , ans);
        solve(root->right, targetSum, currSum , path , ans);


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int currSum = 0;
        solve(root , targetSum , currSum, temp ,ans);
        return ans;
    }
};