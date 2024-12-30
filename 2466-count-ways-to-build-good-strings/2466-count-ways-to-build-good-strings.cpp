#define MOD 1000000007
class Solution {
public:
    int solveUsingRec(int len,int zero,int one){
        //base case
        if(len == 0)return 1;
        if(len<0)return 0;

        long long sum = solveUsingRec(len-one,zero,one) + solveUsingRec(len-zero,zero ,one); 
        return sum;

    }
    int solveUsingMem(int len,int zero,int one , vector<int>&dp ){
         if(len == 0)return 1;
        if(len<0)return 0;

        if(dp[len]!=-1){
            return dp[len];
        }

         long long sum = (solveUsingMem(len-one,zero,one,dp) + solveUsingMem(len-zero,zero ,one,dp)); 
        return dp[len] = sum % MOD;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // int ans = 0;
        // for(int len = low;len<=high;len++){
        //     ans+=solveUsingRec(len,zero,one);
        // }
        // return ans % MOD;


        //Memoization 
        long long ans = 0;
        //as len is changing a 1 D Dp 
        vector<int>dp(high+1,-1);
        for(int len=low;len<=high;len++){
            ans+=solveUsingMem(len,zero,one,dp)%MOD;
        }
        return ans;
    }
};