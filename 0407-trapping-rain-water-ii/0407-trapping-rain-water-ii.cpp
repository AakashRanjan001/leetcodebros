class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        //top left to top right
        for(int i=0;i<m;i++)
        {
            pq.push({heightMap[0][i],{0,i}});
            visited[0][i]=true;
        }
        //bottom left to bottom right
        for(int i=0;i<m;i++)
        {
            pq.push({heightMap[n-1][i],{n-1,i}});
            visited[n-1][i]=true;
        }
        //top left to bottom left
        for(int i=0;i<n;i++)
        {
            pq.push({heightMap[i][0],{i,0}});
            visited[i][0]=true;
        }
        //top right to bottom right
        for(int i=0;i<n;i++)
        {
            pq.push({heightMap[i][m-1],{i,m-1}});
            visited[i][m-1]=true;
        }
        int water=0;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int height=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            for(auto dir:directions)
            {
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m && !visited[i_][j_])
                {
                    water+=max(height-heightMap[i_][j_],0);
                    pq.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_]=true;
                }
            }

        }
        return water;

    }
};