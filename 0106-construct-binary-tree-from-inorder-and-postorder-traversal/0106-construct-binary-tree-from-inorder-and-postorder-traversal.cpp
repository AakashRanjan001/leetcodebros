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
    int findPos( int element , vector<int>&inorder , int n){
        for(int i=0;i<n;i++){
            if(element == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* func(vector<int>& inorder, vector<int>& postorder , int n , int &postindex, int instart , int inend){
        //base case 
         if(postindex<0 || instart>inend){
            return NULL;
         }
           // pehele element nikal lo from postorderf
          int element = postorder[postindex];
          postindex--;

     // abb uss element ka Node create kar do 
    TreeNode* root = new TreeNode(element);

    //given element ko inorder wale mei doondhna padega 
    int pos = findPos(element , inorder, n);

    // right ka call
    root->right =  func(inorder, postorder, n , postindex, pos+1, inend);
   root->left =  func(inorder, postorder, n , postindex, instart, pos-1);

    return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postindex = n-1;
        int instart = 0;
        int inend = n-1;
     
        return func(inorder, postorder, n, postindex, instart, inend);

    }
};