class Solution {
public:
      bool check(int nx, int ny , int n, int m){
        return nx>=0 && ny>=0 && nx<n && ny<m;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();int m=isWater[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                q.push({0,i,j});
                vis[i][j]=1;
                }
            }
        }
        while(q.size()>0){
           int curr=q.front()[0];
           int curr_x=q.front()[1];
           int curr_y=q.front()[2];
           q.pop();
           int delRow[]={-1,0,1,0};
           int delCol[]={0,-1,0,1};
           for(int i=0;i<4;i++){
            int nx=curr_x+delRow[i];
            int ny=curr_y+delCol[i];
            if(check(nx,ny,n,m) && !vis[nx][ny]){
                 vis[nx][ny]=1;
                 dis[nx][ny]=curr+1;
                 q.push({curr+1,nx,ny});
            }
           }
        }
        return dis;
    }
};