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
    vector<int> largestValues(TreeNode* root) {

        if(!root)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
      
        while(!q.empty()){
             int n = q.size();
            int maxVal = INT_MIN;
             for(int i=0;i<n;i++){
                TreeNode* frontNode = q.front();
                q.pop();
               
               maxVal = max(maxVal,frontNode->val);
                

                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                     q.push(frontNode->right);
                }
             }
             ans.push_back(maxVal);
        }
        return ans;
    }
};