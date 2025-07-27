class Solution {
public:
    int solveTab(int x, vector<int> &coins){
         //dp[i] --> No.of ways to solve sum = i 
         // tarnsition func --> dp[i] = sum of all possible ways dp[amount - coins[j]]
         const int MOD = 1e9 + 7;
         vector<long long>dp(x+1 , 0);
         dp[0] = 1;
         for(int j=0;j<coins.size();j++){
             for(int i=1;i<=x;i++){
                if((i-coins[j])>=0)
                 dp[i] +=dp[i-coins[j]] % MOD;
             }
         }
         return dp[x];

    }
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
         int ans = solveTab(amount , coins);
         return ans;
    }
};