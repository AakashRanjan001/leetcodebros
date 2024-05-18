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
    int solve(TreeNode* root, int& move)
    {
        if (!root)
            return 0;

        int left = solve(root->left, move);
        int right = solve(root->right, move);

        int curr = root->val + left + right - 1;
        move += abs(curr);
        return curr;
    }
public:
    int distributeCoins(TreeNode* root) {
        int move = 0;
        solve(root, move);
        return move;
    }
};
