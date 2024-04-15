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
 #include<bits/stdc++.h>
class Solution {
public:
     string s="";
   void f(TreeNode* root, vector<string> &v){
    if(root) s+= to_string(root -> val);
    if(root -> left) f(root-> left, v);
    if(root -> right) f(root-> right, v);
    if(root->left ==NULL && root->right==NULL) v.push_back(s);
    if(s.size()) s.pop_back();
     return;
   }
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        f(root, v);
        int sum=0;
        for(int i=0; i<v.size(); i++){
            int x= stoi(v[i]);
            sum+= x;
        }
        return sum;
    }
};
