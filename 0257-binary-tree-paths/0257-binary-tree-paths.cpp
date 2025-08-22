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
    void preorder(TreeNode* root , string path , vector<string>& ans){
         if(root == NULL)return;

         if(path.empty()){
             path = (to_string(root->val));
         }
         else{
             path = path + "->" + to_string(root->val);
         }

         if(root->left == NULL && root->right == NULL){
             //means we have reaceh dthe leaf nod e
             ans.push_back(path);
             return;
         }

         preorder(root->left,path,ans);
         preorder(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string>ans;
          preorder(root,"",ans);
          return ans;
    }
};