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
    bool isSorted(vector<int>&ans){
           for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]){
                return false;
            }
           }
           return true;
    }

    void inorderBST(TreeNode* root, vector<int>&ans){
        if(root == NULL){
           return;
        }
        //LNR
        inorderBST(root->left,ans);
        ans.push_back(root->val);
        inorderBST(root->right,ans);

    }

    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorderBST(root,ans);
      
      return isSorted(ans);
    }
};