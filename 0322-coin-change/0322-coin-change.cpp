class Solution {
public: 
    int solve(vector<int> &coins, int amount){
         // base case 
         if(amount == 0)return 0;
         if(amount<0)return INT_MAX;
         int val  = INT_MAX;
         for(int i=0;i<coins.size();i++){
             int subprob = solve(coins, amount-coins[i]);
             if(subprob!=INT_MAX){
                 val = min(val, subprob+1);
             }
         }
         return val == INT_MAX ? -1 : val;

    }
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size(); // similar to minimising coins in CSES
         int ans = solve(coins ,amount);
         if(ans == INT_MAX)return -1;
         return ans;
    }
};