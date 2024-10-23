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
    int ans = 0; // to store the no.of paths from a single node 
    void pathoneRoot(TreeNode* root , long long sum){
        if(root == NULL)return;

        if(sum == root->val){
            ++ans;
        }
       // preorder traversal karna hai 
       pathoneRoot(root->left, sum - root->val);
       pathoneRoot(root->right, sum - root->val);

    }
    int pathSum(TreeNode* root, long long targetSum) {
        // hame har ek node ke corresponding paths check karne hai ki woh pathsum ke equAL HAI KI NHI 
        if(root == NULL)return 0;
        if(root!= NULL){
            pathoneRoot(root , targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};