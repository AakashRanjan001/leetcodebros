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
    bool solve(TreeNode* root , long long int lb , long long int ub){
        // basecase
        if(root == NULL){
            return true; // matlab tree empty hai toh pakka BST hoga 
        }
        if(root->val > lb && root->val < ub){
            // matlab root ka data range mei hai 
            // tab apon left aur right ki call maareneg
            bool leftans = solve(root->left , lb , root->val);
            bool rightans = solve(root->right , root->val , ub);
            // agara dono side se tue hua tabhi valid BSt
            return leftans && rightans;
        }
        // agar range mei lie nahi karta hai tab
        else{
             return false;
        }

         
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerbound = -4294967296;
        long long int upperbound = 4294967296;

       return solve(root, lowerbound,upperbound);
    }
};