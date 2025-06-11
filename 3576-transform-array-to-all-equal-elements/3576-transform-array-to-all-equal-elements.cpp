class Solution {
public:
    bool solve(vector<int> nums ,int k , int target){
        int n = nums.size();
         int cnt = 0;
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=target){
             cnt++;
             nums[i] = -nums[i];
             nums[i+1] = -nums[i+1];
          
            }
            if(cnt>k)return false;
         }

        //  if(nums[nums.size()-1] == target)return true;
         return nums[n -1] == target;
         
    }
    bool canMakeEqual(vector<int>& nums, int k) {
         
         // odd number of minusones pakka false hai 
        //  int cnt_minus1 =0;
        //  int cnt1=0;
        //  for(int i=0;i<nums.size();i++){
        //       if(nums[i] == -1)cnt_minus1++;
        //       else cnt1++;
        //  }
        //  if(cnt_minus1%2!=0)return false;

         return solve(nums,k,1)  || solve(nums,k,-1);

        
    }
};