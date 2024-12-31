class Solution {
public:
   int solve(int n){
     if(n<=1)return 1;
     int ans = 0;// considering every node as root node 
     for(int i=1;i<=n;i++){
        ans+= solve(i-1)*solve(n-i);
     }
      return ans;
   }
   int solveUsingMem(int n,vector<int>&dp ){
     // base case
     if(n<=1)return 1;

     if(dp[n]!=-1)return dp[n];

     int ans = 0;// considering every node as root node 
     for(int i=1;i<=n;i++){
        ans+= solveUsingMem(i-1,dp)*solveUsingMem(n-i,dp);
     }
      dp[n] = ans;
      return dp[n];
      
   }

    int numTrees(int n) {
    //    return solve(n);

    vector<int>dp(n+1,-1);
    int ans = solveUsingMem(n,dp);
    return ans;

    }
};