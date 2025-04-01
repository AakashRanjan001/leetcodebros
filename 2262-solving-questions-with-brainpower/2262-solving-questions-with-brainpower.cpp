// class Solution {
// public:
//     long long solve(int i ,vector<vector<int>>questions, vector<long long> &dp){
//          if(i>=questions.size())return 0;

//          if(dp[i]!=-1){
//              return dp[i];
//          }

//        long long include = questions[i][0] +  solve(i + questions[i][1] + 1,questions,dp);
//        long long exclude = 0 + solve(i+1,questions,dp);

//        return dp[i] =  max(include,exclude);
//     }
//     long long mostPoints(vector<vector<int>>& questions) {
        
//         // pick non pick ka question lag rh ahai 
//         int i=0;
//         vector<long long>dp(questions.size()+1,-1);
//         long long ans = solve(i,questions,dp);
//         return ans;
//     }
// };


class Solution {
public:
    long long solve(int idx,int n,vector<vector<int>>& questions,vector<long long>&dp){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long take=questions[idx][0]+solve(idx+questions[idx][1]+1,n,questions,dp);
        long long ntake=solve(idx+1,n,questions,dp);
        return dp[idx]=max(take,ntake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int idx=0;
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        return solve(idx,n,questions,dp);
    }
};