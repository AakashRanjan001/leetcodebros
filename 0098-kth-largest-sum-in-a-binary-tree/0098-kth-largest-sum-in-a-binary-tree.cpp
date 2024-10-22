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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        //level order traversal

        if(root == NULL)return 0;
         queue<TreeNode*>q;
         vector<long long>sumarr;
      
         q.push(root);

             while(!q.empty()){
                int n = q.size();
                 long long sum = 0;
                for(int i=0;i<n;i++){
                 TreeNode* front = q.front();
                 q.pop();

                 sum+=front->val;

                 if(front->left!=NULL){
                    q.push(front->left);
                 }
                 if(front->right!=NULL){
                    q.push(front->right);
                 }
                }
            
            sumarr.push_back(sum);
         }
         sort(sumarr.rbegin(),sumarr.rend());
         if(sumarr.size()<k)return -1;
         return sumarr[k-1];
    }
};

//    if (root == nullptr) return 0;

//         // For the level order traversal in a binary tree 
//         queue<TreeNode*> q;
//         q.push(root);
//         vector<long long> sumarr;

//         while (!q.empty()) {
//             int n = q.size();
//             long long sum = 0;
//             for (int i = 0; i < n; ++i) {
//                 TreeNode* temp = q.front(); // Step A
//                 q.pop(); // Step B

//                 sum += temp->val; // Step C

//                 // Step D: Adding child nodes to the queue
//                 if (temp->left != nullptr) {
//                     q.push(temp->left);
//                 }
//                 if (temp->right != nullptr) {
//                     q.push(temp->right);
//                 }
//             }
//             sumarr.push_back(sum);
//         }

//         // Sort the sums in descending order
//         sort(sumarr.rbegin(), sumarr.rend());
//         if (sumarr.size() < k) return -1;

//         return sumarr[k - 1];