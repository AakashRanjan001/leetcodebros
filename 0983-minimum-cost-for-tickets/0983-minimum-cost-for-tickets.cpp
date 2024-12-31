class Solution {
public:
    int solveUsingRec(int currindex , vector<int>& days, vector<int>& costs,int n){
         if(currindex == n)return 0;

       

         int oneDay = costs[0] + solveUsingRec(currindex+1,days,costs,n);

         int i = currindex;
        while (i < n && days[i] < days[currindex] + 7) {
            i++;
        }
         int sevenDay = costs[1] + solveUsingRec(i,days,costs,n);

         
        i = currindex;
        while (i < n && days[i] < days[currindex] + 30) {
            i++;
        }
         int thirtyDay = costs[2] + solveUsingRec(i,days,costs,n);

         int ans = min({oneDay,sevenDay,thirtyDay});
         return ans;
    }


    int solveUsingMem(int currindex,vector<int>& days, vector<int>& costs,int n, vector<int>&dp){
            if(currindex == n)return 0;

               if(dp[currindex]!=-1){
             return dp[currindex];
         }

         int oneDay = costs[0] + solveUsingMem(currindex+1,days,costs,n,dp);

         int i = currindex;
        while (i < n && days[i] < days[currindex] + 7) {
            i++;
        }
         int sevenDay = costs[1] + solveUsingMem(i,days,costs,n,dp);

         
        i = currindex;
        while (i < n && days[i] < days[currindex] + 30) {
            i++;
        }
         int thirtyDay = costs[2] + solveUsingMem(i,days,costs,n,dp);

         int ans = min({oneDay,sevenDay,thirtyDay});
         return dp[currindex] =  ans;


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // int ans = solveUsingRec(0,days,costs,n);
        // return ans;

        //Memoization //index i schanging from 0 -->n-1
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(0,days,costs,n,dp);
        return ans;
    }
};