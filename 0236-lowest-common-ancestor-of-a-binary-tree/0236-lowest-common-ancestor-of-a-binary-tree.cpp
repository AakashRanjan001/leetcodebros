/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         //base case 
         if(root == NULL){
            return NULL;
         }

        //check for the presence of p and q
         if(root->val == p->val){
            return p;
         }
         if(root->val == q->val){
            return q;
         }
         //agar p and q niche hai root ke tab leftpart mei search karo and rightpart mei search karo

         TreeNode* leftpart = lowestCommonAncestor(root->left , p ,q);
         TreeNode* rightpart = lowestCommonAncestor(root->right , p ,q);
         if(leftpart == NULL && rightpart == NULL){
            return NULL;
         }
         else if(leftpart == NULL && rightpart!=NULL){
            return rightpart;
         }
         else if(leftpart !=NULL && rightpart == NULL){
            return leftpart;
         }
       else{ // leftpart !=NULL && rightpart!=NULL
            return root;
       }
  


    }
};