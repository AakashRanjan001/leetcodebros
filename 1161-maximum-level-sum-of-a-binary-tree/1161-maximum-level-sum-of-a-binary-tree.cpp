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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)return 0;
        queue<TreeNode*>q;
        vector<long long>sumarr;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long long sum =0;
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();

                sum+=front->val; // calculating the sum of each level 

                //calling the left and right childs 
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            sumarr.push_back(sum);
        }
       
       int res = 0;
       int maxSum = sumarr[0];
       for(int i=0;i<sumarr.size();i++){
        if(sumarr[i]>maxSum){
             res =i;
             maxSum = sumarr[i];
        }
       }
          return res + 1;
    }
};