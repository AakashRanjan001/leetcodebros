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
    void inorder(TreeNode* root , vector<int>& temp, int k){
         if(root == NULL)return;

         inorder(root->left,temp,k);
         temp.push_back(root->val);
         inorder(root->right,temp,k);
    }
    int kthSmallest(TreeNode* root, int k) {
         vector<int>temp;
         inorder(root, temp ,k);

         return temp[k-1];

    }
};