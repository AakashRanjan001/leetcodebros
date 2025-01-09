class Solution {
public:
    int solveUsingrec(vector<int>& s,int i){
        //base case 
        if(i == s.size())return 0;
        int ans = INT_MIN; // abb mujhe Alice-Bob ko maximise karna hai
        int total =0;
        for(int X=1;X<=3;X++){
             if(i+X-1 >= s.size()) break;
             total+=s[i+X-1]; // agar ek stone pick kiya 
             // i+X-1 index tak sab stones pick kar liya hoga abb aage ke liye recursice call
             ans = max(ans , total - solveUsingrec(s,i+X));

        }
        return ans;
    }
    int solveUsingMem(vector<int>& s,int i,vector<int>& dp){
         if(i == s.size())return 0;
         if(dp[i]!= -1)return dp[i];
        int ans = INT_MIN; // abb mujhe Alice-Bob ko maximise karna hai
        int total =0;
        for(int X=1;X<=3;X++){
             if(i+X-1 >= s.size()) break;
             total+=s[i+X-1]; // agar ek stone pick kiya 
             // i+X-1 index tak sab stones pick kar liya hoga abb aage ke liye recursice call
             ans = max(ans , total - solveUsingMem(s,i+X,dp));

        }
        return dp[i]= ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        //starting from the zero index 
        // int ans = solveUsingrec(stoneValue,0); 
        // we are calculating Alice -Bob
        vector<int>dp(stoneValue.size()+1,-1);
        int ans = solveUsingMem(stoneValue,0,dp);
        if(ans>0)return "Alice";
        if(ans<0)return "Bob";
        else return "Tie";
    }
};