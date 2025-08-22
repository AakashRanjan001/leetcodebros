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
//     int findMaxdist( unordered_map<TreeNode*, TreeNode*>&mp,TreeNode* target ){
//            queue<TreeNode*>queue;
//            unordered_map<TreeNode* , bool>vis;
//            queue.push(target);
//            vis[target] = true;

//            int maxi = 0;

//            while(!queue.empty()){
//                int size = queue.size();
//                int fl = 0;
//                for(int i=0;i<size;i++){
//                    auto node = queue.front(); // choosing a node // here the startibg node is  the target node 
//                    queue.pop();

//                    if(node->left!=NULL){ // uske left 
//                       fl = 1; 
//                      vis[node->left] = true;
//                      queue.push(node->left);

//                    }
//                    if(node->right!=NULL){ // uske rigfht 
//                      fl = 1;
//                      vis[node->right] = true;
//                      queue.push(node->right);
//                    }

//                    if(mp[node] && !vis[mp[node]]){   // uske parent
//                        fl = 1;
//                        vis[mp[node]] = 1;
//                        queue.push(mp[node]);
//                    }

//                }
//                if(fl)maxi++;

//            }
//         return maxi;
           
//     }

//     TreeNode* BfsToMapParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>&mp, int start){
//          queue<TreeNode*>q;
//          q.push(root);
//          TreeNode* res;
//          while(!q.empty()){
//              TreeNode* node = q.front();
//              if(node->val== start )res = node;
//              q.pop();

//              if(node->left!=NULL){
//                  mp[node->left] = node;
//                  q.push(node->left);
//              }
//              if(node->right!=NULL){
//                  mp[node->right] = node;
//                  q.push(node->right);
//              }
//          }
//          return res;

//     }
//     int amountOfTime(TreeNode* root, int start) {
//          unordered_map<TreeNode*, TreeNode*>mp;
//          TreeNode* target = BfsToMapParent(root,mp,start); // returns me the node address where this target lies
//                             
                   // means start ka address bata deta hai 

//          int maxi = findMaxdist(mp,target);
//          return maxi;
//     }
// };


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
    int findMaxdist(unordered_map<TreeNode*, TreeNode*>& mp, TreeNode* target) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;

        int maxi = 0;

        while (!q.empty()) {
            int size = q.size();
            int fl = 0;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    fl = 1;
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    fl = 1;
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if (mp[node] && !vis[mp[node]]) {
                    fl = 1;
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                }
            }
            if (fl) maxi++;
        }
        return maxi;
    }

    TreeNode* BfsToMapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node->val == start) res = node;
            q.pop();

            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* target = BfsToMapParent(root, mp, start);
        int maxi = findMaxdist(mp, target);
        return maxi;
    }
};

