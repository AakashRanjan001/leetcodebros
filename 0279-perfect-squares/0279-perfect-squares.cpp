class Solution {
public:
    int numSQHelper(int n){
          // base case 
        if(n==0)return 1; //means jab n== 0 hua tab sum ban chuka hai that is 
        // equal to n 
        int i=1;
        int ans = INT_MAX;
        int end = sqrt(n);
        while(i<=end){
        int perfectSquare = i*i;
          int numberOfPerfectSQ  = 1 + numSQHelper(n-perfectSquare);
          ans = min(ans , numberOfPerfectSQ);
          i++;
        }
        // but yaha ek aur extra function call aa rha hai thats why at the end we did a -1
        return ans;
    }
    int numSQHelperMem(int n ,vector<int>&dp ){
      if(n==0)return 1; //means jab n== 0 hua tab sum ban chuka hai that is 
        // equal to n 

      //step 3: check if the answer already existd
      if(dp[n]!=-1){
        return dp[n];
      }

        // step 2: ans wale mei dp ka daalo 
        int i=1;
        int ans = INT_MAX;
        int end = sqrt(n);
        while(i<=end){
        int perfectSquare = i*i;
          int numberOfPerfectSQ  = 1 + numSQHelperMem(n-perfectSquare ,dp);
          ans = min(ans , numberOfPerfectSQ);
          i++;
        }
        dp[n] = ans;
        // but yaha ek aur extra function call aa rha hai thats why at the end we did a -1
        return dp[n];
    }
    int numSquares(int n) {
        // INitial thought 
        // // base case 
        // if(n==0)return 1; //means jab n== 0 hua tab sum ban chuka hai that is 
        // // equal to n 
        // int i=1;
        // int perfectSquare = i*i;

        // int ans = 1 + numSquares(n-perfectSquare);
        // // but yaha ek aur extra function call aa rha hai 
        // return ans;

        // int ans = numSQHelper(n) -1;
        // return ans;

        //1d dp 
        // step1 : create a  dp array 
        vector<int>dp(n+1 , -1);
        int ans = numSQHelperMem(n , dp) -1;
        return ans;

    }
};