/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track , TreeNode* target){
           queue<TreeNode*>que;
           que.push(root);

           while(!que.empty()){
              TreeNode* curr = que.front();
              que.pop();
              if(curr->left!=NULL){
                 parent_track[curr->left] = curr;
                 que.push(curr->left);
              }
              if(curr->right!=NULL){
                parent_track[curr->right] = curr;
                que.push(curr->right);
              }
           }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // step1 : we have to make a map to store the parent pointers of a ndoe 
        unordered_map<TreeNode*, TreeNode*>parent_track; // node - > parent
        markParent(root,parent_track,target);


        unordered_map<TreeNode*,bool>visited; // to check which of the nodes are already visited 
        queue<TreeNode*>queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!queue.empty()){

            int size = queue.size();
            if(curr_level++ == k)break;

            for(int i=0;i<size;i++){
                 TreeNode* current = queue.front();
                 queue.pop();

                 if(current->left!=NULL && !visited[current->left]){
                     queue.push(current->left);
                     visited[current->left] = true;
                 }
                 if(current->right!=NULL && !visited[current->right]){
                     queue.push(current->right);
                     visited[current->right] = true;
                 }
                 if(parent_track[current] && !visited[parent_track[current]]){
                     queue.push(parent_track[current]);
                     visited[parent_track[current]] = true;
                 }
            }
             
        }
        vector<int>res;
        while(!queue.empty()){
             res.push_back(queue.front()->val);
             queue.pop();
        }
        return res;


           
    }
};