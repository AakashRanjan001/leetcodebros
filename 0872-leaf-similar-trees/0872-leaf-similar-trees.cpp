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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        return leaves(root1) == leaves(root2);
    }

    string leaves(TreeNode* root){
        if(!root) return "";
        if(!root->left && !root->right) return to_string(root->val);
        else return ((root->left)? leaves(root->left): "") + ((root->left && root->right)? ".": "") + ((root->right)? leaves(root->right): "");
    }
    
};