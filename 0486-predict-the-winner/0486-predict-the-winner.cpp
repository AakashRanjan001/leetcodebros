class Solution {
public:
     int solveUsingRec(vector<int>& nums,int start , int end){
        // base case
        if(start == end)return nums[start];
        
        //diff-> p1 - p2
        //p1 --> nums[start] pick kiya , bakki recursion p2-->ka laayega 
        int diffbystart = nums[start] -solveUsingRec(nums, start+1,end);
        int diffbyend = nums[end] - solveUsingRec(nums,start,end -1);

        //agar meko player 1 ko jeetnaa hai toh meko diiff maximise karna hoga 
        int ans = max(diffbystart,diffbyend);
        return ans;
     }

     int solveUsingMem(vector<int>& nums,int start, int end,  vector<vector<int>>&dp){
        int n = nums.size();
         if(start == end)return nums[start];
        

        if(dp[start][end]!=-1){
             return dp[start][end];
        }
        //diff-> p1 - p2
        //p1 --> nums[start] pick kiya , bakki recursion p2-->ka laayega 
        int diffbystart = nums[start] -solveUsingMem(nums, start+1,end,dp);
        int diffbyend = nums[end] - solveUsingMem(nums,start,end -1,dp);

        //agar meko player 1 ko jeetnaa hai toh meko diiff maximise karna hoga 
        int ans = max(diffbystart,diffbyend);
        dp[start][end] = ans;
        return dp[start][end];
        

     }
    bool predictTheWinner(vector<int>& nums) {
        //start = 0 , end = nums.size()-1
        // int ans = solveUsingRec(nums,0,nums.size()-1);
        // return ans>=0;

         int n = nums.size();
        //memoiaxztion
        //start index --> 0 -> end;//end can be till n
        //end index ---> num.size()-1->start // start can be till 0 index
        //step 1: Create a dp array 2d dp
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveUsingMem(nums,0,n-1,dp);
        return ans>=0;

    }
};