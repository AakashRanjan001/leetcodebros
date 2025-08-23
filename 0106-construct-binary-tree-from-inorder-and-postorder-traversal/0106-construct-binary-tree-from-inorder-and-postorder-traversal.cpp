// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* build(vector<int>& inorder,int instart,int inend ,vector<int>& postorder, int poststart, int postend,  map<int,int>&mp ){
           
//            if(instart>inend || poststart>postend)return NULL;

//            TreeNode* node = new TreeNode(postorder[postend]);
//            int inroot = mp[node->val];
//            int numsleft = inroot - instart;
//            node->left = build(inorder, instart , inroot-1, postorder, poststart,poststart + numsleft,mp);
//            node->right = build(inorder, inroot+1 , inend, postorder, poststart+numsleft+1,postend,mp);
//            return node;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//          if(inorder.size()!=postorder.size())return NULL;

//          //hash the value for the inorder
//          map<int,int>mp;
//          for(int i=0;i<inorder.size();i++){
//              mp[inorder[i]] = i;
//          }
//          TreeNode* root = build(inorder,0,inorder.size()-1, postorder,0,postorder.size()-1,mp);
//          return root;
//     }
// };

class Solution {
public:
    TreeNode* build(vector<int>& inorder, int instart, int inend,
                    vector<int>& postorder, int poststart, int postend,
                    map<int,int>& mp) {
        if (instart > inend || poststart > postend) return NULL;

        TreeNode* node = new TreeNode(postorder[postend]); // root from postorder
        int inroot = mp[node->val];
        int numsleft = inroot - instart;

        node->left = build(inorder, instart, inroot - 1,
                           postorder, poststart, poststart + numsleft - 1, mp);

        node->right = build(inorder, inroot + 1, inend,
                            postorder, poststart + numsleft, postend - 1, mp);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;

        map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, mp);
    }
};
