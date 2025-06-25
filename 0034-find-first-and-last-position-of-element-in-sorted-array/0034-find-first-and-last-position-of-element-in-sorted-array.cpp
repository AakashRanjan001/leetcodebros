class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         
        //  int first = -1;
        //  int last = -1;

        //  // in O(N) solution
        //  for(int i=0;i<nums.size();i++){
        //     if(nums[i] == target){
        //          if(first == -1)first = i;
        //          last = i;
        //     }
        //  }
        //    return {first,last};

        // USING LOWER BOUND AND UPPPER BOUND in ){log n};
        int n = nums.size();
         auto lower = lower_bound(nums.begin(),nums.end(),target);
         auto upper = upper_bound(nums.begin(),nums.end(),target);

         if(lower == nums.end() || *lower!=target){
             return {-1,-1};
         }
         int start = lower - nums.begin();
         int end = upper - nums.begin() -1;
         return {start,end};
          
    }
};