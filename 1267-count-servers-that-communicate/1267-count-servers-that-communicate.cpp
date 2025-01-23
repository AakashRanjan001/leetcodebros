class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // kayde se dekhke ke BFS ka question lag rha hia but i am trying it using  array and 
        //thoda hint liya tha
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        vector<int>rowcnt(n,0);
        vector<int>Colcnt(m,0);

        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                 if(grid[i][j] == 1){
                     cnt++;
                     rowcnt[i]++;
                     Colcnt[j]++;
                 }
            }
        }

        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j] == 1 && rowcnt[i] == 1 && Colcnt[j] == 1){
                     cnt--; //matlab ye ek isolated one hai 
                 }
             }
        }
        return cnt;
    }
};