class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>maxLocal(n-2,vector<int>(n-2,0));
        
    
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                   int maxi = INT_MIN;
                   for(int p =i;p<=i+2;p++){
                    for(int q=j;q<=j+2;q++){
                        maxi = max(maxi , grid[p][q]);
                    }
                   }   
                   maxLocal[i][j]=maxi;           
            }
        }
        return maxLocal;
    }
};