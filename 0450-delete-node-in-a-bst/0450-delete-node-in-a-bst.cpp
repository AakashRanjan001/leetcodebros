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

int maxVal(TreeNode* root){
     TreeNode* temp = root;

     if(temp == NULL){ // agar node is not present 
      return -1;
     }

     //agar node present hai 
     while(temp->right != NULL){  // jab tak temp ka right not equal to null hai tab tak apon right jaate jayenge 
        temp = temp->right;
     }
    return temp->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
         return NULL;
 }
 
 if(root->val == key){
    // isi ko delete karna hai 
    // we use the 4 cases
    if(root->left == NULL && root->right == NULL){
      //leaf node
      //delete root
      return NULL;
    }
    else if(root->left == NULL && root->right !=NULL){
      TreeNode* child = root->right;
      //delete root;
      return child;
    }
    else if(root->left!= NULL && root->right == NULL){
      TreeNode* child = root->left;
      //delete root
      return child;
    }
    else{
      //both child 
      //find the predecessor in the left subtree
      int InorderPre = maxVal(root->left);
      //replace root ka data with inorderPre
      root->val = InorderPre;

      //delete inorder pre from the left subtree
      root->left = deleteNode(root->left, InorderPre);
      return root;
    }
 }

 else if(key > root->val){
  // right jaana chhaiye 
    root->right = deleteNode(root->right,key);
 }
 else{
  root->left = deleteNode(root->left,key);
 }
 return root;
    }
};