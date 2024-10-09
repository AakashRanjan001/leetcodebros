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
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         bool LtoRdir = true; // for left to right maan liya 
//         queue<TreeNode*>q;
//         q.push(root);

//         while(!q.empty()){
//             // abb width kya hoga ek vector ka 
//             int width = q.size();
//             vector<int>oneLevel(width);
//             for(int i=0;i<width;i++){
//                  TreeNode* temp = q.front();
//                  q.pop();
//                  int index ;
//                  if(LtoRdir == true){
//                       index =i;
//                  }
//                  else{ // agar LtoRdir is false matlab reverse order mei print karna hai toh index ko peeche se start karna padega 
//                     index = width - i-1; // agar 
//                  }
//                 oneLevel[index] = temp->val;
//                 if(temp->left!=NULL){
//                     q.push(temp->left);
//                 }
//                 if(temp->right!=NULL){
//                     q.push(temp->right);
//                 }
                 
//             }
//           // har ek level ke baad toggle karna hai
//           LtoRdir = !LtoRdir;
//           ans.push_back(oneLevel);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (root == NULL) return ans;  // Handle empty tree case
        
        bool LtoRdir = true; // Start from left to right
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int width = q.size();
            vector<int> oneLevel(width);
            
            for (int i = 0; i < width; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                int index;
                if (LtoRdir) {
                    index = i;
                } else {
                    index = width - i - 1;
                }
                
                oneLevel[index] = temp->val;
                
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            
            // Toggle direction after each level
            LtoRdir = !LtoRdir;
            ans.push_back(oneLevel);
        }
        
        return ans;
    }
};
