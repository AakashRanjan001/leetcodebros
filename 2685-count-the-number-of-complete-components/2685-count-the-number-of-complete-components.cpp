class Solution {
public:
   void dfs(int start , vector<vector<int>>& adj , vector<bool>&vis , int &nodes , int &degreeSum){
        vis[start] = true;
        nodes++;
        degreeSum+=adj[start].size();
        for(auto &v:adj[start]){
             if(!vis[v]){
                 dfs(v,adj,vis,nodes,degreeSum);
             }
        }
         
   }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         // yaha hame 2 d matrix  diya hua hai 
          vector<vector<int>>adj(n);
         for(auto &it:edges){ // undirected graph hai 
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
         }
         vector<bool>vis(n);
         int cnt =0;
         for(int start=0;start<n;start++){
             if(!vis[start]){
                 int nodes =0;
                 int degreeSum =0;

                 //dfs 
                 dfs(start,adj,vis,nodes,degreeSum);
                 if(degreeSum == nodes*(nodes - 1)){
                     //matlab complete component hai 
                     cnt++;
                 }
             }
         }
         return cnt;
    }
};