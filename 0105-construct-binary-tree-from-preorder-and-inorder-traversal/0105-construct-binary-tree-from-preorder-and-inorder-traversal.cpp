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
    int findPos(int element , vector<int>&inorder ,int n){
       for(int i=0;i<n;i++){
        if(inorder[i] == element){
             return i;
        }
       }
       return -1;

    }
  
   TreeNode* func(vector<int>& preorder, vector<int>& inorder , int n , int &preindex, int instart, int inend){
       // base case 
       if (preindex>=n || instart>inend){
          return NULL;
       }

       // 1case solve kar do
        int element = preorder[preindex];
        preindex++;

        //abb uss element ko node mei badal dena hai 
        TreeNode* root = new TreeNode(element);

        //search in the inorder array the element
        int pos = findPos(element, inorder, n);

        // calling for the left part 
        
      root->left = func( preorder, inorder , n , preindex,  instart,pos-1);
    root->right = func( preorder, inorder , n , preindex,  pos+1,inend);

   return root;


   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preindex =0;
        int instart =0;
        int inend = n-1;

        return func(preorder, inorder, n , preindex, instart, inend);

         

    }
};