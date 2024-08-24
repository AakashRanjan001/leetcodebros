
class Solution {
public:
    int cnt = 0;

    void solve(TreeNode* root, int targetSum, long long csum) {
        // base case
        if (root == NULL) {
            return;
        }

        csum += root->val;
        if (csum == targetSum) {
            cnt++;
        }

        solve(root->left, targetSum, csum);
        solve(root->right, targetSum, csum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0; // Base case to terminate recursion

        long long csum = 0;

        solve(root, targetSum, csum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return cnt;
    }
};
