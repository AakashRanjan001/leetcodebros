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
//     void solve(TreeNode* root ,map<pair<int,vector<int >>m , vector<vector<int>>ans, int d){
//         if(root == NULL)return;

//         m[d].push_back(root->data);
//         solve(root->left, m , ans , d-1);
//         solve(root->right,m,ans,d+1);

//     }

//     vector<vector<int>> verticalTraversal(TreeNode* root) {
      
//       map<pair<int ,vector<int>>m;
//       vector<vector<int>>ans;
//       int d =0;
//     return solve(root , m , ans , d);


//         for(auto i:m){
//             ans.push_back(i.second);
//         }

//         return ans;
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
// class Solution {
// public:
//     void solve(TreeNode* root, map<int, vector<int>>& m, int d) {
    //     if(root == NULL) return;

    //     m[d].push_back(root->val);
    //     solve(root->left, m, d - 1);  // Move to the left subtree
    //     solve(root->right, m, d + 1); 
    // }

    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     map<int, vector<int>> m;
    //     vector<vector<int>> ans;
    //     int d = 0;

    //     solve(root, m, d);  // Call the recursive function to populate the map

    //     for(auto i : m) {
    //         ans.push_back(i.second);  // Add the vectors of nodes at each depth
    //     }

    //     return ans;  // Return the vertical order traversal result

    //     // itna toh sahi kiya hai ki vertical order traversal mei leke aa gya but sorted nhi aaya hai bass wahi dikkat hai 

    class Solution{
        public:
        vector<vector<int>>verticalTraversal(TreeNode* root){

           vector<vector<int>>ans;
           queue<pair<TreeNode*, pair<int,int>>>q; // node , {row,col}// for the level order traversal , taaki pata chale ki kaunsa node kaunse coordinate system emi hai 
           map<int, map<int,multiset<int>>>mp; // col -> {row , [set of nodes in single row in sorted manner]}
           q.push({root,{0,0}});

           while(!q.empty()){
                 auto front = q.front();
                 q.pop();

                 TreeNode* &node = front.first;
                 auto &coordinate = front.second;
                 int &row = coordinate.first;
                 int &col = coordinate.second;
                 mp[col][row].insert(node->val);

                 if(node->left){
                    q.push({node->left , {row+1 , col-1}});
                 }
                 if(node->right){
                    q.push({node->right , {row+1 , col+1}});
                 }
           }
          for(auto &it:mp){
              auto &colMap = it.second;
              vector<int>vLine;
              for(auto colMapit:colMap){
                 auto&mset  = colMapit.second;
                 vLine.insert(vLine.end() , mset.begin(),mset.end());
              } 
              ans.push_back(vLine);
          }
          return ans;

       
    }
};
