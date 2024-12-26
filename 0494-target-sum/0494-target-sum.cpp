class Solution {
public:
   int solve(vector<int>& nums, int target,int i){
     if(i == nums.size()){
         if(target == 0)return 1;
         return 0;
     }

     int way_1 = solve(nums,target - nums[i],i+1);
     int way_2 = solve(nums,target +nums[i] , i+1);

     return way_1 + way_2;
   }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(nums,target,0);
        return ans;
    }
};