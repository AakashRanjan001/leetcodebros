class Solution {
public:
    // bool solveUsingRec(vector<int>&nums , int index , int target){
    //      // base case
    //      int n = nums.size();
    //      if(index>=n){
    //          return 0;
    //      }
    //      if(target<0)return 0;
    //      if(target == 0)return 1; //found the subset sum

    //      bool include = solveUsingRec(nums,index+1 , target -nums[index]);
    //      bool exclude = solveUsingRec(nums,index+1 , target);

    //      return (include || exclude);
    // }
    bool solveUsingMem(vector<int>& nums , int index , int target , vector<vector<int>>&dp){
          int n = nums.size();
         if(index>=n){
             return 0;
         }
         if(target<0)return 0;
         if(target == 0)return 1; //found the subset sum

         //step3: check if answer already exist 
         if(dp[index][target]!= -1){
             return dp[index][target];
         }

//step 2: change ans to dp array
         bool include = solveUsingMem(nums,index+1 , target -nums[index] , dp);
         bool exclude = solveUsingMem(nums,index+1 , target,dp);

         dp[index][target] = (include || exclude);
         return dp[index][target];
    }

    bool solveUsingTab(vector<int>& nums, int target){
        int n = nums.size();
         //step 1: create a dp array // all columns initialsed with 0
         vector<vector<int>>dp(n +1,vector<int>(target+1 , 0));

         //step 2 : base case of top down dekho
         //return 0 ke liye pehle hi upar inintalsed kar diya hai
         for(int i=0;i<nums.size();i++){
             dp[i][0] = 1;  // 0th column ke liye all are 1
         }

         //step 3: iterative method // in top down : index ----> 0->n-1
                                                // : target ----> target ->0
           for(int index=n-1;index>=0;index--){
               for(int t=1;t<=target;t++){ // jaha jaha target ->t   
                 bool include =0;                      //laha jaha n -> i
                if(t-nums[index]>=0){                       
                   include = dp[index+1][t -nums[index]];
                }
                  bool exclude =dp[index+1][t];

                 dp[index][t] = (include || exclude);
                  
               }
           }                                     
         return dp[0][target];        
    }
   
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum =0;
        for(int i=0;i<n;i++){
             total_sum+=nums[i];
        }
        //(total_sum & 1)// another alternative YAHA MAI GALTI KIYA THA
        if(total_sum%2!=0)return 0;// agr total sum hamara odd hai toh partition nhi kar sakte hai

        int target = total_sum/2;
        // int index =0; // index defines ki apon kaunse index ke upar khade hai 
        // bool ans = solveUsingRec(nums,index,target);
        // return ans;


//MEMOIZATION
      // step 1: create a dp array as yaha 2 parameters are changing index,target
       // hence we need to create a 2d dp
      //yaha last index hamara target hoga  
        
        int index =0;
        // index varies from 0->n-1 ---> n rows
         //target varies from target->0 ----> target + 1 cols and initialised with -1
        // vector<vector<int>>dp(n,vector<int>(target+1 , -1));
        // bool ans = solveUsingMem(nums,index , target , dp);

        // return ans;

       bool ans = solveUsingTab(nums,target);
       return ans;
        
    }
};