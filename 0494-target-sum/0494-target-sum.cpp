class Solution {
public:
   int solve(vector<int>& nums, int target,int i){
     if(i == nums.size()){
         if(target == 0)return 1;
         return 0;
     }
 
     int way_1_plus = solve(nums,target - nums[i],i+1);//isme nums[i] ka sign plus assume kia hai 
     int way_2_minus = solve(nums,target + nums[i] , i+1);// isme mums[i] ka sign minus assume kiya hai 

     return way_1_plus + way_2_minus;
   }

   int solveUsingMem(vector<int>& nums, int target,int i , map<pair<int,int>,int> &dp){
       if(i == nums.size()){
         if(target == 0)return 1;
         return 0;
     }
     //step 3: base cae ke just baad wala condition 
     if(dp.find({i,target})!=dp.end()){
          return dp[{i,target}];
     }

 // step 2: answer mei dp array ka use karn a
     int way_1_plus = solveUsingMem(nums,target - nums[i],i+1,dp);//isme nums[i] ka sign plus assume kia hai 
     int way_2_minus = solveUsingMem(nums,target + nums[i] , i+1,dp);// isme mums[i] ka sign minus assume kiya hai 

     return dp[{i,target}] =  way_1_plus + way_2_minus;     

   }

   int solveUsingTab(vector<int>& nums, int target){
      //step 1: create the dp map 
       map<pair<int,int>,int>dp;
       //base case ka condition 
       dp[{nums.size(),0}] = 1;//jab i---> nums.size() && target == 0 retunr 1 

     
     //for target range kya hoga , it can go utmost negative when all signs are '-'
       int total =0;
       for(auto i:nums){
          total+=i;
       }

      
       //step 3: iterative apprpach 
       // in mem -> i = 0-->nums.size() && target = target ---> -ve val
       //target in BU -> -total ---> +total
       for(int i=nums.size()-1;i>=0;--i){
          for(int sum = -total ;sum<=total;++sum){
                
        int way_1_plus = dp.find({i+1,sum - nums[i]})!=dp.end() ? dp[{i+1,sum - nums[i]}] : 0;
        int way_2_minus = dp.find({i+1,sum + nums[i]})!=dp.end() ? dp[{i+1 ,sum + nums[i]}] : 0;
          dp[{i,sum}] =  way_1_plus + way_2_minus;
          }
          
       }

    return dp[{0,target}];

   }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int ans = solve(nums,target,0);
        // return ans;

// step 1: create a dp map 
        // map<pair<int,int>,int>dp; //{i,target -> no.of ways}
        // int ans = solveUsingMem(nums,target,0,dp);
        // return ans;  

        // bottom up 
        int ans = solveUsingTab(nums,target);
        return ans;  
    }
};