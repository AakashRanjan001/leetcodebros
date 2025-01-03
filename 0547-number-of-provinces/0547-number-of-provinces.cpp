class Solution {
public:
    void dfs( unordered_map<int,bool> &vis,int src ,vector<vector<int>>& isConnected ){
        vis[src] = true;
        //row -->src
        //col --> we will use a loop
        int size =  isConnected[src].size(); 
        for(int col =0;col<size;col++){
             if(isConnected[src][col] == 1){
                 //edge is there or it is a neigbor 
                 if(!vis[col]){
                     dfs(vis,col,isConnected);
                 }
             }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int cnt =0;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            if(!visited[i]){
                 dfs(visited,i,isConnected);
                 cnt++;
            }
        }
        return cnt;
    }
};