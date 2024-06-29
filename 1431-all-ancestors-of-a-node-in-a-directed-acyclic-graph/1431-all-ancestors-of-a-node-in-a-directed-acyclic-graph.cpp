class Solution {
public:
void dfs(int node,vector<int>adj[],vector<int>&ans,int k,vector<int>&vis){
    for(auto it:adj[node]){
        if(vis[it]==0)
        dfs(it,adj,ans,k,vis);
    }
    if(node!=k && vis[node]==0){
    ans.push_back(node);
    }
    vis[node]=1;
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res;
        vector<int>adj[n];
        for(auto it:edges){

            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);

        }
        for(int i=0;i<n;i++){
        vector<int>vis(n,0);
        vector<int>ans;
         dfs(i,adj,ans,i,vis);
        
        res.push_back(ans);
        }
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
          return res;

    }
};
