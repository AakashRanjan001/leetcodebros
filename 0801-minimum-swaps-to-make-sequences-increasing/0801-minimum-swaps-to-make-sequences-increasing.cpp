class Solution {
public:

    int solveUsingRec(vector<int>& nums1, vector<int>& nums2,int i,int p1,int p2){
        //base case
         if(i==nums1.size())return 0;
         int swap = INT_MAX,not_swap = INT_MAX;
          ////swap condition 
          if(p1<nums2[i] && p2<nums1[i]){
             swap = 1 + solveUsingRec(nums1,nums2,i+1,nums2[i],nums1[i]);
          }

          //not swap cond
          if(p1<nums1[i] && p2<nums2[i]){
             not_swap = solveUsingRec(nums1,nums2,i+1,nums1[i],nums2[i]);
          }
          int ans = min(swap,not_swap);
          return ans;
    }
    int solveUsingMem(vector<int>& nums1, vector<int>& nums2,int i,int p1,int p2,vector<vector<int>> &dp,int isSwap ){
            if(i==nums1.size())return 0;
         
         //step 3: check if the answr laready exists 
          if(dp[i][isSwap]!=-1){
             return dp[i][isSwap];
          }

         // step2 
         int swap = INT_MAX,not_swap = INT_MAX;
          ////swap condition 
          if(p1<nums2[i] && p2<nums1[i]){ // 1 represents swap done 
             swap = 1 + solveUsingMem(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
          }

          //not swap cond
          if(p1<nums1[i] && p2<nums2[i]){ // 0 reprsesnts swap not done 
             not_swap = solveUsingMem(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
          }
          dp[i][isSwap] = min(swap,not_swap);
          return dp[i][isSwap];
    }
    int solveUsingTab(vector<int>& nums1, vector<int>& nums2){
         //step 1: create the dp array 
          vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
          //step 2: check the base case please write some answerds prerequisite 
        //   no need

        //step 3: for loops  // look in the notebook // j== 1->swap and j=0->non_swap case 
          for(int i= nums1.size()-1;i>=1;i--){
             for(int j= 1;j>=0;--j){
                   int p1 = nums1[i-1];
                   int p2 = nums2[i-1];
                         int swap = INT_MAX,not_swap = INT_MAX;
          ////swap condition 
                if(p1<nums2[i] && p2<nums1[i]){ // 1 represents swap done 
                  swap = 1 + dp[i+1][1];
                }

          //not swap cond
                 if(p1<nums1[i] && p2<nums2[i]){ // 0 reprsesnts swap not done 
                   not_swap = dp[i+1][0];
                 }
                dp[i][j] = min(swap,not_swap);
             

             }
          }
              return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        // int ans = solveUsingRec(nums1,nums2,0, -1,-1);
        // return ans;

        
        // i is changing from => 0----> nums.size() => n+1 ;
        // taking an isSwap condition that is swap/notswap , that is 2
        //step 1
        // vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
        //isSwap = 0 currently no swap is taken right now 
        // int ans = solveUsingMem(nums1,nums2,0,-1,-1,dp,0 );
        // return ans;

 

 // TABULATION
     nums1.insert(nums1.begin(),-1);
     nums2.insert(nums2.begin(),-1);
     int ans = solveUsingTab(nums1,nums2);
     return ans;


    }
};