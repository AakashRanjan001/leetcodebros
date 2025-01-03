class Solution {
public:
    void bfs(map<pair<int,int>,bool> &visited, int row, int col ,vector<vector<char>>& grid ){
           queue<pair<int,int>>q;//step1 
           // perform the steps 
           q.push({row,col});
           visited[{row,col}] = true;
    

           while(!q.empty()){
              pair<int,int>fnode = q.front();
              q.pop();
              int x = fnode.first;
              int y = fnode.second;

              // now after defining the coordinates i can move in every directions four ways
              int dx[] = {-1,0,1,0};
              int dy[] ={0,1,0,-1}; // ye ek naya tareeeka seekha maine 

              for(int i=0;i<4;i++){
                  int newX = x + dx[i];
                  int newY = y + dy[i];

                  if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && 
                       !visited[{newX,newY}] && grid[newX][newY] == '1'){
                          q.push({newX,newY});
                          visited[{newX,newY}] = true;

                       }
              }
           }

    }
    int numIslands(vector<vector<char>>& grid) {
        // hame bfs karna hai na 
        map<pair<int,int>,bool>visited;

        int cnt =0;
        for(int row =0;row<grid.size();row++){
            int n = grid[row].size();
             for(int col = 0;col<n;col++){ // YAHA MAINE GALTI KI THI
                 if(!visited[{row,col}] && grid[row][col] == '1'){
                     bfs(visited,row,col,grid); // hamm call tabhi karenge jab grid[row][col] == 1 hoga 
                     cnt++;
                 }
             }
        }
        return cnt;
    }
};