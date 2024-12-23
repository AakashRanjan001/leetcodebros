class Solution {
public:
   int solveUsingRec(vector<int>& prices, int i, int buy , int fee) {
        // Base case
        int n = prices.size();
        if (i == n) return 0; // No more transactions possible

        int profit = 0;

        if (buy) {
  
            int buyProfit = -prices[i] + solveUsingRec(prices, i + 1, 0,fee);
            int skipProfit = solveUsingRec(prices, i + 1, 1,fee);
            profit = max(buyProfit, skipProfit);
        } else {
         // jab mai sell kar dunga tab ek transaction kam hogi aur fee deduct hogi 
            int sellProfit = prices[i] + solveUsingRec(prices, i + 1, 1,fee) - fee;
            int skipProfit = solveUsingRec(prices, i + 1, 0,fee);
            profit = max(sellProfit, skipProfit);
        }

        return profit;
    }

    int solveUsingMem(vector<int>& prices, int i,int buy ,int fee,vector<vector<int>> &dp ){
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
            int buyProfit = -prices[i] + solveUsingMem(prices, i + 1, 0,fee,dp);
            // Option 2: Skip buying and move to the next day
            int skipProfit = solveUsingMem(prices, i + 1, 1,fee,dp);
            // Take the maximum of the two
            profit = max(buyProfit, skipProfit);
        } else {
            // Option 1: Sell at the current price and move to the next day
            int sellProfit = prices[i] + solveUsingMem(prices, i + 1, 1,fee,dp) - fee;
            // Option 2: Skip selling and move to the next day
            int skipProfit = solveUsingMem(prices, i + 1, 0,fee,dp);
            // Take the maximum of the two
            profit = max(sellProfit, skipProfit);
        }

        int ans = profit;
        dp[i][buy] = ans;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // use BS - 2
        // int ans = solveUsingRec(prices,0,1,fee);
        // return ans;

int n = prices.size();
    //       step 1: create a dp array 
    //   yaha index aur buy dono change ho rge hence 2D array
        vector<vector<int>>dp(n+1,vector<int>(2 , -1));
        int ans = solveUsingMem(prices,0,1,fee, dp);
        return ans;
    }

};