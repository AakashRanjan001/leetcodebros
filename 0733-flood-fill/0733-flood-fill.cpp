class Solution {
public:
     void dfs(int x,int y, int oldColor, int newColor, map<pair<int,int>,bool> &vis,vector<vector<int>>& arr){
        
        //step 1: visited ko mark karo 
        vis[{x,y}] = true;
        arr[x][y] = newColor; // har baar recursive call mei color chage hoga 

        //fir dfs call maaro uske neighbors ke liye 
          int dx[] = {-1,0,1,0};
          int dy[] = {0,1,0,-1};

          for(int i=0;i<4;i++){
             int newX = x+ dx[i];
             int newY = y + dy[i];

             if(newX>=0 && newX<arr.size() && newY>=0 && newY < arr[0].size() && !vis[{newX,newY}] && arr[newX][newY] == oldColor){
                 // agar ye saari conditions true hogi then we will call the dfs
                 dfs(newX,newY,oldColor, newColor, vis,arr);
             }
          }
        
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        map<pair<int,int>,bool>vis;
         vector<vector<int>> ans = image; // always make a copy of an image it is a  good practice for it 
        dfs(sr,sc,oldColor,color,vis,ans);
        return ans;
    }
};