class Solution {
public: 
    int solve(vector<int>& nums , vector<bool>used , int p , int formed){
         // base case 
         if(formed == p)return 0;

         int n = nums.size();
         int res = INT_MAX;

         for(int i=0;i<n-1;i++){
             if(used[i])continue;
             for(int j=i+1;j<n;j++){
                 if(used[j])continue;

                 used[i] = used[j] = true;
                 int diff = abs(nums[i] - nums[j]);
                 int next = solve(nums,used,p,formed+1);
                 res = min(res , max(diff,next));

                //  int max_diff = max(diff,next);
                //  res = min(res , max_diff);

                used[j] = false;
             }
         }
         return res;
    }
    int minimizeMax(vector<int>& nums, int p) {
  
       vector<bool>used(nums.size(),false);
       int ans = solve(nums,used,p,0);
       return ans;

    }
};