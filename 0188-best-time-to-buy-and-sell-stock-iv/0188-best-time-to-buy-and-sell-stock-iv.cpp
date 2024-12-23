class Solution {
public:
    int solveUsingRec(vector<int>& prices, int i , int buy , int limit){
        int n = prices.size();
        // base case
        if(i>= n)return 0;
        if(limit == 0)return 0;
        int profit =INT_MIN;
        if(buy){
               int buyitProfit = -prices[i] + solveUsingRec(prices,i+1,0,limit);
               int skipProfit = 0 + solveUsingRec(prices,i+1,1,limit);
               profit = max(buyitProfit, skipProfit);
        }
        else{
              int sellitProfit = prices[i] + solveUsingRec(prices,i+1,1,limit-1);
              // 1 transactio --> {buy ,sell};
              // abb jab ki maine sell kar diya hai matlab ek transaction ho chuka hai hence limit--
              int skipProfit = 0 + solveUsingRec(prices,i+1,0,limit);
              profit = max(sellitProfit , skipProfit);
        }
        int ans = profit;
        return ans;
        
    }
       int solveUsingMem(vector<int>& prices, int i , int buy , int limit,  vector<vector<vector<int>>>& dp){
            int n = prices.size();
        // base case
        if(i>= n)return 0;
        if(limit == 0)return 0;

      // step 3; Check if naswer already exists or nor 
       if(dp[i][buy][limit]!=-1){
          return dp[i][buy][limit];
       }

        int profit =INT_MIN;
        if(buy){
               int buyitProfit = -prices[i] + solveUsingMem(prices,i+1,0,limit,dp);
               int skipProfit = 0 + solveUsingMem(prices,i+1,1,limit,dp);
               profit = max(buyitProfit, skipProfit);
        }
        else{
              int sellitProfit = prices[i] + solveUsingMem(prices,i+1,1,limit-1,dp);
              // 1 transactio --> {buy ,sell};
              // abb jab ki maine sell kar diya hai matlab ek transaction ho chuka hai hence limit--
              int skipProfit = 0 + solveUsingMem(prices,i+1,0,limit,dp);
              profit = max(sellitProfit , skipProfit);
        }
        // step2 : answer ko dp array mei daalo
        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];

    }
    int maxProfit(int k, vector<int>& prices) {
        //  int ans = solveUsingRec(prices, 0,1,k);
        //  return ans;
          int n = prices.size();
           vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, -1)));
  
          int ans = solveUsingMem(prices,0,1,k,dp);
          return ans;

    }
};