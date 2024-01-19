
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int ans=0;
        int n= matrix.size();
        int m= matrix[0].size();
         vector<vector<int>> dp(n,vector<int>(m,0));
         for(int i=0;i<m;i++){
           dp[0][i]=matrix[0][i];
         }
        for(int i=0;i<m;i++){
           cout<<dp[0][i]<<" ";
         }
         for(int i=1;i<n;i++){
             for(int j=0;j<m;j++){
                 if(j==0){
                     dp[i][j]=matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                 }
                 else if(j==m-1){
                     dp[i][j]=matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                 }
                 else{
                     dp[i][j]=matrix[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                 }
             }
              for(int k=0;k<m;k++){
           cout<<dp[i][k]<<" ";
         }
         }

         vector<int> v;
         for(int i=0;i<m;i++){
           v.push_back(dp[n-1][i]);
         }
         sort(v.begin(),v.end());
        return v[0];
    }
};