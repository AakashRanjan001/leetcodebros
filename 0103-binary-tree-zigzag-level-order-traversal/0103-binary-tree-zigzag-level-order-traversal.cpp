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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root == NULL)return ans;
          queue<TreeNode*>q;
          q.push(root);
          int level =0;

          while(!q.empty()){
                 vector<int>var;
               
               int size = q.size();
               for(int i=0;i<size;i++){
                    TreeNode* temp = q.front();
                     q.pop();
                      
                     var.push_back(temp->val);

                     if(temp->left!=NULL)q.push(temp->left);
                     if(temp->right!=NULL)q.push(temp->right);
               }
                
               ans.push_back(var);
            
          }
          for(int i=0;i<ans.size();i++){
              if(i%2!=0){
                 reverse(ans[i].begin(),ans[i].end());
              }
          }
          return ans;
      
          
    }
};