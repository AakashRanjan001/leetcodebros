
class Solution {
public:
    int solve(vector<int>& prices, int i, bool buy) {
        // Base case
        int n = prices.size();
        if (i == n) return 0; // No more transactions possible

        int profit = 0;

        if (buy) {
            // Option 1: Buy at the current price and move to the next day
            int buyProfit = -prices[i] + solve(prices, i + 1, false);
            // Option 2: Skip buying and move to the next day
            int skipProfit = solve(prices, i + 1, true);
            // Take the maximum of the two
            profit = max(buyProfit, skipProfit);
        } else {
            // Option 1: Sell at the current price and move to the next day
            int sellProfit = prices[i] + solve(prices, i + 1, true);
            // Option 2: Skip selling and move to the next day
            int skipProfit = solve(prices, i + 1, false);
            // Take the maximum of the two
            profit = max(sellProfit, skipProfit);
        }

        return profit;
    }
    int solveUsingMem(vector<int>& prices, int i,bool buy ,vector<vector<int>> &dp ){
              int n = prices.size();
        if (i == n) return 0; // No more transactions possible
        
        //step 3: check if the answer already exists or not 
         if(dp[i][buy]!=-1){
            return dp[i][buy];
         }
   
        int profit = 0;
        

        // step 2: answer mei dp use krao
        if (buy) {
            // Option 1: Buy at the current price and move to the next day
            int buyProfit = -prices[i] + solveUsingMem(prices, i + 1, false,dp);
            // Option 2: Skip buying and move to the next day
            int skipProfit = solveUsingMem(prices, i + 1, true,dp);
            // Take the maximum of the two
            profit = max(buyProfit, skipProfit);
        } else {
            // Option 1: Sell at the current price and move to the next day
            int sellProfit = prices[i] + solveUsingMem(prices, i + 1, true,dp);
            // Option 2: Skip selling and move to the next day
            int skipProfit = solveUsingMem(prices, i + 1, false,dp);
            // Take the maximum of the two
            profit = max(sellProfit, skipProfit);
        }

        int ans = profit;
        dp[i][buy] = ans;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
         // 0 ---> index 
         // buy ----> variable
    //     return solve(prices, 0, true); // Start with buying allowed
       int n = prices.size();
      // step 1: create a dp array 
      // yaha index aur buy dono change ho rge hence 2D array
        vector<vector<int>>dp(n+1,vector<int>(2 , -1));
        int ans = solveUsingMem(prices,0,true,dp);
        return ans;

    }
};
