class Solution {
public:
const int mod=1e9+7;
   int dp[100007][3][4];
   int fun(int ind,int val,int l){
          if(val<0) return 0;
       if(l<0) return 0;
       if(ind==0) return 1;
    
     if(dp[ind][val][l]!=-1) return dp[ind][val][l];

       int ans=0;
       
       ans=(ans+fun(ind-1,val,2))%mod;
       
        ans=(ans+fun(ind-1,val-1,2))%mod;
        
        ans=(ans+fun(ind-1,val,l-1))%mod;
       return  dp[ind][val][l]=ans;
   }
    
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n,1,2);
    }
};
