class Solution {
public:
    int solveUsingRec(vector<int>& sat, int i,int time){
        //base case
        if(i == sat.size())return 0;

        //including the current dish
        int includelikeTimeCoeff = time*sat[i] + solveUsingRec(sat,i+1,time+1);
        int excludelikeTimeCoeff = 0 + solveUsingRec(sat,i+1,time);//jab tak include nhi karemge tab tak time aage nhi badhega 
        return max(includelikeTimeCoeff,excludelikeTimeCoeff);
    }
    int solveUsingMem(vector<int>& sat,int i,int time, vector<vector<int>>&dp){
             if(i == sat.size())return 0;

             if(dp[i][time]!= -1){
                return dp[i][time];
             }

        //including the current dish
        int includelikeTimeCoeff = time*sat[i] + solveUsingMem(sat,i+1,time+1,dp);
        int excludelikeTimeCoeff = 0 + solveUsingMem(sat,i+1,time,dp);//jab tak include nhi karemge tab tak time aage nhi badhega 
        int ans = max(includelikeTimeCoeff,excludelikeTimeCoeff);
            dp[i][time] = ans;
            return dp[i][time];
    }
    int solveUsingtab(vector<int>& satisfaction){
          int n = satisfaction.size();
         //step 1:creation of a 2d vector
         vector<vector<int>>dp(n+1,vector<int>(n+2,0));
         
         //step 2: base case dkeho phir batao

         //step 3: //time ---> 1--->n tak jaaa rha tah 
          for(int i = n-1;i>=0;i--){
            for(int time = n;time>=1;time--){
            if(i+1>=0){
        int includelikeTimeCoeff = time*satisfaction[i] + dp[i+1][time+1];
        int excludelikeTimeCoeff = 0 + dp[i+1][time];//jab tak include nhi karemge tab tak time aage nhi badhega 
        int ans = max(includelikeTimeCoeff,excludelikeTimeCoeff);
            dp[i][time] = ans;
            }
            }
          }
            return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // int ans = solveUsingRec(satisfaction,0,1);
        // return ans;
        int n = satisfaction.size();
        // as time and index both are changing hence the use of 2d dp
        //time--> maanlo saare dishes baana cahhao isi kaaran n is the size
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveUsingMem(satisfaction,0,1,dp);
        // return ans;


        int ans = solveUsingtab(satisfaction);
        return ans;
    }
};