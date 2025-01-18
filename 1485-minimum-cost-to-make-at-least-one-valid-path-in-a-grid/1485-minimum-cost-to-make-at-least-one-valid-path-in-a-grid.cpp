class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1)return 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        set<vector<int>>st;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        while(q.size()>0){
            int curr=q.top()[0];
            int curr_x=q.top()[1];
            int curr_y=q.top()[2];
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int n_x=delRow[i]+curr_x;
                int n_y=delCol[i]+curr_y;
                if(n_x>=0 && n_x<n && n_y>=0 && n_y<m){
                    if(delRow[i]==1 && grid[curr_x][curr_y]==3 && dis[n_x][n_y]>curr){
                       dis[n_x][n_y]=curr;
                       q.push({curr,n_x,n_y});
                    }
                    else if(delRow[i]==-1  &&  grid[curr_x][curr_y]==4 && dis[n_x][n_y]>curr){
                         dis[n_x][n_y]=curr;
                         q.push({curr,n_x,n_y});
                    }
                    else if(delCol[i]==1 &&  grid[curr_x][curr_y]==1 && dis[n_x][n_y]>curr){
                              dis[n_x][n_y]=curr;
                              q.push({curr,n_x,n_y});
                    }
                        else if(delCol[i]==-1 &&  grid[curr_x][curr_y]==2 && dis[n_x][n_y]>curr){
                              dis[n_x][n_y]=curr;
                              q.push({curr,n_x,n_y});
                    }
                    else {
                         if(dis[n_x][n_y]>curr+1){
                            dis[n_x][n_y]=curr+1;
                            q.push({curr+1,n_x,n_y});
                         }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};